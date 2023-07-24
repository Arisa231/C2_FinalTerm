#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>

#define BUFFSIZE 1024

// 使用した関数一覧
void getCurrentDirectory(char* currentDirectory);
// ゲームタイトル＆モードの選択
int introduction();
// 問題の作成
int makeQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size);
// 問題の出力
void printQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size, int answer);
// 回答の入力
int getAnswer(int size, int answer);
// 名前の入力
void getName(char name[10]);
// ゲームをプレイ
int playGame(time_t startTime, time_t endTime);
// 結果の出力
void result(char name[10], int correct, time_t playTime);
// ゲームの説明
void description();
// ゲームのプレイ結果ランキング表示
void ranking();