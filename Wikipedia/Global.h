
#ifndef Wikipedia_Global_h
#define Wikipedia_Global_h

#import "WMFLogging.h"
#import "WMFGCDHelpers.h"

#import <libextobjc/EXTScope.h>

#import "MediaWikiKit.h"
#import "WMFArticlePresenter.h"

static inline NSString* localizedStringForKeyFallingBackOnEnglish(NSString* key){
    NSString* outStr = NSLocalizedString(key, nil);
    if (![outStr isEqualToString:key]) {
        return outStr;
    }

    static NSBundle* englishBundle = nil;

    if (!englishBundle) {
        NSString* path = [[NSBundle mainBundle] pathForResource:@"en" ofType:@"lproj"];
        englishBundle = [NSBundle bundleWithPath:path];
    }
    return [englishBundle localizedStringForKey:key value:@"" table:nil];
}

#define MWLocalizedString(key, throwaway) localizedStringForKeyFallingBackOnEnglish(key)

#endif