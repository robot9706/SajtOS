#ifndef __APP__
#define __APP__

typedef void (*app_entry_func)();

typedef struct {
	char* command;
	app_entry_func entry;
	
} app_info;

void shellExecute(const char* app);

#endif