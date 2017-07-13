#import <UIKit/UIKit.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>

@interface PSSliderTableCell : PSTableCell
- (UIControl *)control;
@end

__attribute__((visibility("hidden")))
@interface RandomyPreferenceController : PSListController <UIActionSheetDelegate> {}
@end

@implementation RandomyPreferenceController

- (void)twt:(id)param
{
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"twitter://user?screen_name=PoomSmart"]];
}

- (void)donate:(id)param
{
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=GBQGZL8EFMM86"]];
}

- (void)setInput:(id)value specifier:(PSSpecifier *)spec
{
	NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
	if ([formatter numberFromString:(NSString *)value] != nil) {
		float floatValue = [value floatValue];
		if (floatValue < 0)
			value = @0;
	} else
		value = @0;
	[formatter release];
	[self setPreferenceValue:value specifier:spec];
	[[NSUserDefaults standardUserDefaults] synchronize];
	[self reloadSpecifier:spec animated:NO];
}

- (void)buttonPressed
{
	UIActionSheet *sheet = [[UIActionSheet alloc] initWithTitle:nil delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:
		@"❄ Respring",
		@"⬇ Hide KB",
		nil];
	sheet.tag = 95969598;
	[sheet showInView:self.view];
	[sheet release];
}

- (void)actionSheet:(UIActionSheet *)popup clickedButtonAtIndex:(NSInteger)buttonIndex
{
	if (popup.tag == 95969598) {
		switch (buttonIndex) {
			case 0:
				[[super view] endEditing:YES];
				system("killall SpringBoard");
				break;
			case 1:
				[[super view] endEditing:YES];
				break;
		}
	}
}

- (void)addBtn
{
	UIBarButtonItem *btn = [[UIBarButtonItem alloc]
        initWithTitle:@"⭕" style:UIBarButtonItemStyleBordered
        target:self action:@selector(buttonPressed)];
	((UINavigationItem *)[super navigationItem]).rightBarButtonItem = btn;
	[btn release];
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	[self addBtn];
}

- (NSArray *)specifiers
{
	if (_specifiers == nil) {
		NSMutableArray *specs = [NSMutableArray arrayWithArray:[self loadSpecifiersFromPlistName:@"Randomy" target:self]];
        _specifiers = [specs copy];
	}
	return _specifiers;
}

@end

@interface RandomySliderTableCell : PSSliderTableCell
@end

@implementation RandomySliderTableCell

- (id)initWithStyle:(int)style reuseIdentifier:(NSString *)identifier specifier:(PSSpecifier *)spec
{
	self = [super initWithStyle:style reuseIdentifier:identifier specifier:spec]; 
	if (self) {
		UIColor *color = [UIColor grayColor];
		CGRect rect = CGRectMake(0, 0, 1, 2);
    	UIGraphicsBeginImageContextWithOptions(rect.size, NO, 0);
    	CGContextRef context = UIGraphicsGetCurrentContext();
    	CGContextSetFillColorWithColor(context, [color CGColor]);
    	CGContextFillRect(context, rect);
    	UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    	UIGraphicsEndImageContext();
		[((UISlider *)[self control]) setMinimumTrackImage:image forState:UIControlStateNormal];
		[((UISlider *)[self control]) setMaximumTrackImage:image forState:UIControlStateNormal];
	}
	return self;
}

@end
