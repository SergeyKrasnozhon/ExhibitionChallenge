/**
 * Copyright Maarten Billemont (http://www.lhunath.com, lhunath@lyndir.com)
 *
 * See the enclosed file LICENSE for license information (LGPLv3). If you did
 * not receive this file, see http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * @author   Maarten Billemont <lhunath@lyndir.com>
 * @license  http://www.gnu.org/licenses/lgpl-3.0.txt
 */

//
//  PearlUIUtils.h
//  Pearl
//
//  Created by Maarten Billemont on 29/10/10.
//  Copyright 2010, lhunath (Maarten Billemont). All rights reserved.
//

#import <UIKit/UIKit.h>

#define UIApp [UIApplication sharedApplication]
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

// Modify the variable (of type CGRect) such that it contains a new CGRect derived from the original.
#define CGRectSetX(rect, value)                     rect = CGRectWithX(rect, value)
#define CGRectSetY(rect, value)                     rect = CGRectWithY(rect, value)
#define CGRectSetWidth(rect, value)                 rect = CGRectWithWidth(rect, value)
#define CGRectSetHeight(rect, value)                rect = CGRectWithHeight(rect, value)
#define CGRectSetOrigin(rect, value)                rect = CGRectWithOrigin(rect, value)
#define CGRectSetSize(rect, value)                  rect = CGRectWithSize(rect, value)
#define CGRectSetCenter(rect, value)                rect = CGRectWithCenter(rect, value)
#define CGRectSetTop(rect, value)                   rect = CGRectWithTop(rect, value)
#define CGRectSetRight(rect, value)                 rect = CGRectWithRight(rect, value)
#define CGRectSetBottom(rect, value)                rect = CGRectWithBottom(rect, value)
#define CGRectSetLeft(rect, value)                  rect = CGRectWithLeft(rect, value)
#define CGRectSetTopLeft(rect, value)               rect = CGRectWithTopLeft(rect, value)
#define CGRectSetTopRight(rect, value)              rect = CGRectWithTopRight(rect, value)
#define CGRectSetBottomRight(rect, value)           rect = CGRectWithBottomRight(rect, value)
#define CGRectSetBottomLeft(rect, value)            rect = CGRectWithBottomLeft(rect, value)

#define CGRectSetXDidChange(rect, value)            ({ CGRect __old = rect; CGRectSetX(rect, value); !CGRectEqualToRect(__old, rect); })
#define CGRectSetYDidChange(rect, value)            ({ CGRect __old = rect; CGRectSetY(rect, value); !CGRectEqualToRect(__old, rect); })
#define CGRectSetWidthDidChange(rect, value)        ({ CGRect __old = rect; CGRectSetWidth(rect, value); !CGRectEqualToRect(__old, rect); })
#define CGRectSetHeightDidChange(rect, value)       ({ CGRect __old = rect; CGRectSetHeight(rect, value); !CGRectEqualToRect(__old, rect); })
#define CGRectSetOriginDidChange(rect, value)       ({ CGRect __old = rect; CGRectSetOrigin(rect, value); !CGRectEqualToRect(__old, rect); })
#define CGRectSetSizeDidChange(rect, value)         ({ CGRect __old = rect; CGRectSetSize(rect, value); !CGRectEqualToRect(__old, rect); })

__BEGIN_DECLS
// Create a new CGRect derived from the original.
extern CGRect CGRectWithX(CGRect rect, CGFloat x);
extern CGRect CGRectWithY(CGRect rect, CGFloat y);
extern CGRect CGRectWithWidth(CGRect rect, CGFloat width);
extern CGRect CGRectWithHeight(CGRect rect, CGFloat height);
extern CGRect CGRectWithOrigin(CGRect rect, CGPoint origin);
extern CGRect CGRectWithSize(CGRect rect, CGSize size);

// Calculate the point of a certain part of a CGRect.
extern CGPoint CGRectGetCenter(CGRect rect);
extern CGPoint CGRectGetTop(CGRect rect);
extern CGPoint CGRectGetRight(CGRect rect);
extern CGPoint CGRectGetBottom(CGRect rect);
extern CGPoint CGRectGetLeft(CGRect rect);
extern CGPoint CGRectGetTopLeft(CGRect rect);
extern CGPoint CGRectGetTopRight(CGRect rect);
extern CGPoint CGRectGetBottomRight(CGRect rect);
extern CGPoint CGRectGetBottomLeft(CGRect rect);

// Create a new CGRect from the original anchored at a new position.
extern CGRect CGRectWithCenter(CGRect rect, CGPoint newCenter);
extern CGRect CGRectWithTop(CGRect rect, CGPoint newTop);
extern CGRect CGRectWithRight(CGRect rect, CGPoint newRight);
extern CGRect CGRectWithBottom(CGRect rect, CGPoint newBottom);
extern CGRect CGRectWithLeft(CGRect rect, CGPoint newLeft);
extern CGRect CGRectWithTopLeft(CGRect rect, CGPoint newTopLeft);
extern CGRect CGRectWithTopRight(CGRect rect, CGPoint newTopRight);
extern CGRect CGRectWithBottomRight(CGRect rect, CGPoint newBottomRight);
extern CGRect CGRectWithBottomLeft(CGRect rect, CGPoint newBottomLeft);

/** Get the UIEdgeInsets that insets each edge by the largest edge of either a or b. */
UIEdgeInsets UIEdgeInsetsUnionEdgeInsets(UIEdgeInsets a, UIEdgeInsets b);

/** Get the UIEdgeInsets to apply to the insetRect in order to subtract the subtractRect from it. */
extern UIEdgeInsets UIEdgeInsetsForRectSubtractingRect(CGRect insetRect, CGRect subtractRect);

// UIViewAnimationCurve -> UIViewAnimationOptions
extern UIViewAnimationOptions UIViewAnimationCurveToOptions(UIViewAnimationCurve curve);

// CGPoint <-> CGSize.
extern CGPoint CGPointFromCGSize(const CGSize size);
extern CGPoint CGPointFromCGSizeCenter(const CGSize size);
extern CGSize CGSizeFromCGPoint(const CGPoint point);

// Creating a CGRect.
extern CGRect CGRectFromOriginWithSize(const CGPoint origin, const CGSize size);
extern CGRect CGRectFromCenterWithSize(const CGPoint center, const CGSize size);
/** Use CGFLOAT_MAX in size or padding for auto values.  Currently, in every dimension, only one property may be CGFLOAT_MAX. */
extern CGRect CGRectInCGRectWithSizeAndPadding(const CGRect parent, CGSize size, CGFloat top, CGFloat right, CGFloat bottom, CGFloat left);

// Create a new CGPoint by applying an operation to an original CGPoint.
extern CGPoint CGPointMinusCGPoint(const CGPoint origin, const CGPoint subtract);
extern CGPoint CGPointPlusCGPoint(const CGPoint origin, const CGPoint add);
extern CGPoint CGPointMultiply(const CGPoint origin, const CGFloat multiply);
extern CGPoint CGPointMultiplyCGPoint(const CGPoint origin, const CGPoint multiply);

// Getting the distance between CGPoints.
extern CGPoint CGPointDistanceBetweenCGPoints(CGPoint from, CGPoint to);
extern CGFloat DistanceBetweenCGPointsSq(CGPoint from, CGPoint to);
extern CGFloat DistanceBetweenCGPoints(CGPoint from, CGPoint to);

typedef struct PearlLayout {
    CGFloat left;
    CGFloat top;
    CGFloat width;
    CGFloat height;
    CGFloat bottom;
    CGFloat right;
} PearlLayout;

typedef NS_OPTIONS( NSUInteger, PearlLayoutOption ) {
    PearlLayoutOptionConstrainSize = 2 >> 1,
};
__END_DECLS

@interface UIView(PearlUIUtils)

- (NSArray *)addConstraintsWithVisualFormat:(NSString *)format options:(NSLayoutFormatOptions)opts
                                    metrics:(NSDictionary *)metrics views:(NSDictionary *)views;
- (NSArray *)addConstraintsWithVisualFormats:(NSArray *)formats options:(NSLayoutFormatOptions)opts
                                     metrics:(NSDictionary *)metrics views:(NSDictionary *)views;
/** @return All constraints in the view hierarchy that apply to this view. */
- (NSArray *)applicableConstraints;
- (NSDictionary *)applicableConstraintsByHolder;
/** @return The first constraint that applies to this view's given attribute. */
- (NSLayoutConstraint *)firstConstraintForAttribute:(NSLayoutAttribute)attribute;
/** @return The first constraint that applies to this view's given attribute and relates to the given other view. */
- (NSLayoutConstraint *)firstConstraintForAttribute:(NSLayoutAttribute)attribute otherView:(UIView *)otherView;
- (void)setFrameFromCurrentSizeAndParentPaddingTop:(CGFloat)top right:(CGFloat)right
                                            bottom:(CGFloat)bottom left:(CGFloat)left;
- (void)setFrameFromSize:(CGSize)size andParentPaddingTop:(CGFloat)top right:(CGFloat)right
                  bottom:(CGFloat)bottom left:(CGFloat)left;
- (void)setFrameFromSize:(CGSize)size andParentPaddingTop:(CGFloat)top right:(CGFloat)right
                  bottom:(CGFloat)bottom left:(CGFloat)left constrainSize:(BOOL)constrainSize;

/**
 * Set the layout of the view based on the given layout string.
 *
 * @"left | top [ width / height ] bottom | right"
 *
 * A "-" padding = parent's layout margin, a "-" size = 44.
 * An "=" dimension retains its current value.
 * A ">" left/top or "<" right/bottom padding = expand.
 * Empty padding = 0, empty size = fit or expand if both paddings are fixed.
 * An "x", "y" or "z" will be replaced with the x, y and z parameter value.
 * Spaces around operators are permitted.
 *
 * @"-[  ]-"       // Use the superview's left and right layout margin, top and bottom default to 0.
 *                 // Since width and height are unspecified but edges are fixed, they will fill available space.
 *
 * @"[  ]20"       // Left defaults to 0 and right is fixed to 20.  Top and bottom also default to 0.
 *                 // Since width and height are unspecified but edges are fixed, they will fill available space.
 *
 * @">[  ]<"       // Left and right edges expand, top and bottom default to 0.
 *                 // Width is unspecified but at least one horizontal edge wants to expand, so use the fitting width.
 *                 // Height is unspecified but the vertical edges are fixed, so height will still fill available space.
 *
 * @">|-[  ]-|-"  // expand left, 8pt from right, 5pt width.  8pt from top and bottom, expand height.
 * @">[ -/30 ]-|"   // expand left, fixed to right.  Fixed to top, 8pt from bottom,  44pt height.
 */
- (void)setFrameFrom:(NSString *)layoutString;
- (void)setFrameFrom:(NSString *)layoutString x:(CGFloat)x;
- (void)setFrameFrom:(NSString *)layoutString x:(CGFloat)x y:(CGFloat)y;
- (void)setFrameFrom:(NSString *)layoutString x:(CGFloat)x y:(CGFloat)y z:(CGFloat)z;
- (void)setFrameFrom:(NSString *)layoutString using:(PearlLayout)layoutOverrides;
- (void)setFrameFrom:(NSString *)layoutString x:(CGFloat)x y:(CGFloat)y z:(CGFloat)z using:(PearlLayout)layoutOverrides;
- (void)setFrameFrom:(NSString *)layoutString x:(CGFloat)x y:(CGFloat)y z:(CGFloat)z using:(PearlLayout)layoutOverrides
             options:(PearlLayoutOption)options;

/** Return the view or the first parent of it that is of the receiver's type. */
+ (instancetype)findAsSuperviewOf:(UIView *)view;
- (BOOL)isOrHasSuperviewOfKind:(Class)kind;
- (BOOL)enumerateViews:(void ( ^ )(UIView *subview, BOOL *stop, BOOL *recurse))block recurse:(BOOL)recurseDefault;
- (void)printSuperHierarchy;
- (void)printChildHierarchy;
/** Return a string that briefly describes this view. */
- (NSString *)infoDescription;
/** Return a string that briefly describes this view's layout. */
- (NSString *)layoutDescription;

/**
 * Calculate which of this view's subviews have their center closest to the given point.
 */
- (UIView *)subviewClosestTo:(CGPoint)point;

/**
 * Calculate the bounds of the content of the given view by recursively iterating and checking the content bounds
 * of its subviews, so long as it does not clip them.
 *
 * @param ignoredSubviews These subviews are ignored when determining the bounds of the scroll view's content.
 */
- (CGRect)contentBoundsIgnoringSubviews:(UIView *)ignoredSubviews, ... NS_REQUIRES_NIL_TERMINATION;

/**
 * Calculate the bounds of the content of the given view by recursively iterating and checking the content bounds
 * of its subviews, so long as it does not clip them.
 *
 * @param ignoredSubviewsArray These subviews are ignored when determining the bounds of the scroll view's content.
 */
- (CGRect)contentBoundsIgnoringSubviewsArray:(NSArray *)ignoredSubviewsArray;

/**
 * Create a rectangle that describes the given view's frame in the coordinates of the top-level view that contains it.
 */
- (CGRect)frameInWindow;

/**
 * Find the current first responder in the given view's hierarchy.
 * @return The given view or a subview of it that is the current first responder or nil if no view has first responder status.
 */
- (UIView *)findFirstResponderInHierarchy;

@end

@interface PearlUIUtils : NSObject {
}

/**
 * Calculate which of the given views' center is closest to the given point.
 */
+ (UIView *)viewClosestTo:(CGPoint)point of:(UIView *)views, ... NS_REQUIRES_NIL_TERMINATION;

/**
 * Calculate which of the given views' center is closest to the given point.
 */
+ (UIView *)viewClosestTo:(CGPoint)point ofArray:(NSArray *)views;

@end
