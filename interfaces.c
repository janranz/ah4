#include <dlfcn.h>

#include "interfaces.h"

Interfaces interfaces;

static void *find(const char *moduleName, const char *name)
{
	void *(*createInterface)(const char *name, int *returnCode);

	*(void **)&createInterface = dlsym(dlopen(moduleName, RTLD_NOLOAD | RTLD_LAZY), "CreateInterface");
	if (!createInterface)
		return 0;

	void *interface = createInterface(name, 0);
	if (interface)
		return interface;

	return 0;
}

void interfaces_init(void)
{
	interfaces.client = find("csgo/bin/linux64/client_client.so", "VClient018");
}