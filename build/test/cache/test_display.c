#include "inc/display7seg.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static uint8_t registro_direccionamientoA;

static uint8_t registro_direccionamientoB;

static uint8_t registro_valorA;

static uint8_t registro_valorB;



void setUp(void)

{

    initDisplay(&registro_direccionamientoA, &registro_direccionamientoB, &registro_valorA, &registro_valorB);

}







void test_todos_registros_configuradors_correctamente(void)

{

    registro_direccionamientoA = 0;

    registro_direccionamientoB = 0;

    registro_valorA = 0;

    registro_valorB = 0;



    initDisplay(&registro_direccionamientoA, &registro_direccionamientoB, &registro_valorA, &registro_valorB);



    UnityAssertEqualNumber((UNITY_INT)((0xFC)), (UNITY_INT)((registro_direccionamientoA)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x3F)), (UNITY_INT)((registro_direccionamientoB)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x0C)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x30)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_mostrar_un_numero(void)

{

    digOnDisplays(7);



    UnityAssertEqualNumber((UNITY_INT)((0xEC)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x30)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}







void test_encender_display3_apagar_display3_encender_display4(void)

{

    digitOff();

    onSingleDisplay(3);

    offAllDisplays();

    onSingleDisplay(4);

    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (3))), (UNITY_INT)((UNITY_UINT)(-1)), (UNITY_INT)((registro_direccionamientoA)), (

   ((void *)0)

   ), (UNITY_UINT)(51));

    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (4))), (UNITY_INT)((UNITY_UINT)(-1)), (UNITY_INT)((registro_direccionamientoA)), (

   ((void *)0)

   ), (UNITY_UINT)(52));

    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (5))), (UNITY_INT)((UNITY_UINT)(-1)), (UNITY_INT)((registro_direccionamientoB)), (

   ((void *)0)

   ), (UNITY_UINT)(53));

    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (6))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((registro_direccionamientoB)), (

   ((void *)0)

   ), (UNITY_UINT)(54));

}







void test_encender_digito1_pasar_a_digito8(void)

{

    offAllDisplays();

    digOnDisplays(1);

    digOnDisplays(8);

    UnityAssertEqualNumber((UNITY_INT)((0xFC)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x3E)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);



}









void test_mostrar_diferentes_en_todos_los_segmentos(void)

{

    offAllDisplays();

    digOnDisplayAndShow(1,1);

    UnityAssertEqualNumber((UNITY_INT)((0x68)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x30)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);



    digOnDisplayAndShow(2,2);

    UnityAssertEqualNumber((UNITY_INT)((0xD4)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x3A)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);



    digOnDisplayAndShow(3,3);

    UnityAssertEqualNumber((UNITY_INT)((0xFC)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x22)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);



    digOnDisplayAndShow(4,4);

    UnityAssertEqualNumber((UNITY_INT)((0x6C)), (UNITY_INT)((registro_valorA)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0x16)), (UNITY_INT)((registro_valorB)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}
