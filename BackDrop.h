#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore2.h>

//____UIBackdropViewStyleForClass

/*extern "C" float __UIBackdropViewSettingsBlurRadiusNone;
extern "C" float __UIBackdropViewSettingsBlurRadiusSmall;
extern "C" float __UIBackdropViewSettingsBlurRadiusMedium;
extern "C" float __UIBackdropViewSettingsBlurRadiusLarge;*/

@interface CABackdropLayer : CALayer
{
}

+ (BOOL)CA_automaticallyNotifiesObservers:(Class)arg1;
+ (BOOL)_hasRenderLayerSubclass;
+ (id)defaultValueForKey:(id)arg1;
@property double statisticsInterval;
@property(copy) NSString *statisticsType;
@property(copy) NSArray *groupFilters;
@property float marginWidth;
@property struct CGRect backdropRect;
@property float scale;
@property(copy) NSString *groupName;
@property(getter=isEnabled) BOOL enabled;
- (unsigned int)_renderLayerPropertyAnimationFlags:(unsigned int)arg1;
- (_Bool)_renderLayerDefinesProperty:(unsigned int)arg1;
- (struct Layer *)_copyRenderLayer:(struct Transaction *)arg1 layerFlags:(unsigned int)arg2 commitFlags:(unsigned int *)arg3;
- (void)didChangeValueForKey:(id)arg1;
- (id)statisticsValues;
- (void)layerDidBecomeVisible:(BOOL)arg1;

@end

@interface _UIBackdropEffectView : UIView
{
    CABackdropLayer *_backdropLayer;
    float _zoom;
}
 
+ (Class)layerClass;
@property(nonatomic) float zoom;
@property(retain, nonatomic) CABackdropLayer *backdropLayer;
- (void)backdropLayerStatisticsDidChange:(id)arg1;
- (id)valueForUndefinedKey:(id)arg1;
- (BOOL)_shouldAnimatePropertyWithKey:(id)arg1;
- (void)dealloc;
- (id)init;
 
@end
 
@interface _UIBackdropContentView : UIView
{
}
 
- (void)didMoveToWindow;
- (void)_descendent:(id)arg1 willMoveFromSuperview:(id)arg2 toSuperview:(id)arg3;
- (void)_descendent:(id)arg1 didMoveFromSuperview:(id)arg2 toSuperview:(id)arg3;
- (void)recursivelyRemoveBackdropMaskViewsForView:(id)arg1;
- (void)backdropView:(id)arg1 recursivelyUpdateMaskViewsForView:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;
 
@end

@class _UIBackdropViewSettings;

@interface _UIBackdropColorSettings : NSObject {
    float _averageBrightness;
    float _averageHue;
    float _averageSaturation;
    float _contrast;
    BOOL _hasObservedValues;
    _UIBackdropViewSettings *_parentSettings;
    float _previousAverageBrightness;
    float _previousAverageHue;
    float _previousAverageSaturation;
    float _previousContrast;
}

@property float averageBrightness;
@property float averageHue;
@property float averageSaturation;
@property(readonly) UIColor * color;
@property float contrast;
@property BOOL hasObservedValues;
@property(assign) _UIBackdropViewSettings *parentSettings;
@property float previousAverageBrightness;
@property float previousAverageHue;
@property float previousAverageSaturation;
@property float previousContrast;

- (BOOL)applyCABackdropLayerStatistics:(id)arg1;
- (float)averageBrightness;
- (float)averageHue;
- (float)averageSaturation;
- (id)color;
- (float)contrast;
- (BOOL)hasObservedValues;
- (id)parentSettings;
- (float)previousAverageBrightness;
- (float)previousAverageHue;
- (float)previousAverageSaturation;
- (float)previousContrast;
- (void)setAverageBrightness:(float)arg1;
- (void)setAverageHue:(float)arg1;
- (void)setAverageSaturation:(float)arg1;
- (void)setContrast:(float)arg1;
- (void)setDefaultValues;
- (void)setHasObservedValues:(BOOL)arg1;
- (void)setParentSettings:(_UIBackdropViewSettings *)arg1;
- (void)setPreviousAverageBrightness:(float)arg1;
- (void)setPreviousAverageHue:(float)arg1;
- (void)setPreviousAverageSaturation:(float)arg1;
- (void)setPreviousContrast:(float)arg1;
- (void)setValuesFromModel:(id)arg1;

@end

@class _UIBackdropView;

@interface _UIBackdropViewSettings : NSObject
{
    BOOL _appliesTintAndBlurSettings;
    _UIBackdropView *_backdrop;
    BOOL _backdropVisible;
    int _blurHardEdges;
    NSString *_blurQuality;
    float _blurRadius;
    float _colorBurnTintAlpha;
    float _colorBurnTintLevel;
    UIImage *_colorBurnTintMaskImage;
    _UIBackdropColorSettings *_colorSettings;
    UIColor *_colorTint;
    float _colorTintAlpha;
    float _colorTintMaskAlpha;
    UIImage *_colorTintMaskImage;
    UIColor *_combinedTintColor;
    BOOL _darkenWithSourceOver;
    float _darkeningTintAlpha;
    float _darkeningTintBrightness;
    float _darkeningTintHue;
    UIImage *_darkeningTintMaskImage;
    float _darkeningTintSaturation;
    BOOL _designMode;
    BOOL _enabled;
    BOOL _explicitlySetGraphicsQuality;
    float _filterMaskAlpha;
    UIImage *_filterMaskImage;
    int _graphicsQuality;
    float _grayscaleTintAlpha;
    float _grayscaleTintLevel;
    float _grayscaleTintMaskAlpha;
    UIImage *_grayscaleTintMaskImage;
    BOOL _highlighted;
    UIColor *_legibleColor;
    BOOL _lightenGrayscaleWithSourceOver;
    int _renderingHint;
    BOOL _requiresColorStatistics;
    struct CFRunLoopObserver *_runLoopObserver;
    float _saturationDeltaFactor;
    float _scale;
    BOOL _selected;
    int _stackingLevel;
    double _statisticsInterval;
    int _style;
    int _suppressSettingsDidChange;
    BOOL _usesBackdropEffectView;
    BOOL _usesColorBurnTintView;
    BOOL _usesColorTintView;
    BOOL _usesContentView;
    BOOL _usesDarkeningTintView;
    BOOL _usesGrayscaleTintView;
    unsigned int _version;
    BOOL _zoomsBack;
}

@property BOOL appliesTintAndBlurSettings;
@property(assign) _UIBackdropView * backdrop;
@property(getter=isBackdropVisible) BOOL backdropVisible;
@property int blurHardEdges;
@property(copy) NSString * blurQuality;
@property float blurRadius;
@property BOOL blursWithHardEdges;
@property float colorBurnTintAlpha;
@property float colorBurnTintLevel;
@property(retain) UIImage * colorBurnTintMaskImage;
@property(retain) _UIBackdropColorSettings * colorSettings;
@property(retain) UIColor * colorTint;
@property float colorTintAlpha;
@property float colorTintMaskAlpha;
@property(retain) UIImage * colorTintMaskImage;
@property(retain) UIColor * combinedTintColor;
@property BOOL darkenWithSourceOver;
@property float darkeningTintAlpha;
@property float darkeningTintBrightness;
@property float darkeningTintHue;
@property(retain) UIImage * darkeningTintMaskImage;
@property float darkeningTintSaturation;
@property(setter=setDesignMode:) BOOL designMode;
@property(getter=isEnabled) BOOL enabled;
@property BOOL explicitlySetGraphicsQuality;
@property float filterMaskAlpha;
@property(retain) UIImage * filterMaskImage;
@property int graphicsQuality;
@property float grayscaleTintAlpha;
@property float grayscaleTintLevel;
@property float grayscaleTintMaskAlpha;
@property(retain) UIImage * grayscaleTintMaskImage;
@property(getter=isHighlighted) BOOL highlighted;
@property(retain) UIColor *legibleColor;
@property BOOL lightenGrayscaleWithSourceOver;
@property int renderingHint;
@property BOOL requiresColorStatistics;
@property struct CFRunLoopObserver *runLoopObserver;
@property float saturationDeltaFactor;
@property float scale;
@property(getter=isSelected) BOOL selected;
@property int stackingLevel;
@property double statisticsInterval;
@property int style;
@property int suppressSettingsDidChange;
@property BOOL usesBackdropEffectView;
@property BOOL usesColorBurnTintView;
@property BOOL usesColorTintView;
@property BOOL usesContentView;
@property BOOL usesDarkeningTintView;
@property BOOL usesGrayscaleTintView;
@property unsigned int version;
@property BOOL zoomsBack;

+ (id)darkeningTintColor;
+ (id)settingsForPrivateStyle:(int)arg1 graphicsQuality:(int)arg2;
+ (id)settingsForPrivateStyle:(int)arg1;
+ (id)settingsForStyle:(int)arg1 graphicsQuality:(int)arg2;
+ (id)settingsForStyle:(int)arg1;

- (void)addKeyPathObserver:(id)arg1;
- (BOOL)appliesTintAndBlurSettings;
- (id)backdrop;
- (int)blurHardEdges;
- (id)blurQuality;
- (float)blurRadius;
- (BOOL)blursWithHardEdges;
- (void)clearRunLoopObserver;
- (float)colorBurnTintAlpha;
- (float)colorBurnTintLevel;
- (id)colorBurnTintMaskImage;
- (id)colorSettings;
- (id)colorTint;
- (float)colorTintAlpha;
- (float)colorTintMaskAlpha;
- (id)colorTintMaskImage;
- (id)combinedTintColor;
- (void)computeOutputSettingsUsingModel:(id)arg1;
- (BOOL)darkenWithSourceOver;
- (float)darkeningTintAlpha;
- (float)darkeningTintBrightness;
- (float)darkeningTintHue;
- (id)darkeningTintMaskImage;
- (float)darkeningTintSaturation;
- (void)dealloc;
- (void)decrementSuppressSettingsDidChange;
- (id)description;
- (BOOL)designMode;
- (BOOL)explicitlySetGraphicsQuality;
- (float)filterMaskAlpha;
- (id)filterMaskImage;
- (int)graphicsQuality;
- (float)grayscaleTintAlpha;
- (float)grayscaleTintLevel;
- (float)grayscaleTintMaskAlpha;
- (id)grayscaleTintMaskImage;
- (void)incrementSuppressSettingsDidChange;
- (id)init;
- (id)initWithDefaultValues;
- (id)initWithDefaultValuesForGraphicsQuality:(int)arg1;
- (BOOL)isBackdropVisible;
- (BOOL)isEnabled;
- (BOOL)isHighlighted;
- (BOOL)isSelected;
- (id)legibleColor;
- (BOOL)lightenGrayscaleWithSourceOver;
- (void)removeKeyPathObserver:(id)arg1;
- (int)renderingHint;
- (BOOL)requiresColorStatistics;
- (void)restoreDefaultValues;
- (struct CFRunLoopObserver *)runLoopObserver;
- (float)saturationDeltaFactor;
- (float)scale;
- (void)scheduleSettingsDidChangeIfNeeded;
- (void)setAppliesTintAndBlurSettings:(BOOL)arg1;
- (void)setBackdrop:(_UIBackdropView *)arg1;
- (void)setBackdropVisible:(BOOL)arg1;
- (void)setBlurHardEdges:(int)arg1;
- (void)setBlurQuality:(NSString *)arg1;
- (void)setBlurRadius:(float)arg1;
- (void)setBlursWithHardEdges:(BOOL)arg1;
- (void)setColorBurnTintAlpha:(float)arg1;
- (void)setColorBurnTintLevel:(float)arg1;
- (void)setColorBurnTintMaskImage:(UIImage *)arg1;
- (void)setColorSettings:(_UIBackdropColorSettings *)arg1;
- (void)setColorTint:(UIColor *)arg1;
- (void)setColorTintAlpha:(float)arg1;
- (void)setColorTintMaskAlpha:(float)arg1;
- (void)setColorTintMaskImage:(UIImage *)arg1;
- (void)setCombinedTintColor:(UIColor *)arg1;
- (void)setDarkenWithSourceOver:(BOOL)arg1;
- (void)setDarkeningTintAlpha:(float)arg1;
- (void)setDarkeningTintBrightness:(float)arg1;
- (void)setDarkeningTintHue:(float)arg1;
- (void)setDarkeningTintMaskImage:(UIImage *)arg1;
- (void)setDarkeningTintSaturation:(float)arg1;
- (void)setDefaultValues;
- (void)setDesignMode:(BOOL)arg1;
- (void)setEnabled:(BOOL)arg1;
- (void)setExplicitlySetGraphicsQuality:(BOOL)arg1;
- (void)setFilterMaskAlpha:(float)arg1;
- (void)setFilterMaskImage:(UIImage *)arg1;
- (void)setGraphicsQuality:(int)arg1;
- (void)setGrayscaleTintAlpha:(float)arg1;
- (void)setGrayscaleTintLevel:(float)arg1;
- (void)setGrayscaleTintMaskAlpha:(float)arg1;
- (void)setGrayscaleTintMaskImage:(UIImage *)arg1;
- (void)setHighlighted:(BOOL)arg1;
- (void)setLegibleColor:(UIColor *)arg1;
- (void)setLightenGrayscaleWithSourceOver:(BOOL)arg1;
- (void)setRenderingHint:(int)arg1;
- (void)setRequiresColorStatistics:(BOOL)arg1;
- (void)setRunLoopObserver:(struct CFRunLoopObserver *)arg1;
- (void)setSaturationDeltaFactor:(float)arg1;
- (void)setScale:(float)arg1;
- (void)setSelected:(BOOL)arg1;
- (void)setStackingLevel:(int)arg1;
- (void)setStackinglevel:(int)arg1;
- (void)setStatisticsInterval:(double)arg1;
- (void)setStyle:(int)arg1;
- (void)setSuppressSettingsDidChange:(int)arg1;
- (void)setUsesBackdropEffectView:(BOOL)arg1;
- (void)setUsesColorBurnTintView:(BOOL)arg1;
- (void)setUsesColorTintView:(BOOL)arg1;
- (void)setUsesContentView:(BOOL)arg1;
- (void)setUsesDarkeningTintView:(BOOL)arg1;
- (void)setUsesGrayscaleTintView:(BOOL)arg1;
- (void)setValuesFromModel:(id)arg1;
- (void)setVersion:(unsigned int)arg1;
- (void)setZoomsBack:(BOOL)arg1;
- (int)stackingLevel;
- (double)statisticsInterval;
- (int)style;
- (int)suppressSettingsDidChange;
- (BOOL)usesBackdropEffectView;
- (BOOL)usesColorBurnTintView;
- (BOOL)usesColorTintView;
- (BOOL)usesContentView;
- (BOOL)usesDarkeningTintView;
- (BOOL)usesGrayscaleTintView;
- (unsigned int)version;
- (BOOL)zoomsBack;

@end

@protocol _UIBackdropViewObserver
@required
-(void)backdropViewDidChange:(id)arg1;
@end

@protocol _UIBackdropViewGraphicsQualityChangeDelegate
@required
-(id)backdropView:(id)arg1 willChangeToGraphicsQuality:(int)arg2;
-(void)backdropView:(id)arg1 didChangeToGraphicsQuality:(int)arg2;
@end
 
@interface _UIBackdropView : UIView
{
    BOOL _autosizesToFitSuperview;
    BOOL _computesColorSettings;
    BOOL _appliesOutputSettingsAutomatically;
    BOOL _appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
    BOOL _applyingBackdropChanges;
    BOOL _applyingTransition;
    BOOL _requiresTintViews;
    BOOL _wantsColorSettings;
    BOOL _blursBackground;
    BOOL _allowsColorSettingsSuppression;
    BOOL _contentViewAccessed;
    BOOL _contentViewAccessorGuard;
    BOOL _applySettingsAfterLayout;
    BOOL _updateMaskViewsForViewReentrancyGuard;
    BOOL _simulatesMasks;
    BOOL _backdropVisibilitySetOnce;
    BOOL _blurRadiusSetOnce;
    BOOL __backdropVisible;
    BOOL __zoomsBack;
    int _style;
    NSHashTable *_observers;
    id <_UIBackdropViewObserver> _observer;
    _UIBackdropViewSettings *_inputSettings;
    _UIBackdropViewSettings *_outputSettings;
    _UIBackdropViewSettings *_savedInputSettingsDuringRenderInContext;
    int _configuration;
    _UIBackdropEffectView *_backdropEffectView;
    NSString *_groupName;
    UIImage *_filterMaskImage;
    UIView *_grayscaleTintView;
    UIImage *_grayscaleTintMaskImage;
    UIView *_colorTintView;
    UIImage *_colorTintMaskImage;
    CAFilter *_gaussianBlurFilter;
    CAFilter *_colorSaturateFilter;
    CAFilter *_tintFilter;
    UIView *_contentView;
    int _maskMode;
    NSMutableSet *_partialMaskViews;
    UIView *_grayscaleTintMaskViewContainer;
    NSMutableDictionary *_grayscaleTintMaskViewMap;
    UIView *_colorTintMaskViewContainer;
    NSMutableDictionary *_colorTintMaskViewMap;
    UIView *_filterMaskViewContainer;
    NSMutableDictionary *_filterMaskViewMap;
    id _computeAndApplySettingsNotificationObserver;
    float _colorMatrixGrayscaleTintLevel;
    float _colorMatrixGrayscaleTintAlpha;
    UIColor *_colorMatrixColorTint;
    float _colorMatrixColorTintAlpha;
    int _blurHardEdges;
    struct CFRunLoopObserver *_updateInputBoundsRunLoopObserver;
    float _previousBackdropStatisticsRed;
    float _previousBackdropStatisticsGreen;
    float _previousBackdropStatisticsBlue;
    float _previousBackdropStatisticsContrast;
    id <_UIBackdropViewGraphicsQualityChangeDelegate> _graphicsQualityChangeDelegate;
    NSString *__blurQuality;
    float __blurRadius;
    float __saturationDeltaFactor;
    double _appliesOutputSettingsAnimationDuration;
}
 
+ (Class)layerClass;
+ (Class)defaultSettingsClass;
+ (void)setAllBackdropViewsToGraphicsQuality:(int)arg1;
+ (void)adjustGraphicsQualityForAccessibilityIfNeeded:(id)arg1;
+ (void)restoreColorSettingsForRequester:(id)arg1;
+ (void)suppressColorSettingsForRequester:(id)arg1;
+ (void)restoreColorSettingsForDidBecomeActive:(id)arg1;
+ (void)suppressColorSettingsForWillResignActive:(id)arg1;
+ (void)restoreColorSettingsForRunLoopModePop:(id)arg1;
+ (void)suppressColorSettingsForRunLoopModePush:(id)arg1;
+ (id)allBackdropViews;
@property(nonatomic, setter=setZoomsBack:) BOOL _zoomsBack; // @synthesize _zoomsBack=__zoomsBack;
@property(nonatomic) BOOL _backdropVisible; // @synthesize _backdropVisible=__backdropVisible;
@property(nonatomic) float _saturationDeltaFactor; // @synthesize _saturationDeltaFactor=__saturationDeltaFactor;
@property(nonatomic) float _blurRadius; // @synthesize _blurRadius=__blurRadius;
@property(copy, nonatomic) NSString *_blurQuality; // @synthesize _blurQuality=__blurQuality;
//@property id <_UIBackdropViewGraphicsQualityChangeDelegate> *graphicsQualityChangeDelegate;
@property(nonatomic) float previousBackdropStatisticsContrast; // @synthesize previousBackdropStatisticsContrast=_previousBackdropStatisticsContrast;
@property(nonatomic) float previousBackdropStatisticsBlue; // @synthesize previousBackdropStatisticsBlue=_previousBackdropStatisticsBlue;
@property(nonatomic) float previousBackdropStatisticsGreen; // @synthesize previousBackdropStatisticsGreen=_previousBackdropStatisticsGreen;
@property(nonatomic) float previousBackdropStatisticsRed; // @synthesize previousBackdropStatisticsRed=_previousBackdropStatisticsRed;
@property(nonatomic) BOOL blurRadiusSetOnce; // @synthesize blurRadiusSetOnce=_blurRadiusSetOnce;
@property(nonatomic) BOOL backdropVisibilitySetOnce; // @synthesize backdropVisibilitySetOnce=_backdropVisibilitySetOnce;
@property(nonatomic) struct CFRunLoopObserver *updateInputBoundsRunLoopObserver; // @synthesize updateInputBoundsRunLoopObserver=_updateInputBoundsRunLoopObserver;
@property(nonatomic) int blurHardEdges; // @synthesize blurHardEdges=_blurHardEdges;
@property(nonatomic) BOOL simulatesMasks; // @synthesize simulatesMasks=_simulatesMasks;
@property(nonatomic) float colorMatrixColorTintAlpha; // @synthesize colorMatrixColorTintAlpha=_colorMatrixColorTintAlpha;
@property(retain, nonatomic) UIColor *colorMatrixColorTint; // @synthesize colorMatrixColorTint=_colorMatrixColorTint;
@property(nonatomic) float colorMatrixGrayscaleTintAlpha; // @synthesize colorMatrixGrayscaleTintAlpha=_colorMatrixGrayscaleTintAlpha;
@property(nonatomic) float colorMatrixGrayscaleTintLevel; // @synthesize colorMatrixGrayscaleTintLevel=_colorMatrixGrayscaleTintLevel;
@property(nonatomic) BOOL updateMaskViewsForViewReentrancyGuard; // @synthesize updateMaskViewsForViewReentrancyGuard=_updateMaskViewsForViewReentrancyGuard;
@property(retain, nonatomic) id computeAndApplySettingsNotificationObserver; // @synthesize computeAndApplySettingsNotificationObserver=_computeAndApplySettingsNotificationObserver;
@property(nonatomic) BOOL applySettingsAfterLayout; // @synthesize applySettingsAfterLayout=_applySettingsAfterLayout;
@property(retain, nonatomic) NSMutableDictionary *filterMaskViewMap; // @synthesize filterMaskViewMap=_filterMaskViewMap;
@property(retain, nonatomic) UIView *filterMaskViewContainer; // @synthesize filterMaskViewContainer=_filterMaskViewContainer;
@property(retain, nonatomic) NSMutableDictionary *colorTintMaskViewMap; // @synthesize colorTintMaskViewMap=_colorTintMaskViewMap;
@property(retain, nonatomic) UIView *colorTintMaskViewContainer; // @synthesize colorTintMaskViewContainer=_colorTintMaskViewContainer;
@property(retain, nonatomic) NSMutableDictionary *grayscaleTintMaskViewMap; // @synthesize grayscaleTintMaskViewMap=_grayscaleTintMaskViewMap;
@property(retain, nonatomic) UIView *grayscaleTintMaskViewContainer; // @synthesize grayscaleTintMaskViewContainer=_grayscaleTintMaskViewContainer;
@property(retain, nonatomic) NSMutableSet *partialMaskViews; // @synthesize partialMaskViews=_partialMaskViews;
@property(nonatomic) int maskMode; // @synthesize maskMode=_maskMode;
@property(nonatomic) BOOL contentViewAccessorGuard; // @synthesize contentViewAccessorGuard=_contentViewAccessorGuard;
@property(nonatomic) BOOL contentViewAccessed; // @synthesize contentViewAccessed=_contentViewAccessed;
@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(retain, nonatomic) CAFilter *tintFilter; // @synthesize tintFilter=_tintFilter;
@property(retain, nonatomic) CAFilter *colorSaturateFilter; // @synthesize colorSaturateFilter=_colorSaturateFilter;
@property(retain, nonatomic) CAFilter *gaussianBlurFilter; // @synthesize gaussianBlurFilter=_gaussianBlurFilter;
@property(retain, nonatomic) UIImage *colorTintMaskImage; // @synthesize colorTintMaskImage=_colorTintMaskImage;
@property(retain, nonatomic) UIView *colorTintView; // @synthesize colorTintView=_colorTintView;
@property(retain, nonatomic) UIImage *grayscaleTintMaskImage; // @synthesize grayscaleTintMaskImage=_grayscaleTintMaskImage;
@property(retain, nonatomic) UIView *grayscaleTintView; // @synthesize grayscaleTintView=_grayscaleTintView;
@property(retain, nonatomic) UIImage *filterMaskImage; // @synthesize filterMaskImage=_filterMaskImage;
@property(copy, nonatomic) NSString *groupName; // @synthesize groupName=_groupName;
@property(retain, nonatomic) _UIBackdropEffectView *backdropEffectView; // @synthesize backdropEffectView=_backdropEffectView;
@property(nonatomic) BOOL allowsColorSettingsSuppression; // @synthesize allowsColorSettingsSuppression=_allowsColorSettingsSuppression;
@property(nonatomic) BOOL blursBackground; // @synthesize blursBackground=_blursBackground;
@property(nonatomic) BOOL wantsColorSettings; // @synthesize wantsColorSettings=_wantsColorSettings;
@property(nonatomic) BOOL requiresTintViews; // @synthesize requiresTintViews=_requiresTintViews;
@property(nonatomic) BOOL applyingTransition; // @synthesize applyingTransition=_applyingTransition;
@property(nonatomic) BOOL applyingBackdropChanges; // @synthesize applyingBackdropChanges=_applyingBackdropChanges;
@property(nonatomic) BOOL appliesOutputSettingsAutomaticallyEnabledComputesColorSettings; // @synthesize appliesOutputSettingsAutomaticallyEnabledComputesColorSettings=_appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
@property(nonatomic) int configuration; // @synthesize configuration=_configuration;
@property(retain, nonatomic) _UIBackdropViewSettings *savedInputSettingsDuringRenderInContext; // @synthesize savedInputSettingsDuringRenderInContext=_savedInputSettingsDuringRenderInContext;
@property(retain, nonatomic) _UIBackdropViewSettings *outputSettings; // @synthesize outputSettings=_outputSettings;
@property(retain, nonatomic) _UIBackdropViewSettings *inputSettings; // @synthesize inputSettings=_inputSettings;
@property(nonatomic) double appliesOutputSettingsAnimationDuration; // @synthesize appliesOutputSettingsAnimationDuration=_appliesOutputSettingsAnimationDuration;
@property(nonatomic) BOOL appliesOutputSettingsAutomatically; // @synthesize appliesOutputSettingsAutomatically=_appliesOutputSettingsAutomatically;
@property(nonatomic) BOOL computesColorSettings; // @synthesize computesColorSettings=_computesColorSettings;
//@property id <_UIBackdropViewObserver> *observer;
@property(retain, nonatomic) NSHashTable *observers; // @synthesize observers=_observers;
@property(nonatomic) BOOL autosizesToFitSuperview; // @synthesize autosizesToFitSuperview=_autosizesToFitSuperview;
@property(nonatomic) int style; // @synthesize style=_style;
- (void)applySettings:(id)arg1;
- (void)applySettingsWithBuiltInAnimation:(id)arg1;
- (void)computeAndApplySettingsForTransition;
- (void)computeAndApplySettings:(id)arg1;
- (void)delayedComputeAndApplySettings;
- (void)adjustTintImplementationIfNeeded:(id)arg1;
- (void)ensureProperSubviewOrdering;
- (void)addContentViewIfNeededForSettings:(id)arg1;
- (void)addColorTintViewIfNeededForSettings:(id)arg1;
- (void)addGrayscaleTintViewIfNeededForSettings:(id)arg1;
- (void)addBackdropEffectViewIfNeededForSettings:(id)arg1;
- (void)updateSubviewHierarchyIfNeededForSettings:(id)arg1;
@property(readonly, nonatomic) UIView *effectView; // @dynamic effectView;
- (void)transitionComplete;
- (void)transitionIncrementallyToPrivateStyle:(int)arg1 weighting:(float)arg2;
- (void)transitionIncrementallyToStyle:(int)arg1 weighting:(float)arg2;
- (void)transitionToSettings:(_UIBackdropViewSettings *)arg1;
- (void)transitionToColor:(UIColor *)arg1;
- (void)transitionToPrivateStyle:(int)arg1;
- (void)transitionToStyle:(int)arg1;
- (void)prepareForTransitionToSettings:(id)arg1;
- (void)_setBlursBackground:(BOOL)arg1;
- (void)setUsesZoom;
- (void)setBackdropVisible:(BOOL)arg1;
- (BOOL)isBackdropVisible;
- (void)setTintFilterForSettings:(id)arg1;
- (void)setSaturationDeltaFactor:(float)arg1;
- (float)saturationDeltaFactor;
- (void)_updateInputBounds;
- (void)scheduleUpdateInputBoundsIfNeeded;
- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(id)arg2 blurHardEdges:(int)arg3;
- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(id)arg2;
- (void)setBlursWithHardEdges:(BOOL)arg1;
- (BOOL)blursWithHardEdges;
- (void)setBlurQuality:(id)arg1;
- (id)blurQuality;
- (void)setBlurRadius:(float)arg1;
- (float)blurRadius;
- (id)filters;
- (void)_updateFilters;
- (void)removeOverlayBlendModeFromView:(id)arg1;
- (void)applyOverlayBlendModeToView:(id)arg1;
- (void)applyOverlayBlendMode:(int)arg1 toView:(id)arg2;
- (void)removeMaskViews;
- (void)updateMaskViewsForView:(id)arg1;
- (void)updateMaskViewForView:(id)arg1 flag:(int)arg2;
- (void)setMaskImage:(id)arg1 onLayer:(id)arg2;
- (void)setBounds:(struct CGRect)arg1;
- (void)setFrame:(struct CGRect)arg1;
- (void)layoutSubviews;
- (void)didMoveToSuperview;
- (void)removeObserver:(id)arg1;
- (void)addObserver:(id)arg1;
- (void)didCallRenderInContextOnBackdropViewLayer;
- (void)willCallRenderInContextOnBackdropViewLayer;
- (id)backdropViewLayer;
- (void)setShouldRasterizeEffectsView:(BOOL)arg1;
- (void)backdropLayerStatisticsDidChange:(id)arg1;
- (void)settingsDidChange:(id)arg1;
- (void)clearUpdateInputBoundsRunLoopObserver;
- (void)dealloc;
- (id)init;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1 privateStyle:(int)arg2;
- (id)initWithFrame:(struct CGRect)arg1 style:(int)arg2;
- (id)initWithPrivateStyle:(int)arg1;
- (id)initWithStyle:(int)arg1;
- (id)initWithSettings:(_UIBackdropViewSettings *)arg1;
- (id)initWithFrame:(struct CGRect)arg1 settings:(_UIBackdropViewSettings *)arg2;
- (id)initWithFrame:(struct CGRect)arg1 autosizesToFitSuperview:(BOOL)arg2 settings:(_UIBackdropViewSettings *)arg3;
 
@end

@interface _UIBackdropViewLayer : CALayer
{
    _UIBackdropView *_backdropView;
}
 
@property(assign) _UIBackdropView *backdropView;
- (void)dealloc;
- (void)renderInContext:(struct CGContext *)arg1;
 
@end

@interface _UIBackdropViewSettingsNone : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsBlur : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsColored : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsColorSample : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsCombiner : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsDark : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsDarkLow : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsDarkWithZoom : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsPasscodePaddle : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsUltraLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsUltraColored : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsUltraDark : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsAdaptiveLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsSemiLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsNoneAdaptive : _UIBackdropViewSettings
@end

@interface UIDeviceRGBColor : UIColor
@end

@interface _UILegibilityLabel : _UILegibilityView
@end

/*extern "C" UIDeviceRGBColor *_UIBackdropViewSettingsColorAcceptGreen();
extern "C" UIDeviceRGBColor *_UIBackdropViewSettingsColorCancelRed();*/
