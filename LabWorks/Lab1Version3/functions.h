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

void renumber(FileRows*&);
void purge(FileRows*&);

void pop(FileRows*&);
void push(char*&, FileRows*&);