#include "display7seg.h"

#define DISPLAY1_OFFSET 2
#define DISPLAY2_OFFSET 3
#define DISPLAY3_OFFSET 4
#define DISPLAY4_OFFSET 5

const uint8_t segmentDisplay[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0x3E, 0xE0, 0xFE, 0xE6};
static uint8_t *registro_direccionamientoA;
static uint8_t *registro_direccionamientoB;
static uint8_t *registro_valorA;
static uint8_t *registro_valorB;

void digitOff(void)
{
    *registro_valorA &= 0x0F;
    
    *registro_valorB &= 0xF0;
}

void offAllDisplays(void)
{
    *registro_valorA |= 1 << DISPLAY1_OFFSET;
    *registro_valorA |= 1 << DISPLAY2_OFFSET;
    *registro_valorB |= 1 << DISPLAY3_OFFSET;
    *registro_valorB |= 1 << DISPLAY4_OFFSET;
}

void onAllDisplays(void)
{
    *registro_valorA &= ~(1 << DISPLAY1_OFFSET);
    *registro_valorA &= ~(1 << DISPLAY2_OFFSET);
    *registro_valorB &= ~(1 << DISPLAY3_OFFSET);
    *registro_valorB &= ~(1 << DISPLAY4_OFFSET);
}

void onSingleDisplay(uint8_t display)
{
    switch (display)
    {
    case 1:
        *registro_valorA &= ~(1 << DISPLAY1_OFFSET);
        *registro_valorA |= 1 << DISPLAY2_OFFSET;
        *registro_valorB |= 1 << DISPLAY3_OFFSET;
        *registro_valorB |= 1 << DISPLAY4_OFFSET;
        break;

    case 2:
        *registro_valorA |= 1 << DISPLAY1_OFFSET;
        *registro_valorA &= ~(1 << DISPLAY2_OFFSET);
        *registro_valorB |= 1 << DISPLAY3_OFFSET;
        *registro_valorB |= 1 << DISPLAY4_OFFSET;
        break;

    case 3:
        *registro_valorA |= 1 << DISPLAY1_OFFSET;
        *registro_valorA |= 1 << DISPLAY2_OFFSET;
        *registro_valorB &= ~(1 << DISPLAY3_OFFSET);
        *registro_valorB |= 1 << DISPLAY4_OFFSET;
        break;

    case 4:
        *registro_valorA |= 1 << DISPLAY1_OFFSET;
        *registro_valorA |= 1 << DISPLAY2_OFFSET;
        *registro_valorB |= 1 << DISPLAY3_OFFSET;
        *registro_valorB &= ~(1 << DISPLAY4_OFFSET);
        break;

    default:
        *registro_valorA |= 1 << DISPLAY1_OFFSET;
        *registro_valorA |= 1 << DISPLAY2_OFFSET;
        *registro_valorB |= 1 << DISPLAY3_OFFSET;
        *registro_valorB |= 1 << DISPLAY4_OFFSET;
        break;
    }
}

void initDisplay(uint8_t *direccion_reg_dirA, uint8_t *direccion_reg_dirB, uint8_t *direccion_reg_valA, uint8_t *direccion_reg_valB)
{
    registro_direccionamientoA = direccion_reg_dirA;
    registro_direccionamientoB = direccion_reg_dirB;
    registro_valorA = direccion_reg_valA;
    registro_valorB = direccion_reg_valB;

    *registro_direccionamientoA |= 0xFC;
    *registro_direccionamientoB |= 0x3F;

    *registro_valorA &= 0x0F;
    *registro_valorA |= 0x0C;
    
    *registro_valorB &= 0xF0;
    *registro_valorB |= 0x30;
}

void digOnDisplays(uint8_t digit)
{
    digitOff();
    *registro_valorA |= (segmentDisplay[digit] & 0xF0);
    *registro_valorB |= (segmentDisplay[digit] & 0x0F);
}

void digOnDisplayAndShow(uint8_t digit, uint8_t display)
{
    digitOff();
    offAllDisplays();
    *registro_valorA |= (segmentDisplay[digit] & 0xF0);
    *registro_valorB |= (segmentDisplay[digit] & 0x0F);
    onSingleDisplay(display);
}