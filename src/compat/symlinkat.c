#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "dir_mutex.h"

int symlinkat(const char *oldpath, int newdirfd, const char *newpath)
{
	int rc;
	int cwd;

	cwd = dir_mutex_lock(newdirfd);
	rc = symlink(oldpath, newpath);
	dir_mutex_unlock(cwd);
	return rc;
}