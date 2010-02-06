/***** BEGIN LICENSE BLOCK *****
 Version: MPL 1.1/GPL 2.0/LGPL 2.1
 
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

 Alternatively, the contents of this file may be used under the terms of either
 the GNU General Public License Version 2 or later (the "GPL"), or the GNU
 Lesser General Public License Version 2.1 or later (the "LGPL"), in which case
 the provisions of the GPL or the LGPL are applicable instead of those above.
 If you wish to allow use of your version of this file only under the terms of
 either the GPL or the LGPL, and not to allow others to use your version of
 this file under the terms of the MPL, indicate your decision by deleting the
 provisions above and replace them with the notice and other provisions
 required by the GPL or the LGPL. If you do not delete the provisions above, a
 recipient may use your version of this file under the terms of any one of the
 MPL, the GPL or the LGPL.
 
 ***** END LICENSE BLOCK *****/

#import <UIKit/UIKit.h>

#import "Store.h";

#import "SearchResultsController.h"
#import "TabBrowserController.h"
#import "BookmarkBrowserController.h"

@interface WeaveAppDelegate : NSObject <UIApplicationDelegate> 
{
  UIWindow*                 window;
  UIViewController*         rootController;
  UIView*                   contentView;
  UIView*                   headerView;
  UIActivityIndicatorView*  spinner;
  UILabel*                  spinMessage;
  UIButton*                 syncButton;
  UILabel*                  userNameDisplay;
  UITabBarController*       browserPage;
  SearchResultsController*  searchResults;
  TabBrowserController*     tabBrowser;
  BookmarkBrowserController*bookmarkBrowser;
}

- (IBAction) resync:(id)sender;

- (void) startSpinner;
- (void) stopSpinner;
- (void) refreshViews;
- (void) signIn;
- (void) signOut;

//ugh.  this is to prevent the views from being updated and the animation from starting until after the login page
// goes away, if it was a first time user
- (void) installTabBar;


@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UIViewController *rootController;

@property (nonatomic, retain) IBOutlet UIView* contentView;
@property (nonatomic, retain) IBOutlet UIView* headerView;
@property (nonatomic, retain) IBOutlet UIActivityIndicatorView* spinner;
@property (nonatomic, retain) IBOutlet UILabel* spinMessage;
@property (nonatomic, retain) IBOutlet UIButton* syncButton;
@property (nonatomic, retain) IBOutlet UILabel* userNameDisplay;
@property (nonatomic, retain) IBOutlet UITabBarController *browserPage;
@property (nonatomic, retain) IBOutlet SearchResultsController *searchResults;
@property (nonatomic, retain) IBOutlet TabBrowserController *tabBrowser;
@property (nonatomic, retain) IBOutlet BookmarkBrowserController *bookmarkBrowser;


@end
