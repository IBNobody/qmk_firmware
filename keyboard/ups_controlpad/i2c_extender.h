
void TWIInit(void);
void TWIStart(void);
void TWIStop(void);
void TWIWrite(uint8_t u8data);
uint8_t TWIReadACK(void);
uint8_t TWIGetStatus(void);
uint8_t EEWriteByte(uint16_t u16addr, uint8_t u8data);