/***** BEGIN LICENSE BLOCK *****
 Version: MPL 1.1
 
 The contents of this file are subject to the Mozilla Public License Version 
 1.1 (the "License"); you may not use this file except in compliance with 
 the License. You may obtain a copy of the License at 
 http://www.mozilla.org/MPL/
 
 Software distributed under the License is distributed on an "AS IS" basis,
 WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 for the specific language governing rights and limitations under the
 License.
 
 The Original Code is weave-iphone.
 
 The Initial Developer of the Original Code is Mozilla Labs.
 Portions created by the Initial Developer are Copyright (C) 2009
 the Initial Developer. All Rights Reserved.
 
 Contributor(s):
	Anant Narayanan <anant@kix.in>
 
 ***** END LICENSE BLOCK *****/

#import "ListController.h"
#import "WeaveAppDelegate.h"
#import "TabViewController.h"
#import "Service.h"
#import "Utility.h"

@implementation ListController

@synthesize tView, tabController;

- (void)viewDidLoad {
    [super viewDidLoad];
	app = (WeaveAppDelegate *)[[UIApplication sharedApplication] delegate];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {    
	return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	if (tabController.selectedIndex == 2)
		return @"Bookmarks";
	else if (tabController.selectedIndex == 1)
		return @"Tabs";
	else
		return @"History";
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if (tabController.selectedIndex == 2)
		return [[[app service] getBookmarks] count];
	else if (tabController.selectedIndex == 1)
		return [[[app service] getTabs] count];
	else
		return ([[[app service] getHistory] count] > 20 ? 20 : [[[app service] getHistory] count]);
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	const NSInteger TITLE_TAG = 1001;
	const NSInteger URI_TAG = 1002;
	
	UILabel *title;
	UILabel *uri;
	
	static NSString *CellIdentifier = @"Cell";
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
	
	if (cell == nil) {
		cell = [[[UITableViewCell alloc] initWithFrame:CGRectZero reuseIdentifier:CellIdentifier] autorelease];
		title = [[[UILabel alloc] initWithFrame:CGRectMake(
					cell.indentationWidth + 24,
					tableView.rowHeight - 40,
					tableView.bounds.size.width - cell.indentationWidth - 34,
					20)] autorelease];
		[cell.contentView addSubview:title];
		title.tag = TITLE_TAG;
		title.font = [UIFont systemFontOfSize:[UIFont labelFontSize] + 1];
		
		uri = [[[UILabel alloc] initWithFrame:CGRectMake(
            cell.indentationWidth + 24,
			tableView.rowHeight - 20,
			tableView.bounds.size.width - cell.indentationWidth - 34,
			18)] autorelease];
		[cell.contentView addSubview:uri];
		uri.tag = URI_TAG;
		uri.font = [UIFont systemFontOfSize:[UIFont labelFontSize] - 3];
		uri.textColor = [UIColor colorWithRed:0.34 green:0.50 blue:0.77 alpha:1.0];
	} else {
		title = (UILabel *)[cell viewWithTag:TITLE_TAG];
		uri = (UILabel *)[cell viewWithTag:URI_TAG];
	}
	
	cell.image = nil;
	cell.accessoryView = nil;

	NSArray *obj;
	if (tabController.selectedIndex == 2) {
		obj = [[[app service] getBookmarks] objectAtIndex:indexPath.row];
		title.text = [obj objectAtIndex:0];
		uri.text = [obj objectAtIndex:1];
	} else if (tabController.selectedIndex == 1) {
		obj = [[[app service] getTabs] objectAtIndex:indexPath.row];
		title.text = [obj objectAtIndex:0];
		uri.text = [obj objectAtIndex:1];
	} else {
		obj = [[[app service] getHistory] objectAtIndex:indexPath.row];
		title.text = [obj objectAtIndex:0];
		uri.text = [obj objectAtIndex:1];
	}

	cell.image = [UIImage imageWithData:[[[NSData alloc] initWithBase64EncodedString:[obj objectAtIndex:2]] autorelease]];
	
	return cell;
}

- (void)tableView:(UITableView *)tv didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	if (tabController.selectedIndex == 2) {
		[app setUri:[[[[app service] getBookmarks] objectAtIndex:indexPath.row] objectAtIndex:0]];
	} else if (tabController.selectedIndex == 1) {
		[app setUri:[[[[app service] getTabs] objectAtIndex:indexPath.row] objectAtIndex:0]];
	} else {
		[app setUri:[[[[app service] getHistory] objectAtIndex:indexPath.row] objectAtIndex:0]];
	}
	[app switchMainToWeb];
}

/*
// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}
*/

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}


@end
