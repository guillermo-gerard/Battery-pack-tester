#ifndef _string_provider_h
#define _string_provider_h

#include "LanguageOptions.h"
#include "L10nStringDefinitions.h"
#include <stdint.h>

class StringProvider{
    public:

    StringProvider(LanguageOption lang);
    void SetLanguage(LanguageOption option);
    void GetLocalizedString(StringKeys key, char * _buffer);

    private:
    LanguageOption _lang;
    uint8_t _localizedKeyStartingIndex;
};

#endif