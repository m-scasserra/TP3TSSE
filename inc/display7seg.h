/** @file display7seg.h
 * 
 * @brief Es una libreria para control de 4 displats de 7 segmentos multiplexados
 *        a los mismos pines de salida de 2 puertos distintos de un microcontrolador.
 *        Las conexiones son las siguientes
 *          seg a  -> Port D7
 *          seg b  -> Port D6
 *          seg c  -> Port D5
 *          seg d  -> Port D4
 *          seg e  -> Port B3
 *          seg f  -> Port B2
 *          seg g  -> Port B1
 *          seg dp -> Port B0
 *          CC1    -> Port D3
 *          CC2    -> Port D2
 *          CC2    -> Port B4
 *          CC2    -> Port B5
 *        Debido a que los pines D1, D0, B6 y B7 estan reservados para otras tareas
 *        las funciones en esta libreria solo modifican los bits necesarios para no
 *        modificar los datos anteriormente ubicados en estas posiciones.
 *        Esta libreria esta pensanda para su uso con un microcontrolador AtMega 328p
 *        cuyo tamaño de registros de 8 bits.
 */ 

#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

#include <stdint.h>
#include <stdbool.h>

//const uint8_t segmentDisplay[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0x3E, 0xE0, 0xFE, 0xE6};
/**
 * Apaga los segmentos del display sin modificar el valor de los catodos comunes.
 *
 * @param void
 * @return void
 */
void digitOff(void);

/**
 * Prende los segmentos del display al numero especificado sin modificar el valor de los catodos comunes.
 *
 * @param uint8_t digit valor numerico del digito a mostrar, de 0 a 9.
 * @return void
 */
void digOnDisplays(uint8_t digit);

/**
 * Prende los segmentos del display y modifica el valor de los catodos comunes para mostrarlo en un display
 * especifico.
 *
 * @param uint8_t digit valor numerico del digito a mostrar, de 0 a 9.
 * @param uint8_t display valor numerico del display donde se muestra el digito, de 1 a 4.
 * @return void
 */
void digOnDisplayAndShow(uint8_t digit, uint8_t display);

/**
 * Apaga los catodos comunes de todos los displays, sin modificar los valores de los segmentos.
 *
 * @param void
 * @return void
 */
void offAllDisplays(void);

/**
 * Prende los catodos comunes de todos los displays, sin modificar los valores de los segmentos.
 *
 * @param void
 * @return void
 */
void onAllDisplays(void);

/**
 * Prende el catodo comun de un display especifico y apaga el deel resto de los catodos comunes,
 * sin modificar los valores de los segmentos.
 *
 * @param uint8_t display valor numerico del display que se encienda, de 1 a 4.
 * @return void
 */
void onSingleDisplay(uint8_t display);

/**
 * Inicializa el registro de direccionamiento de datos de los dos puertos IO e inicaliza con todos
 * los segmentos de los displays y los catodos comunes apagados.
 *
 * @param uint_8t *direccion_reg_dirA puntero a la direccion del registro de direccionamiento del puerto A
 * @param uint_8t *direccion_reg_dirB puntero a la direccion del registro de direccionamiento del puerto B
 * @param uint_8t *direccion_reg_valA puntero a la direccion del registro de valor de salida del puerto A
 * @param uint_8t *direccion_reg_valB puntero a la direccion del registro de valor de salida del puerto B
 * @return void
 */
void initDisplay(uint8_t *direccion_reg_dirA, uint8_t *direccion_reg_dirB, uint8_t *direccion_reg_valA, uint8_t *direccion_reg_valB);


#endif