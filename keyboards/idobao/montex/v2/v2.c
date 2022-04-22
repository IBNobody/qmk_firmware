// Copyright 2022 peepeetee (@peepeetee)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "v2.h"

#ifdef RGB_MATRIX_ENABLE

#define __ NO_LED

led_config_t g_led_config = { {
    // Key Matrix to LED Index

    // VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
    // { 6,  5,  4,  30, 29},
    // { 24, 25, 26, 27, 28},
    // { 23, 22, 21, 20, 19},
    // { 15, 16, 17, 18, __},
    // { 14, 13, 12, 11, __},
    // { 7,  8,  __, 9,  10}
    // ^^^^^^^^^^^^^^^^^^^ not working

    { 4,  3,  2,  1,  0},
    { 5,  6,  7,  8,  9},
    { 14, 13, 12, 11, 10},
    { 15, 16, 17, 18, __},
    { 23, 22, 21, 20, __},
    { 24, 25, 26, 19, __}
}, {
    // LED Index to Physical Position

    // VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
    { 180,  3}, { 142, 54}, {  30, 54}, {  50,  3},             // 0 1 2 3 (underglow)
    { 112,  0}, {  56,  0}, {   0,  0},                         // 4 5 6
    {   0, 64}, {  84, 64}, { 168, 64}, { 210, 54},             // 7 - 10
    { 168, 51}, { 112, 51}, {  56, 51}, {   0, 51},             //11 - 14
    {   0, 38}, {  56, 38}, { 112, 38}, { 168, 38},             //15 - 18
    { 210, 30}, { 168, 26}, { 112, 26}, {  56, 26}, {   0, 26}, //19 - 23
    {   0, 13}, {  56, 13}, { 112, 13}, { 168, 13}, { 224, 13}, //24 - 28
    { 224,  0}, { 168,  0}                                      //29 30
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ this is still broken
}, {
    // LED Index to Flag
    // VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
    2, 2, 2, 2,     // 0 1 2 3 (underglow)
    1, 1, 1,        // 4 5 6
    1, 4, 4, 1,     // 7 - 10
    4, 4, 4, 1,     //11 - 14
    1, 4, 4, 4,     //15 - 18
    1, 4, 4, 4, 1,  //19 - 23
    1, 1, 1, 1, 1,  //24 - 28
    1, 1            //29 30
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ this is still broken
} };

#endif
