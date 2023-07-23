#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

#define BUFFSIZE 1024

//@ŠÖ”
void getCurrentDirectory(char* currentDirectory);
// –â‘è‚Ìì¬
int makeQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size);
// –â‘è‚Ìo—Í
void printQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size, int answer);