#ifndef _string_provider_h
#define _string_provider_h

#include "LanguageOptions.h"
#include <stdint.h>

class StringProvider{
    public:

    StringProvider(LanguageOption lang);
    const char * GetLocalizedString(const char* key);

    private:
    LanguageOption _lang;
    uint8_t _localizedKeyStartingIndex;
};

#endif