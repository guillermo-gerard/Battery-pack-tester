#include "StringProvider.h"
#include "L10nStringDefinitions.h"
#include <string.h>
#include <Arduino.h>
#include <avr/pgmspace.h>

StringProvider::StringProvider(LanguageOption lang){
    this->SetLanguage(lang); 
}

void StringProvider::SetLanguage(LanguageOption option){
    _lang = option;
    _localizedKeyStartingIndex = _lang == LanguageOption::ENGLISH ? 0 : ((uint8_t)StringKeys::NUMBER_OF_STRINGS);
}

//const char * 
void StringProvider::GetLocalizedString(StringKeys key, char * _buffer){
    strcpy_P(_buffer, (char *)pgm_read_word(&(_strings[_localizedKeyStartingIndex + (uint8_t)key])));
}