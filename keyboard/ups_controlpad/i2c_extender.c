#include <avr/io.h>
#include <util/twi.h> 
#include "i2c_extender.h"

void TWIInit(void)
{
    //set SCL to 400kHz
    TWSR = 0x00;
    TWBR = 0x48;
    //enable TWI
    TWCR = (1<<TWEN);
}

void TWIStart(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}

void TWIStop(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWIWrite(uint8_t u8data)
{
    TWDR = u8data;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}

uint8_t TWIReadACK(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while ((TWCR & (1<<TWINT)) == 0);
    return TWDR;
}

uint8_t TWIGetStatus(void)
{
    uint8_t status;
    //mask status
    status = TWSR & 0xF8;
    return status;
}

uint8_t EEWriteByte(uint16_t u16addr, uint8_t u8data)
{
    TWIStart();
    if (TWIGetStatus() != 0x08)
        return ERROR;
    //select devise and send A2 A1 A0 address bits
    TWIWrite((EEDEVADR)|(uint8_t)((u16addr & 0x0700)>>7));
    if (TWIGetStatus() != 0x18)
        return ERROR;  
    //send the rest of address
    TWIWrite((uint8_t)(u16addr));
    if (TWIGetStatus() != 0x28)
        return ERROR;
    //write byte to eeprom
    TWIWrite(u8data);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    TWIStop();
    return SUCCESS;
}

//8574TS