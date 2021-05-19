/*
Based on: https://powercartel.com/projects/packprobe/ , but customized to build using the platformio project
structure and to use an Arduino NANO

NOTES:
-Connection to battery:
  You must handle LI-ION batteries with extreme caution. DO NOT connect anything if you are not sure about the risks!
  You can expect that every battery have a different pinout. 
  You can found most of them by googling it.
  Even when you found the pinout for a battery given battery, you should perform some basic tests, 
  like measuring the output of the pack with a multimeter, to be sure you found the correct diagram.
  Some batteries will need a resistor to simulate the laptop (usually referred as SYSTEM PRESENT/SP or BATTERY ENABLE/BE).
  If needed, it is something like 1Kohm.
  Usually, the batteries have placed the power output in the outer pins. f.e: you can found the plus on the rightmost pins
  and the minus on the other side
  Another test will be to measure pins in the middle (where the I2C signal is usually placed) against the minus terminal/s,
  You should obtain something around 0.5/1Meg

-Connections to the microcontroller board:
  Of course, you have to connect the GND's togheter
  Then, you can connect the BE (or SP) resistor, if needed
  Then you can safely attach the SDA ans SCL signals.
  On the arduino side, both pins have pullup resistors (10K) and that's it       
*/

#include <Arduino.h>
#include "LanguageOptions.h"
#include "StringProvider.h"
#include "Commands.h"
#include "L10nStringDefinitions.h"

#define SDA_PORT PORTC
#define SDA_PIN 4

#define SCL_PORT PORTC
#define SCL_PIN 5

#define I2C_SLOWMODE 1
#define bufferLen 32

// standard I2C address for Smart Battery packs
byte deviceAddress = 11;

//this should be included here, after the port and pin definitions
#include <SoftI2CMaster.h>

//You can change the language here. Available translations: English, Spanish
StringProvider stringProvider(LanguageOption::ENGLISH);
uint8_t i2cBuffer[bufferLen];
char buffer[_maxStringLengh];

void scan();
uint8_t i2c_smbus_read_block ( uint8_t command, uint8_t* blockBuffer, uint8_t blockBufferLen );
int fetchWord(byte func);
void print(StringKeys key);

void setup()
{
  Serial.begin(115200);  
  Serial.println(i2c_init());
  pinMode(A4 ,INPUT_PULLUP);
  pinMode(A5 ,INPUT_PULLUP);
  
  i2c_init();
  scan();
}

void loop()
{
  uint8_t length_read = 0;

  print(StringKeys::MANUFACTURER);
  length_read = i2c_smbus_read_block(MFG_NAME, i2cBuffer, bufferLen);
  Serial.write(i2cBuffer, length_read);
  Serial.println("");
  
  print(StringKeys::DEVICE);
  length_read = i2c_smbus_read_block(DEV_NAME, i2cBuffer, bufferLen);
  Serial.write(i2cBuffer, length_read);
  Serial.println("");
  
  print(StringKeys::CHEMISTRY);
  length_read = i2c_smbus_read_block(CELL_CHEM, i2cBuffer, bufferLen);
  Serial.write(i2cBuffer, length_read);
  Serial.println("");
  
  print(StringKeys::DESIGNCAPACITY);
  Serial.println(fetchWord(DESIGN_CAPACITY));
  
  print(StringKeys::DESIGNVOLTAGE);
  Serial.println(fetchWord(DESIGN_VOLTAGE));
  
  stringProvider.GetLocalizedString(StringKeys::MANUFACTUREDATE, buffer);
  String formatted_date = buffer;
  //formatted_date.trim();
  int mdate = fetchWord(MFG_DATE);
  int mday = B00011111 & mdate;
  int mmonth = mdate>>5 & B00001111;
  int myear = 1980 + (mdate>>9 & B01111111);
  formatted_date += myear;
  formatted_date += "-";
  formatted_date += mmonth;
  formatted_date += "-";
  formatted_date += mday;
  Serial.println(formatted_date);

  print(StringKeys::SERIALNUMBER);
  Serial.println(fetchWord(SERIAL_NUM));

  print(StringKeys::SPECIFICATIONINFO);
  Serial.println(fetchWord(SPEC_INFO));
 
  print(StringKeys::CYCLECOUNT);
  Serial.println(fetchWord(CYCLE_COUNT));
  
  print(StringKeys::CURRENTVOLTAGE);
  Serial.println((float)fetchWord(VOLTAGE)/1000);

  print(StringKeys::FULLCHARGECAPACITY);
  Serial.println(fetchWord(FULL_CHARGE_CAPACITY));
  
  print(StringKeys::REMAININGCAPACITY);
  Serial.println(fetchWord(REMAINING_CAPACITY));

  print(StringKeys::RELATIVECHARGE);
  Serial.println(fetchWord(RELATIVE_SOC));
  
  print(StringKeys::ABSOLUTECHARGE);
  Serial.println(fetchWord(ABSOLUTE_SOC));
  
  print(StringKeys::MINUTESREMAININGTOFULLCHARGE);
  Serial.println(fetchWord(TIME_TO_FULL));
  // These aren't part of the standard, but work with some packs.
  // They don't work with the Lenovo and Dell packs we've tested
  print(StringKeys::CELL1V); 
  Serial.println(fetchWord(CELL1_VOLTAGE));
  print(StringKeys::CELL2V); 
  Serial.println(fetchWord(CELL2_VOLTAGE));
  print(StringKeys::CELL3V); 
  Serial.println(fetchWord(CELL3_VOLTAGE));
  print(StringKeys::CELL4V); 
  Serial.println(fetchWord(CELL4_VOLTAGE));
  
  print(StringKeys::STATEHEALTH); 
  Serial.println(fetchWord(STATE_OF_HEALTH));

  print(StringKeys::BATMODE); 
  Serial.println(fetchWord(BATTERY_MODE),BIN);

  print(StringKeys::BATSTATUS); 
  Serial.println(fetchWord(BATTERY_STATUS),BIN);
  
  print(StringKeys::CHARGINGCURRENT); 
  Serial.println(fetchWord(CHARGING_CURRENT));
  
  print(StringKeys::CHARGINGV); 
  Serial.println(fetchWord(CHARGING_VOLTAGE));

  print(StringKeys::TEMP); 
  unsigned int tempk = fetchWord(TEMPERATURE);
  Serial.println((float)tempk/10.0-273.15);

  print(StringKeys::CURRENTMA); 
  Serial.println(fetchWord(CURRENT));
  
  Serial.println(".");
  delay(10000);
}

void print(StringKeys key){
  stringProvider.GetLocalizedString(key, buffer);
  Serial.print(buffer);
}

int fetchWord(byte func)
{
  i2c_start(deviceAddress<<1 | I2C_WRITE);
  i2c_write(func);
  i2c_rep_start(deviceAddress<<1 | I2C_READ);
  byte b1 = i2c_read(false);
  byte b2 = i2c_read(true);
  i2c_stop();
  return (int)b1|((( int)b2)<<8);
}

uint8_t i2c_smbus_read_block ( uint8_t command, uint8_t* blockBuffer, uint8_t blockBufferLen ) 
{
  uint8_t x, num_bytes;
  i2c_start((deviceAddress<<1) + I2C_WRITE);
  i2c_write(command);
  i2c_rep_start((deviceAddress<<1) + I2C_READ);
  num_bytes = i2c_read(false); // num of bytes; 1 byte will be index 0
  num_bytes = constrain(num_bytes,0,blockBufferLen-2); // room for null at the end
  for (x=0; x<num_bytes-1; x++) { // -1 because x=num_bytes-1 if x<y; last byte needs to be "nack"'d, x<y-1
    blockBuffer[x] = i2c_read(false);
  }
  blockBuffer[x++] = i2c_read(true); // this will nack the last byte and store it in x's num_bytes-1 address.
  blockBuffer[x] = 0; // and null it at last_byte+1
  i2c_stop();
  return num_bytes;
}

void scan()
{
  byte i = 0;
  for ( i= 0; i < 127; i++  )
  {
    Serial.print("Address: 0x");
    Serial.print(i,HEX);
    bool ack = i2c_start(i<<1 | I2C_WRITE); 
    if ( ack ) {
      Serial.println(": OK");
      Serial.flush();
    }
    else {
      Serial.println(": -");
      Serial.flush();      
    }
    i2c_stop();
  }
}