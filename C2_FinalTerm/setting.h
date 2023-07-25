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
void playGame(char name[10], std::chrono::seconds playTime);
// プレイ結果の出力
void result(char name[10], int correct, std::chrono::seconds playTime);
// ゲームの説明を表示
void description();
// プレイ履歴を"result.txt"から読み込んで、コンソール画面に出力
void readResult(const char* fileName);
// プレイ結果を"result.txt"に書き込む
void writeResult(const char* fileName, char name[10], int correct, std::chrono::seconds playTime);