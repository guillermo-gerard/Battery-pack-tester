#ifndef _l10n_string_definitions_h
#define _l10n_string_definitions_h
#include <Arduino.h>

enum class StringKeys{
    MANUFACTURER = 0,
    DEVICE,
    CHEMISTRY,
    DESIGNCAPACITY,
    DESIGNVOLTAGE,
    MANUFACTUREDATE,
    SERIALNUMBER,
    SPECIFICATIONINFO,
    CYCLECOUNT,
    CURRENTVOLTAGE,
    FULLCHARGECAPACITY,
    REMAININGCAPACITY,
    RELATIVECHARGE,
    ABSOLUTECHARGE,
    MINUTESREMAININGTOFULLCHARGE,
    CELL1V,
    CELL2V,
    CELL3V,
    CELL4V,
    STATEHEALTH,
    BATMODE,
    BATSTATUS,
    CHARGINGCURRENT,
    CHARGINGV,
    TEMP,
    CURRENTMA,
    NUMBER_OF_STRINGS,
};
//This should be longer than the longest string among all the localized strings 
const unsigned int _maxStringLengh = 41;

const char string_0_EN[] PROGMEM = "Manufacturer Name: "; 
const char string_1_EN[] PROGMEM = "Device Name: ";
const char string_2_EN[] PROGMEM = "Chemistry: ";
const char string_3_EN[] PROGMEM = "Design Capacity: ";
const char string_4_EN[] PROGMEM = "Design Voltage:";
const char string_5_EN[] PROGMEM = "Manufacture Date (Y-M-D): ";
const char string_6_EN[] PROGMEM = "Serial Number: ";
const char string_7_EN[] PROGMEM = "Specification Info: ";
const char string_8_EN[] PROGMEM = "Cycle Count: ";
const char string_9_EN[] PROGMEM = "Voltage: ";
const char string_10_EN[] PROGMEM = "Full Charge Capacity: ";
const char string_11_EN[] PROGMEM = "Remaining Capacity: ";
const char string_12_EN[] PROGMEM = "Relative Charge(%): ";
const char string_13_EN[] PROGMEM = "Absolute Charge(%): ";
const char string_14_EN[] PROGMEM = "Minutes remaining for full charge: ";
const char string_15_EN[] PROGMEM = "Cell 1 Voltage: ";
const char string_16_EN[] PROGMEM = "Cell 2 Voltage: ";
const char string_17_EN[] PROGMEM = "Cell 3 Voltage: ";
const char string_18_EN[] PROGMEM = "Cell 4 Voltage: ";
const char string_19_EN[] PROGMEM = "State of Health: ";
const char string_20_EN[] PROGMEM = "Battery Mode (BIN): 0b";
const char string_21_EN[] PROGMEM = "Battery Status (BIN): 0b";
const char string_22_EN[] PROGMEM = "Charging Current: ";
const char string_23_EN[] PROGMEM = "Charging Voltage: ";
const char string_24_EN[] PROGMEM = "Temp: ";
const char string_25_EN[] PROGMEM = "Current (mA): ";

const char string_0_ES[] PROGMEM = "Fabricante: ";
const char string_1_ES[] PROGMEM = "Dispositivo: ";
const char string_2_ES[] PROGMEM = "Química: ";
const char string_3_ES[] PROGMEM = "Capacidad de diseño: ";
const char string_4_ES[] PROGMEM = "Voltaje de diseño: ";
const char string_5_ES[] PROGMEM = "Fecha de fabricación (A-M-D): ";
const char string_6_ES[] PROGMEM = "Número de serie: ";
const char string_7_ES[] PROGMEM = "Información de la especificación: ";
const char string_8_ES[] PROGMEM = "Conteo de ciclos: ";
const char string_9_ES[] PROGMEM = "Voltaje: ";
const char string_10_ES[] PROGMEM = "Capacidad de carga completa: ";
const char string_11_ES[] PROGMEM = "Carga restante: ";
const char string_12_ES[] PROGMEM = "Carga relativa(%): ";
const char string_13_ES[] PROGMEM = "Carga absoluta(%): ";
const char string_14_ES[] PROGMEM = "Minutos restantes para carga completa: ";
const char string_15_ES[] PROGMEM = "Voltaje de celda 1: ";
const char string_16_ES[] PROGMEM = "Voltaje de celda 2: ";
const char string_17_ES[] PROGMEM = "Voltaje de celda 3: ";
const char string_18_ES[] PROGMEM = "Voltaje de celda 4: ";
const char string_19_ES[] PROGMEM = "Salud del pack: ";
const char string_20_ES[] PROGMEM = "Modo de batería (BIN): 0b";
const char string_21_ES[] PROGMEM = "Estado de la batería (BIN): 0b";
const char string_22_ES[] PROGMEM = "Corriente de carga: ";
const char string_23_ES[] PROGMEM = "Voltaje de carga: ";
const char string_24_ES[] PROGMEM = "Temperatura: ";
const char string_25_ES[] PROGMEM = "Corriente (mA): "; 

const char *const _strings[] PROGMEM = {
    string_0_EN, string_1_EN, string_2_EN, string_3_EN, string_4_EN, 
    string_5_EN, string_6_EN, string_7_EN, string_8_EN, string_9_EN, 
    string_10_EN, string_11_EN, string_12_EN, string_13_EN, string_14_EN,
    string_15_EN, string_16_EN, string_17_EN, string_18_EN, string_19_EN, 
    string_20_EN, string_21_EN, string_22_EN, string_23_EN, string_24_EN, 
    string_25_EN,
    string_0_ES, string_1_ES, string_2_ES, string_3_ES, string_4_ES, 
    string_5_ES, string_6_ES, string_7_ES, string_8_ES, string_9_ES, 
    string_10_ES, string_11_ES, string_12_ES, string_13_ES, string_14_ES,
    string_15_ES, string_16_ES, string_17_ES, string_18_ES, string_19_ES, 
    string_20_ES, string_21_ES, string_22_ES, string_23_ES, string_24_ES, 
    string_25_ES
    };

#endif