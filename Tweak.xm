#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import <QuartzCore/QuartzCore.h>
#import "../PS.h"

#define CLASSICDOCK_PREF_PATH @"/var/mobile/Library/Preferences/org.coolstar.classicdock.plist"
#define BLURBAR_PREF_PATH @"/var/mobile/Library/Preferences/com.insanj.blurbar.plist"
#define CLASSICDOCK_LIBRARY_PATH "/Library/MobileSubstrate/DynamicLibraries/ClassicDock.dylib"
#define CLASSICDOCK_MODERN_MASK_IMAGE @"ModernDockMask.png"
#define FANCY_LIBRARY_PATH "/Library/MobileSubstrate/DynamicLibraries/Fancy.dylib"

#define SMALL_INTERVAL 0.03

#define PREF_PATH @"/var/mobile/Library/Preferences/com.PS.Randomy.plist"
#define PREFIX @"Randomy-"
#define SPRINGBOARD_IDENT @"com.apple.springboard"
#define PreferencesChangedNotification "com.PS.Randomy.prefs"
#define RandomyDidChangeNotification @"RandomyDidChangeNotification"

#define blurStyle(style) [_UIBackdropViewSettings settingsForStyle:style]

@interface SBFolderBackgroundView : NSObject
+ (float)cornerRadiusToInsetContent;
+ (CGSize)folderBackgroundSize;
@end

@interface SBWallpaperEffectView : UIView
@end

@interface SBFolderIconBackgroundView : UIView
@end

@interface SBFolderIconImageView : UIView
@end

@interface SBIconView : UIView
+ (CGSize)defaultIconImageSize;
@end

@interface SBIconImageView : UIView
+ (CGFloat)cornerRadius;
@end

@interface SBCloseBoxView : UIView
@end

@interface SBWallpaperController : NSObject
+ (id)sharedInstance;
- (CGColorRef)homescreenLightForegroundBlurColor;
- (void)_clearHomescreenLightForegroundBlurColor;
@end

@interface _SBIconWallpaperColorProvider : NSObject
- (void)_updateAllClients;
@end

@interface UIApplication (Private)
- (UIStatusBar *)statusBar;
@end

@interface UIStatusBarBackgroundView : UIView
@end

extern "C" CGPoint UIRectGetCenter(CGRect);

static BOOL randomyEnabled;

static NSTimeInterval randomyAnimationInterval = 5;
static NSTimeInterval randomyAnimationDelay = 1;

static CGFloat colorAlpha;
static CGFloat tintAlpha;

static CGFloat away;
static CGFloat awayWhite;
static CGFloat awayBlack;

static BOOL noRandomHook = NO;

static void randomyLoader()
{
	NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:PREF_PATH];
	#define readOption(prename, name, defaultValue) \
		name = [dict objectForKey:prename] ? [[dict objectForKey:prename] boolValue] : defaultValue;
		
	readOption(@"randomyEnabled", randomyEnabled, YES)
	
	id r1 = dict[@"randomyAnimationInterval"];
	randomyAnimationInterval = r1 ? [r1 floatValue] : 5.0f;
	id r2 = dict[@"randomyAnimationDelay"];
	randomyAnimationDelay = r2 ? [r2 floatValue] : 1.0f;
	
	id r3 = dict[@"colorAlpha"];
	colorAlpha = r3 ? [r3 floatValue] : 0.5f;
	id r4 = dict[@"tintAlpha"];
	tintAlpha = r4 ? [r4 floatValue] : 0.3f;
	
	id r7 = dict[@"away"];
	away = r7 ? [r7 floatValue] : 0.5f;
	if (away != 0.5f) {
		awayWhite = away < 0.5f ? abs(away - 0.5f) : 0;
		awayBlack = away > 0.5f ? away - 0.5f : 0;
	}
	[[NSNotificationCenter defaultCenter] postNotificationName:RandomyDidChangeNotification object:nil];
}

static UIColor *randomColor(CGFloat alpha)
{
	CGFloat hue = (arc4random()%256/256.0);
	CGFloat saturation = (arc4random()%128/256.0) + awayWhite;
	CGFloat brightness = (arc4random()%128/256.0) + awayBlack;
	UIColor *color = [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
	return color;
}

static void setSettings(_UIBackdropViewSettings *settings)
{
	settings.usesColorTintView = YES;
	settings.requiresColorStatistics = YES;
	settings.colorTintAlpha = tintAlpha;
	settings.grayscaleTintAlpha = tintAlpha;
	settings.colorTint = randomColor(colorAlpha);
}

static BOOL randomyShouldRun(NSString *identifier)
{
    NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:PREF_PATH];
    BOOL notRun = [dict[[PREFIX stringByAppendingString:identifier]] boolValue];
	return !notRun;
}

%group UIKIT

%hook _UIBackdropViewSettings

+ (_UIBackdropViewSettings *)settingsForStyle:(NSInteger)style graphicsQuality:(NSInteger)quality
{
	_UIBackdropViewSettings *settings = %orig(style, quality);
	setSettings(settings);
	return settings;
}

- (void)setColorTintAlpha:(CGFloat)alpha
{
	%orig(tintAlpha);
}

- (void)setGrayscaleTintAlpha:(CGFloat)alpha
{
	%orig(tintAlpha);
}

- (BOOL)usesColorTintView
{
	return YES;
}

- (void)setUsesColorTintView:(BOOL)tint
{
	%orig(YES);
}

%end

%hook _UIBackdropView

static NSTimer *randomy = nil;

- (void)setAppliesOutputSettingsAnimationDuration:(NSTimeInterval)duration
{
	%orig(randomyAnimationInterval);
}

%new
- (void)randomy
{
	if (!self.applyingTransition && !self.applyingBackdropChanges) {
		UIColor *color = randomColor(colorAlpha);
		self.inputSettings.colorTint = color;
		self.outputSettings.colorTint = color;
	}
}

%new
- (void)randomyDidChange
{
	//NSTimer *random = objc_getAssociatedObject(self, &randomy);
	//objc_setAssociatedObject(self, &randomy, random, OBJC_ASSOCIATION_RETAIN);
}

- (id)initWithFrame:(CGRect)frame autosizesToFitSuperview:(BOOL)fit settings:(_UIBackdropViewSettings *)settings
{
	self = %orig;
	if (self) {
		if (objc_getAssociatedObject(self, &randomy) == nil) {
			NSTimer *random = [NSTimer scheduledTimerWithTimeInterval:(randomyAnimationInterval + randomyAnimationDelay + SMALL_INTERVAL) target:self selector:@selector(randomy) userInfo:nil repeats:YES];
			[random retain];
			objc_setAssociatedObject(self, &randomy, random, OBJC_ASSOCIATION_RETAIN);
		}
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(randomyDidChange) name:RandomyDidChangeNotification object:nil];
	}
	return self;
}

- (void)dealloc
{
	[[NSNotificationCenter defaultCenter] removeObserver:self name:RandomyDidChangeNotification object:nil];
	%orig;
}

%end

%end

%group SB

%hook _SBFakeBlurView

- (void)requestStyle:(NSInteger)style
{
	NSLog(@"style");
	%orig;
}

%end

%hook SBWallpaperController

- (_UILegibilitySettings *)legibilitySettingsForVariant:(NSInteger)variant
{
	_UILegibilitySettings *orig = %orig;
	orig.contentColor = randomColor(colorAlpha);
	return orig;
}

%end

%hook SBWallpaperEffectView

static NSTimer *randomy2 = nil;

- (id)initWithWallpaperVariant:(NSInteger)variant
{
	self = %orig;
	if (self) {
		if (objc_getAssociatedObject(self, &randomy2) == nil) {
			NSTimer *random2 = [NSTimer scheduledTimerWithTimeInterval:(randomyAnimationInterval + randomyAnimationDelay + SMALL_INTERVAL) target:self selector:@selector(randomy) userInfo:nil repeats:YES];
			[random2 retain];
			objc_setAssociatedObject(self, &randomy2, random2, OBJC_ASSOCIATION_RETAIN);
		}
	}
	return self;
}

- (void)_configureFromScratch
{
	NSLog(@"Con");
	%orig;
}

%new
- (void)randomy
{
	//[self wallpaperDidChangeForVariant:1];
	[[%c(SBWallpaperController) sharedInstance] _handleWallpaperLegibilitySettingsChanged:[[%c(SBWallpaperController) sharedInstance] legibilitySettingsForVariant:1] forVariant:1];
}

%end

%end

static void PreferencesChangedCallback(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo)
{
	randomyLoader();
}

%ctor {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, PreferencesChangedCallback, CFSTR(PreferencesChangedNotification), NULL, CFNotificationSuspensionBehaviorCoalesce);
	randomyLoader();
	if (randomyEnabled) {
		%init(UIKIT);
		%init(SB);
	}
	[pool drain];
}
