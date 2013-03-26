/*
Copyright © 2012-2013, Silent Circle, LLC.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Any redistribution, use, or modification is done solely for personal 
      benefit and not for any commercial purpose or for monetary gain
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name Silent Circle nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL SILENT CIRCLE, LLC BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
//
//  STAudioView.h
//  SilentText
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class SCloudObject;

@protocol STAudioViewDelegate <NSObject>


#pragma mark -
#pragma mark Delegate methods
@optional

#pragma mark Data source methods
@required

- (void)didFinishRecordingAudioWithError:(NSError *)error scloud:(SCloudObject*) scloud ;


@end


@interface STAudioView : UIView <AVAudioPlayerDelegate, AVAudioRecorderDelegate>


@property (nonatomic, weak) IBOutlet UIButton* recordButton;
@property (nonatomic, weak) IBOutlet UIButton* pauseButton;
@property (nonatomic, weak) IBOutlet UIButton* playButton;
@property (nonatomic, weak) IBOutlet UIButton* sendButton;
@property (nonatomic, weak) IBOutlet UIImageView* redLEDImageView;
@property (weak, nonatomic) IBOutlet UIImageView *blueLEDImageView;
@property (weak, nonatomic) IBOutlet UIButton *cancelButton;
@property (weak, nonatomic) IBOutlet UIImageView *controlbarImageView;


@property (assign) id<STAudioViewDelegate>       delegate;

- (void) unfurlOnView:(UIView*)view under:(UIView*)underview  atPoint:(CGPoint) point;

- (void) fadeOut;
- (BOOL) isVisible;
- (void) hide;

- (IBAction)recordAction:(id)sender;
- (IBAction)pauseAction:(id)sender;
- (IBAction)playAction:(id)sender;
- (IBAction)cancelAction:(id)sender;

- (IBAction)sendAction:(id)sender;
 

@end
