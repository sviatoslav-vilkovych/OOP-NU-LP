#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;


struct FileRows {
	char *row;
	FileRows *addr;
};

FileRows *&loadFileToStack(char*);

void renumber(FileRows*&);
void purge(FileRows*&);

void pop(FileRows*&);
void push(char*&, FileRows*&);
