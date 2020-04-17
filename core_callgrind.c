
#include <r_core.h>

#include <valgrind/callgrind.h>

#define CMD_PREFIX "?C"

static void _cmd(RCore *core, const char *input)
{
	CALLGRIND_START_INSTRUMENTATION;
	CALLGRIND_ZERO_STATS;
	r_core_cmd0 (core, input);
	CALLGRIND_DUMP_STATS;
	CALLGRIND_STOP_INSTRUMENTATION;
}

static int r2callgrind_cmd(void *user, const char *input)
{
	RCore *core = (RCore *) user;
	if (!strncmp (input, CMD_PREFIX, strlen(CMD_PREFIX)))
	{
		_cmd (core, input + 3);
		return true;
	}
	return false;
}

RCorePlugin r_core_plugin_ghidra = {
	.name = "r2callgrind",
	.desc = "Command profiler with callgrind",
	.license = "GPL3",
	.author = "thestr4ng3r",
	.version = NULL,
	.call = r2callgrind_cmd,
	.init = NULL,
	.fini = NULL
};

#ifndef CORELIB
R_API RLibStruct radare_plugin = {
	.type = R_LIB_TYPE_CORE,
	.data = &r_core_plugin_ghidra,
	.version = R2_VERSION,
	.free = NULL
};
#endif
