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

struct playData 
{
	boolean isData = false;
	int rank;
	char* name;
	int correct;
	double playTime;
	playData* next = NULL;
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
int playGame(std::chrono::seconds playTime);
// ���ʂ̏o��
void result(char name[10], int correct, std::chrono::seconds playTime);
// �Q�[���̐���
void description();
// �Q�[���̃v���C���ʃ����L���O�\��
void showRanking(playData* firstData);
// �����L���O���X�V
void updateRanking(char name[10], int correct, std::chrono::seconds playTime, playData* firstData);
// CSV�t�@�C���̃f�[�^�i�����L���O�j��ǂݍ���ō\���̂Ɋi�[
void CSV2struct(const char* fileName, playData* firstData);
// �X�V���ꂽ�����L���O��csv�t�@�C���ɏo��
void struct2CSV(const char* fileName, playData* firstData);