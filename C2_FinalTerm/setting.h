#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

#define BUFFSIZE 1024

//　関数
void getCurrentDirectory(char* currentDirectory);
// 問題の作成
int makeQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size);
// 問題の出力
void printQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size, int answer);
// 回答の入力
void putAnswer(int size, int answer);
// ゲームをプレイ
void playGame();