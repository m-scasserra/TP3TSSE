#include "unity.h"

#include <stdint.h>
#include <stdbool.h>
#include "display7seg.h"

static uint8_t registro_direccionamientoA;
static uint8_t registro_direccionamientoB;
static uint8_t registro_valorA;
static uint8_t registro_valorB;

void setUp(void)
{
    initDisplay(&registro_direccionamientoA, &registro_direccionamientoB, &registro_valorA, &registro_valorB);
}

// Al iniciar la biblioteca, todos los segmentos tienen que estar apagados y todos los registros de direccionamiento con
// configurados correctamente
void test_todos_registros_configuradors_correctamente(void)
{
    registro_direccionamientoA = 0;
    registro_direccionamientoB = 0;
    registro_valorA = 0;
    registro_valorB = 0;

    initDisplay(&registro_direccionamientoA, &registro_direccionamientoB, &registro_valorA, &registro_valorB);

    TEST_ASSERT_EQUAL(0xFC, registro_direccionamientoA);
    TEST_ASSERT_EQUAL(0x3F, registro_direccionamientoB);
    TEST_ASSERT_EQUAL(0x0C, registro_valorA);
    TEST_ASSERT_EQUAL(0x30, registro_valorB);
}

// Con todos los segmentos apagados mostrar un 7
void test_prender_y_mostrar_un_numero(void)
{
    digOnDisplays(7);

    TEST_ASSERT_EQUAL(0xEC, registro_valorA);
    TEST_ASSERT_EQUAL(0x30, registro_valorB);
}

// Con todos los displays apagados, encender el display numero 3, apagarlo y encender el display 4

void test_encender_display3_apagar_display3_encender_display4(void)
{
    digitOff();
    onSingleDisplay(3);
    offAllDisplays();
    onSingleDisplay(4);
    TEST_ASSERT_BIT_HIGH(3, registro_direccionamientoA);
    TEST_ASSERT_BIT_HIGH(4, registro_direccionamientoA);
    TEST_ASSERT_BIT_HIGH(5, registro_direccionamientoB);
    TEST_ASSERT_BIT_LOW(6, registro_direccionamientoB);
}

// Con todos los diplays apagados, mostrar el digito 1 y despues mostrar el digito 8

void test_encender_digito1_pasar_a_digito8(void)
{
    offAllDisplays();
    digOnDisplays(1);
    digOnDisplays(8);
    TEST_ASSERT_EQUAL(0xFC, registro_valorA);
    TEST_ASSERT_EQUAL(0x3E, registro_valorB);

}

// Con todos los segmentos y digitos apagados mostrar el digito 1 en el segmento 1, el digito 2 en el segmento 2
// el digito 3 en el segmento 3 y el digito 4 en el segmento 4

void test_mostrar_diferentes_en_todos_los_segmentos(void)
{
    offAllDisplays();
    digOnDisplayAndShow(1,1);
    TEST_ASSERT_EQUAL(0x68, registro_valorA);
    TEST_ASSERT_EQUAL(0x30, registro_valorB);

    digOnDisplayAndShow(2,2);
    TEST_ASSERT_EQUAL(0xD4, registro_valorA);
    TEST_ASSERT_EQUAL(0x3A, registro_valorB);

    digOnDisplayAndShow(3,3);
    TEST_ASSERT_EQUAL(0xFC, registro_valorA);
    TEST_ASSERT_EQUAL(0x22, registro_valorB);

    digOnDisplayAndShow(4,4);
    TEST_ASSERT_EQUAL(0x6C, registro_valorA);
    TEST_ASSERT_EQUAL(0x16, registro_valorB);
}