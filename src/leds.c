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
 * @file leds.c
 * @brief Implementación del control de un puerto de LEDs.
 *
 * Este módulo permite inicializar, encender, apagar y consultar el estado
 * de LEDs.
 */

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

#define ALL_LEDS_OFF       0x0000 /**< Máscara para apagar todos los LEDs */
#define ALL_LEDS_ON        0xFFFF /**< Máscara para encender todos los LEDs */
#define LEDS_TO_BIT_OFFSET 1      /**< Offset para convertir número de LED en bit */
#define FIRST_BIT          1      /**< Representa el primer bit en una máscara */
#define MAX_LED_NUMBER     16     /**< Representa el numero maximo de LED valido */
#define MIN_LED_NUMBER     1      /**< Representa el numero minimo de LED valido */

/* === Private data type declarations ========================================================== */

/* === Private function declarations =========================================================== */

static inline uint16_t leds_to_bit(uint16_t led_number);
static inline bool_t led_is_out_of_range(uint16_t led_number);
static inline bool_t led_check_if_is_on(uint16_t led_number);

/* === Private variable definitions ============================================================ */

static uint16_t * leds_port_private; /**< Puntero al puerto de LEDs virtual */

/* === Private function implementation ========================================================= */

/**
 * @brief Convierte un número de LED a su bit correspondiente en la máscara.
 *
 * @param led_number Número del LED a convertir (1-16).
 * @return uint16_t Máscara con el bit correspondiente al LED.
 */
static inline uint16_t leds_to_bit(uint16_t led_number) {
    return (FIRST_BIT << ((led_number)-LEDS_TO_BIT_OFFSET));
}

/**
 * @brief Consulta si el número de led esta fuera de rango
 *
 * @param led_number Número del LED.
 * @return bool_t TRUE si el led esta fuera de rango | FALSE en caso contrario
 */
static inline bool_t led_is_out_of_range(uint16_t led_number) {
    return (led_number < MIN_LED_NUMBER || led_number > MAX_LED_NUMBER);
}

/**
 * @brief Verifica las condiciones para que un LED se considere encendido
 *
 * @param led_number Número del LED a convertir (1-16).
 * @return bool_t TRUE si el LED esta encendido | FALSE en caso contrario
 */
static inline bool_t led_check_if_is_on(uint16_t led_number) {
    return (*leds_port_private & leds_to_bit(led_number)) != 0;
}
/* === Public function implementation ========================================================== */

/**
 * @brief Inicializa el puerto de LEDs virtual.
 *
 * @param leds_port Puntero a la variable que representa el puerto de LEDs.
 */
void leds_init(uint16_t * leds_port) {
    leds_port_private = leds_port;
    led_turn_all_off(); // Apagar todos los LEDs en la inicialización.
}

/**
 * @brief Enciende un LED específico.
 *
 * @param led_number Número del LED a encender (1-16).
 */
void leds_on_single(uint16_t led_number) {
    *leds_port_private |= leds_to_bit(led_number);
}

/**
 * @brief Apaga un LED específico.
 *
 * @param led_number Número del LED a apagar (1-16).
 */
void leds_off_single(uint16_t led_number) {
    *leds_port_private &= ~leds_to_bit(led_number);
}

/**
 * @brief Enciende todos los LEDs.
 */
void led_turn_all_on(void) {
    *leds_port_private = ALL_LEDS_ON;
}

/**
 * @brief Apaga todos los LEDs.
 */
void led_turn_all_off(void) {
    *leds_port_private = ALL_LEDS_OFF;
}

/**
 * @brief Verifica si un LED específico está encendido.
 *
 * @param led_number Número del LED a consultar (1-16).
 * @return bool_t TRUE si el LED está encendido, FALSE en caso contrario o si el número esta fuera
 * de rango.
 */
bool_t led_is_this_on(uint16_t led_number) {
    return !led_is_out_of_range(led_number) ? led_check_if_is_on(led_number) != 0 : false;
}

/**
 * @brief Verifica si un LED específico está apagado.
 *
 * @param led_number Número del LED a consultar (1-16).
 * @return bool_t TRUE si el LED está apagado, FALSE en caso contrario o si el número esta fuera de
 * rango.
 */
bool_t led_is_this_off(uint16_t led_number) {
    return !led_is_out_of_range(led_number) ? !led_check_if_is_on(led_number) : false;
}

/* === End of documentation ==================================================================== */
