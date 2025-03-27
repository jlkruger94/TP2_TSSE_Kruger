/************************************************************************************************
Copyright (c) 2024, José Luis Krüger <jlkruger94@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/
/**
 * @file test_leds.c
 * @brief Defines the main function of the program.
 *
 * This file contains the entry point of the program, where the main system logic is executed.
 * It initializes the GPIO pin for controlling a red LED and sets the LED state.
 */

/* === Header files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static uint16_t leds_virtual;
/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @test Con la inicialización todos los LEDs quedan apagados.
 * @test Prender un LED individual.
 * @test Apagar un LED individual.
 * @test Prender y apagar múltiples LED’s.
 * @test Prender todos los LEDs de una vez.
 * @test Apagar todos los LEDs de una vez.
 * @test Consultar el estado de un LED que está encendido
 * @test Consultar el estado de un LED que est apagado
 * @test Revisar limites de los parametros.
 * @test Revisar parámetros fuera de los limites.
 */

/**
 * @brief Main function of the program.
 *
 * This function is executed when the program starts. It initializes a GPIO pin for controlling
 * a red LED and sets its initial state to OFF. The function is the entry point of the program
 * and handles the basic setup required for operation.
 *
 * @return int Returns zero if the program executed successfully, negative if an error occurred.
 */
void test_initial(void) {
    //TEST_FAIL_MESSAGE("Piloto");
}

void setUp(void) {
    leds_init(&leds_virtual);
}

void tearDown(void) {
}

/**
 * @test Después de la inicialización todos los LEDs deben quedar apagados.
 */
void test_Leds_off_after_create(void) {
   leds_virtual = 0xFFFF;
   leds_init(&leds_virtual);
   TEST_ASSERT_EQUAL_HEX16(0, leds_virtual);
}

/**
 *  @test Se puede prender un LED individual.
 */
void test_turn_on_led_one(void) {
   leds_on_single(3);
   TEST_ASSERT_EQUAL_HEX16(4, leds_virtual);
}

/**
 * @test Se puede apagar un LED individual.
 */
void test_turn_off_led_one(void) {
   leds_on_single(2);
   leds_off_single(2);
   TEST_ASSERT_EQUAL_HEX16(0, leds_virtual);
}

/**
 * @test Se pueden prender y apagar múltiples LED’s.
 */
void test_turn_on_off_multiple_leds(void) {
   leds_on_single(8);
   leds_on_single(9);
   leds_off_single(9);
   leds_off_single(8);
   leds_off_single(8);
   TEST_ASSERT_EQUAL_HEX16(0x0, leds_virtual);
}

/**
 *   @test Prender todos los LEDs de una vez.
 */
void test_turn_all_on(void) {
   led_turn_all_on();
   TEST_ASSERT_EQUAL_HEX16(0xFFFF, leds_virtual);   
}

/**
 *  @test Apagar todos los LEDs de una vez.
 */
void test_turn_all_off(void) {
   led_turn_all_off();
   TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtual);   
}

/**
 *  @test Consultar el estado de un LED que está encendido
 */
void test_if_a_led_is_on(void) {
   leds_on_single(5);
   TEST_ASSERT_TRUE(led_is_this_on(5));
   leds_on_single(6);
   leds_off_single(6);
   TEST_ASSERT_FALSE(led_is_this_on(6));
}

/**
 *  @test Consultar el estado de un LED que est apagado
 */
void test_if_a_led_is_off(void) {
   leds_on_single(5);
   leds_off_single(5);
   TEST_ASSERT_TRUE(led_is_this_off(5));
   leds_on_single(6);
   TEST_ASSERT_FALSE(led_is_this_off(6));
}

/**
 * @test Revisar limites de los parametros.
 */
void test_check_led_limits(void) {
   leds_on_single(1);
   leds_on_single(16);
   TEST_ASSERT_TRUE(led_is_this_on(1));
   TEST_ASSERT_TRUE(led_is_this_on(16));
   leds_off_single(1);
   leds_off_single(16);
   TEST_ASSERT_TRUE(led_is_this_off(1));
   TEST_ASSERT_TRUE(led_is_this_off(16));
}

/**
 *  @test Revisar parámetros fuera de los limites.
 * Fuera de rango no se encuentra ni encendido ni apagado
 */
void test_check_led_out_of_limits(void) {
   leds_on_single(0);
   leds_on_single(17);
   leds_on_single(125);

   // No estan encendidos
   TEST_ASSERT_FALSE(led_is_this_on(0));
   TEST_ASSERT_FALSE(led_is_this_on(17));
   TEST_ASSERT_FALSE(led_is_this_on(125));

   leds_off_single(0);
   leds_off_single(17);

   // No estan apagados
   TEST_ASSERT_FALSE(led_is_this_off(0));
   TEST_ASSERT_FALSE(led_is_this_off(17));
   TEST_ASSERT_FALSE(led_is_this_off(125));
}

/* === End of documentation ==================================================================== */
