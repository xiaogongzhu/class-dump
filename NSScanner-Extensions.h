#import <Foundation/NSScanner.h>

#import <Foundation/NSString.h> // for unichar

@interface NSScanner (CDExtensions)

- (BOOL)scanCharacter:(unichar *)value;
- (BOOL)scanCharacterFromSet:(NSCharacterSet *)set intoString:(NSString **)value;

@end