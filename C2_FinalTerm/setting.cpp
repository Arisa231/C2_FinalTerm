#include "Setting.h"

void getCurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(BUFFSIZE, currentDirectory);
}