/*
 * Copyright (c) 2018 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#pragma once
#include <cstdarg>
#include <switch.h>
#include <stratosphere.hpp>

#define RGB888_TO_RGB565(r, g, b) ((((r >> 3) << 11) & 0xF800) | (((g >> 2) << 5) & 0x7E0) | ((b >> 3) & 0x1F))
#define RGB565_GET_R8(c) (((c >> 11) & 0x1F) << 3)
#define RGB565_GET_G8(c) (((c >> 5) & 0x3F) << 2)
#define RGB565_GET_B8(c) (((c >> 0) & 0x1F) << 3)

class FontManager {        
    public:
        static Result InitializeSharedFont();
        static void ConfigureFontFramebuffer(u16 *fb, u32 (*unswizzle_func)(u32, u32));

        static void SetFontColor(u16 color);
        static void DrawString(u32 x, u32 y, const char *str);
        static void DrawFormat(u32 x, u32 y, const char *format, ...);
};