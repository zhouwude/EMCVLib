//
//  EMCVImage.h
//  EMCVLib
//
//  Created by 郑宇琦 on 2017/4/10.
//  Copyright © 2017年 郑宇琦. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import "EMCVSplitedImage.h"

@class EMCVSplitedImage;

#ifdef __cplusplus
#include "opencv.h"
using namespace cv;
#endif

@interface EMCVImage : NSObject

#ifdef __cplusplus
{
@public
    Mat _mat;
    MatND _hist;
}
- (instancetype)initWithMat:(Mat)mat;
- (instancetype)initWithMat:(Mat)mat cvtColor:(int)color;
- (instancetype)initWithNoCopyMat:(Mat)mat;
#endif

@property (nonatomic, readonly) NSUInteger channalCount;

- (instancetype)initWithPath:(NSString *)path;
- (instancetype)initWithCVImage:(EMCVImage *)img;
- (instancetype)initWithCVImage:(EMCVImage *)img cvtColor:(int)color;
- (instancetype)initWithSplitedImage:(EMCVSplitedImage *)splitedImage;

- (EMCVImage *)makeACopy;

- (EMCVSplitedImage *)splitImage;
- (void)drawARectWithCenter:(NSPoint)center size:(NSSize)size rgbColor:(int *)rgb thickness:(int)thickness;
- (void)drawARect:(NSRect)rect rgbColor:(int *)rgb thickness:(int)thickness;
- (void)cvtColor:(int)code;
- (void)blurWithSize:(NSSize)size;
- (void)medianBlurWithSize:(int)size;
- (void)bilateralFilterWithDelta:(int)d andSigmaColor:(double)sc andSigmaSpace:(double)sp;
- (void)gaussianBlurWithSize:(NSSize)size;
- (NSImage *)toImage;

- (void)calHistWithSize:(int)size range:(float *)range;
- (void)calHistWithDims:(int)dims size:(int)size range:(float *)range;
- (void)calHistWithDims:(int)dims sizes:(int *)sizes ranges:(float **)ranges;
- (void)normalizeHistWithValue:(double)value;

@end

