/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "touch.h"

#define HAS_TOUCH_PANEL()           touchCST340Flag == true

#define CST340_READ_XY_REG          0xD000		// Touch info register
#define TOUCH_POINTS_MAX            5	        // Max touch points

#define TOUCH_ACK                   0  			       
#define TOUCH_NACK                  1	

#define CST340_I2C_ADDR             0x1A

extern bool touchCST340Flag;
extern uint32_t touchI2Chiccups;
extern bool touchPanelInit();

struct TouchState touchPanelRead();
bool touchPanelEventOccured();

PACK(typedef struct {
  uint8_t track;
  uint16_t x;
  uint16_t y;
  uint16_t size;
  uint8_t reserved;
}) TouchPoint;

PACK(struct TouchData {
  union
  {
    TouchPoint points[TOUCH_POINTS_MAX];
    uint8_t data[TOUCH_POINTS_MAX * sizeof(TouchPoint)];
  };
});

#define TPRST_LOW()   do { TOUCH_RST_GPIO->BSRRH = TOUCH_RST_GPIO_PIN; } while(0)
#define TPRST_HIGH()  do { TOUCH_RST_GPIO->BSRRL = TOUCH_RST_GPIO_PIN; } while(0)
