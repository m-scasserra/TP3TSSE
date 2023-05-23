#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

#include <stdint.h>
#include <stdbool.h>

//const uint8_t segmentDisplay[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0x3E, 0xE0, 0xFE, 0xE6};
void digitOff(void);
void digOnDisplays(uint8_t digit);
void digOnDisplayAndShow(uint8_t digit, uint8_t display);
void offAllDisplays(void);
void onAllDisplays(void);
void onSingleDisplay(uint8_t display);
void initDisplay(uint8_t *direccion_reg_dirA, uint8_t *direccion_reg_dirB, uint8_t *direccion_reg_valA, uint8_t *direccion_reg_valB);


#endif