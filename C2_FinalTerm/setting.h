#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

#define BUFFSIZE 1024

//�@�֐�
void getCurrentDirectory(char* currentDirectory);
// ���̍쐬
int makeQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size);
// ���̏o��
void printQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size, int answer);
// �񓚂̓���
void putAnswer(int size, int answer);
// �Q�[�����v���C
void playGame();