#import "FSSwitchDataSource.h"
#import "FSSwitchPanel.h"

@interface RandomyToggleSwitch : NSObject <FSSwitchDataSource>
@end

@interface NSUserDefaults (Randomy)
- (id)objectForKey:(NSString *)key inDomain:(NSString *)domain;
- (void)setObject:(id)value forKey:(NSString *)key inDomain:(NSString *)domain;
@end

@implementation RandomyToggleSwitch

- (FSSwitchState)stateForSwitchIdentifier:(NSString *)switchIdentifier
{
	return _AXSEnhanceBackgroundContrastEnabled() ? FSSwitchStateOn : FSSwitchStateOff;
}

- (void)applyState:(FSSwitchState)newState forSwitchIdentifier:(NSString *)switchIdentifier
{
	if (newState == FSSwitchStateIndeterminate)
		return;
	_AXSSetEnhanceBackgroundContrastEnabled(newState == FSSwitchStateOn);
}

@end
