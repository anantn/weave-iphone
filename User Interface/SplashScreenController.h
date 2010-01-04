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
 Dan Walkowski <dan.walkowski@gmail.com>
 
 ***** END LICENSE BLOCK *****/

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "Animator.h"

@interface SplashScreenController : UIViewController {

  UIImageView* bigLogo;
  UIImageView* title1;
  UIImageView* title2;
  UIImageView* arrow;
  UIImageView* tabHelp;
  UIImageView* bmkHelp;
  UIImageView* srchHelp;
  
  CGRect bigLogoOrigFrame;
  CGRect title1OrigFrame;
  CGRect title2OrigFrame;
  CGPoint arrowPos, arrowHidden;
  
  CGPoint srchHelpPos, srchHelpHidden;
  CGPoint tabHelpPos, tabHelpHidden;
  CGPoint bmkHelpPos, bmkHelpHidden;

  Animator* animationController;
  
//  AVAudioPlayer *popPlayer;

}

@property (nonatomic, retain) IBOutlet UIImageView *bigLogo;
@property (nonatomic, retain) IBOutlet UIImageView *title1;
@property (nonatomic, retain) IBOutlet UIImageView *title2;
@property (nonatomic, retain) IBOutlet UIImageView *arrow;

@property (nonatomic, retain) IBOutlet UIImageView *tabHelp;
@property (nonatomic, retain) IBOutlet UIImageView *bmkHelp;
@property (nonatomic, retain) IBOutlet UIImageView *srchHelp;
//@property (nonatomic, retain) AVAudioPlayer *popPlayer;

@end
