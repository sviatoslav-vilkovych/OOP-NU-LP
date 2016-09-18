#pragma once

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>

struct FileRows;
void push(FileRows *&pHeader, char *&str);
void pop(FileRows *&pHeader);
void purge(FileRows *&pHeader);
FileRows *loadFileToStack(char *fileName);
void renumber(FileRows *&pHeader);