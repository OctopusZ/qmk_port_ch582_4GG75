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

enum {
    BOOTLOADER_BOOT_MODE_IAP = 0x05,
    BOOTLOADER_BOOT_MODE_USB = 0x0A,
    BOOTLOADER_BOOT_MODE_BLE = 0x50,
    BOOTLOADER_BOOT_MODE_ESB = 0xA0,
};

void bootloader_boot_mode_set(uint8_t mode);
uint8_t bootloader_boot_mode_get();
void bootloader_jump();
void mcu_reset();

__attribute__((always_inline)) inline uint8_t bootloader_set_to_default_mode(const char *reason)
{
    PRINT("%s, ", reason);
#ifdef USB_ENABLE
    PRINT("default to USB.\n");
    bootloader_boot_mode_set(BOOTLOADER_BOOT_MODE_USB);
    return BOOTLOADER_BOOT_MODE_USB;
#elif defined BLE_ENABLE
    PRINT("default to BLE slot 0.\n");
    bootloader_boot_mode_set(BOOTLOADER_BOOT_MODE_BLE_START);
    return BOOTLOADER_BOOT_MODE_BLE_START;
#else
    PRINT("default to ESB.\n");
    bootloader_boot_mode_set(BOOTLOADER_BOOT_MODE_ESB);
    return BOOTLOADER_BOOT_MODE_ESB;
#endif
}
