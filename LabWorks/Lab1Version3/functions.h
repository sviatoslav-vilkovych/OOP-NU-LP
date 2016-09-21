#pragma once

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>

struct FileRows {
	char *row;
	FileRows *addr;

};

FileRows *&loadFileToStack(char*);
