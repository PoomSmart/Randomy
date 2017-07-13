SDKVERSION = 7.0
GO_EASY_ON_ME = 1
ARCHS = armv7 armv7s arm64

include theos/makefiles/common.mk
TWEAK_NAME = Randomy
Randomy_FILES = Tweak.xm
Randomy_FRAMEWORKS = CoreGraphics QuartzCore UIKit
Ramdomy_PRIVATE_FRAMEWORKS = SpringBoardFoundation

include $(THEOS_MAKE_PATH)/tweak.mk

BUNDLE_NAME = RandomySettings
RandomySettings_FILES = RandomyPreferenceController.m
RandomySettings_INSTALL_PATH = /Library/PreferenceBundles
RandomySettings_PRIVATE_FRAMEWORKS = Preferences
RandomySettings_FRAMEWORKS = CoreImage CoreGraphics UIKit

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/Randomy.plist$(ECHO_END)
	$(ECHO_NOTHING)find $(THEOS_STAGING_DIR) -name .DS_Store | xargs rm -rf$(ECHO_END)

