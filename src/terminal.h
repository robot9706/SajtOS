#ifndef __TERMINAL__
#define __TERMINAL__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 24;

static const uint8_t COLOR_BLACK = 0;
static const uint8_t COLOR_BLUE = 1;
static const uint8_t COLOR_GREEN = 2;
static const uint8_t COLOR_CYAN = 3;
static const uint8_t COLOR_RED = 4;
static const uint8_t COLOR_MAGENTA = 5;
static const uint8_t COLOR_BROWN = 6;
static const uint8_t COLOR_LIGHT_GREY = 7;
static const uint8_t COLOR_DARK_GREY = 8;
static const uint8_t COLOR_LIGHT_BLUE = 9;
static const uint8_t COLOR_LIGHT_GREEN = 10;
static const uint8_t COLOR_LIGHT_CYAN = 11;
static const uint8_t COLOR_LIGHT_RED = 12;
static const uint8_t COLOR_LIGHT_MAGENTA = 13;
static const uint8_t COLOR_LIGHT_BROWN = 14;
static const uint8_t COLOR_WHITE = 15;

uint8_t make_color(uint8_t fg, uint8_t bg);
uint16_t make_vgaentry(char c, uint8_t color);

void set_cursor(int row, int col);
void update_cursor();

void terminal_initialize();
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_writestring(const char* data);
void terminal_writeline(const char* data);
void terminal_nextline();
void terminal_scrollup();
void terminal_printbyte(uint8_t byte);
void terminal_printint32(uint32_t i);
void terminal_backspace();

size_t getCursorRow();
size_t getCursorColumn();

void terminal_fg(uint8_t color);
void terminal_bg(uint8_t color);
#endif