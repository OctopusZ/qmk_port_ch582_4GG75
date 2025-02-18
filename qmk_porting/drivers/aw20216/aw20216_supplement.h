/*
Copyright 2022 Huckies <https://github.com/Huckies>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdbool.h>
#include "gpio.h"

#define AW20216_POWER_CHECK              \
    if (!aw20216_power_status_get()) {   \
        aw20216_power_toggle(true);      \
    }                                    \
    if (!rgbled_status_check()) {        \
        aw20216_delayed_power_off_set(); \
    }

bool aw20216_power_status_get();
void aw20216_power_toggle(bool status);
void aw20216_delayed_power_off_set();
void aw20216_delayed_power_off_excute();
