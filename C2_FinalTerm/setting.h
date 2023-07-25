#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#define BUFFSIZE 1024
#define ROUND 5

struct question {
	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int size;
	int answer;
	question* next;
};

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
void playGame(char name[10], std::chrono::seconds playTime);
// �v���C���ʂ̏o��
void result(char name[10], int correct, std::chrono::seconds playTime);
// �Q�[���̐�����\��
void description();
// �v���C������"result.txt"����ǂݍ���ŁA�R���\�[����ʂɏo��
void readResult(const char* fileName);
// �v���C���ʂ�"result.txt"�ɏ�������
void writeResult(const char* fileName, char name[10], int correct, std::chrono::seconds playTime);