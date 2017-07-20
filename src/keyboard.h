#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define KEY_ENTER 0x1C
#define KEY_BACKSPACE 0x0E
#define KEY_SHIFT 0x36
#define KEY_ESCAPE 0x01

typedef struct {
	char normal[256];
	char shifted[256];
} scanmap;

typedef struct {
	uint8_t chr;
	uint8_t scan;
	bool down;
	uint8_t code;
} key_event;

void keyboard_setscanmap(scanmap* map);
uint8_t keyboard_getScancode();
bool keyboard_getkey(key_event* event);

#endif