#include "StringProvider.h"
#include "Keys.h"
#include <string.h>
#include <Arduino.h>

StringProvider::StringProvider(LanguageOption lang){
    _lang = lang;
    
    _localizedKeyStartingIndex = _lang == LanguageOption::SPANISH ? 0 : _numberOfStrings;
    Serial.println(_numberOfStrings);
}

const char * StringProvider::GetLocalizedString(const char* key){

    Serial.print("key: ");
    Serial.println(key);

    for(int i = 0; i < _numberOfStrings; ++i)
    {
        Serial.print("_key[i]: ");
        Serial.println(_keys[i]);
        if(!strcmp(_keys[i], key))
        {
            return _strings[_localizedKeyStartingIndex + i]; 
        }
    }
    return "string not found";
}