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

#ifndef LEDS_H
#define LEDS_H

/**
 * @file leds.h
 * @brief Interface for managing leds pins.
 *
 * This file provides the definitions and declarations required for
 * configuring and manipulating leds pins, allowing their use as inputs or outputs.
 */

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>

/* === C++ Header ============================================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
typedef bool bool_t;
/* === Public data type declarations =========================================================== */

/**
 * @brief Inicializa el puerto de LEDs virtual.
 *
 * @param leds_port Puntero a la variable que representa el puerto de LEDs.
 */
void leds_init(uint16_t * led_port);

/**
 * @brief Enciende un LED específico.
 *
 * @param led_number Número del LED a encender (1-16).
 */
void leds_on_single(uint16_t led_number);

/**
 * @brief Apaga un LED específico.
 *
 * @param led_number Número del LED a apagar (1-16).
 */
void leds_off_single(uint16_t led_number);

/**
 * @brief Enciende todos los LEDs.
 */
void led_turn_all_on(void);

/**
 * @brief Apaga todos los LEDs.
 */
void led_turn_all_off(void);

/**
 * @brief Verifica si un LED específico está encendido.
 *
 * @param led_number Número del LED a consultar (1-16).
 * @return bool_t TRUE si el LED está encendido, FALSE en caso contrario o si el número es inválido.
 */
bool_t led_is_this_on(uint16_t led_number);

/**
 * @brief Verifica si un LED específico está apagado.
 *
 * @param led_number Número del LED a consultar (1-16).
 * @return bool_t TRUE si el LED está apagado, FALSE en caso contrario o si el número es inválido.
 */
bool_t led_is_this_off(uint16_t led_number);

/* === End of documentation ==================================================================== */
#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */
