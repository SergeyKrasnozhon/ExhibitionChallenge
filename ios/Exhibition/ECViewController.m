//
//  ECViewController.m
//  Exhibition
//
//  Created by Maarten Billemont on 2017-08-13.
//  Copyright © 2017 Maarten Billemont. All rights reserved.
//

#import "ECViewController.h"
#import "PearlUIUtils.h"

@interface ECViewController()

@end

@implementation ECViewController

- (void)loadView {

    [super loadView];

    // Frames
    UIImageView *frameBottomView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"frame_bottom"]];
    [self.view addSubview:frameBottomView];
    [frameBottomView setFrameFrom:@"-|>[ ]-|-"];
}

@end
