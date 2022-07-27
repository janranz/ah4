#include <stdbool.h>

typedef struct {
	int key;
} KeyBind;

typedef struct {
	bool enabled;
	int timeLimit;
} BacktrackConfig;

typedef struct {
	BacktrackConfig backtrack;
} Config;

extern Config config;

int config_getConfigs(char ***configs);
void config_load(const char *name);
void config_save(const char *name);
