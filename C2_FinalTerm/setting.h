#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>

#define BUFFSIZE 1024

// �g�p�����֐��ꗗ
void getCurrentDirectory(char* currentDirectory);
// �Q�[���^�C�g�������[�h�̑I��
int introduction();
// ���̍쐬
int makeQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size);
// ���̏o��
void printQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size, int answer);
// �񓚂̓���
int getAnswer(int size, int answer);
// ���O�̓���
void getName(char name[10]);
// �Q�[�����v���C
int playGame(time_t startTime, time_t endTime);
// ���ʂ̏o��
void result(char name[10], int correct, time_t playTime);
// �Q�[���̐���
void description();
// �Q�[���̃v���C���ʃ����L���O�\��
void ranking();