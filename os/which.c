#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <alloca.h>

char *which(const char *prog) {
	char *epath = getenv("PATH");	
	size_t epath_bytes = strlen(epath) + 1;
	char *path = alloca(epath_bytes);
	char *ppath = alloca(1);
	size_t ppath_bytes = 1;

	// Clone $PATH to the stack
	memcpy(path, epath, epath_bytes);

	// Empty string
	*ppath = 0;

	while ((path = strtok(path, ":"))) {
		// Buf size of "%s/%s"
		size_t needs = strlen(path) + strlen(prog) + 2;

		// Allocate more space if current buffer is too small
		if (ppath_bytes < needs) {
			ppath = alloca(needs - ppath_bytes);
			ppath_bytes = needs;
		}

		snprintf(ppath, ppath_bytes, "%s/%s", path, prog);

		// If we can execute ppath, dup and return it
		if (!access(ppath, R_OK | X_OK))
			return strdup(ppath);

		path = NULL;
	}

	// 404 not found
	return NULL;
}
