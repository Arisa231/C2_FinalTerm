#include "setting.h"

// ゲームをプレイ
int playGame(std::chrono::seconds playTime) {
	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int answer = 0;
	int size = 0;
	int correct = 0;

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"----------------------GAME-START-----------------------\n");
	
	auto startTime = std::chrono::high_resolution_clock::now();	// プレイ時間計測開始

	// 5ラウンド
	for (int i = 1; i < 6; i++) {
		// 問題作成
		answer = 0;
		size = i * 4;
		answer = makeQuestion(char1, char2, size);

		// 問題表示
		fprintf_s(stdout, u8"-------------------------------------------------------\n");
		fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
		fprintf_s(stdout, u8"第%d問：\n\n", i);
		printQuestion(char1, char2, size, answer);
		fprintf_s(stdout, "\n\n");

		// 解答入力
		int playersAnswer = getAnswer(size, answer);
		fprintf_s(stdout, "\n");

		// 答え合わせ
		if (answer == playersAnswer) {
			fprintf_s(stdout, u8"-------------------正解です！-------------------\n\n");
			correct += 1;
		}
		else 
			fprintf_s(stdout, u8"-------------------不正解です.-------------------\n\n");

		if (i != 5) {
			// Enterキーが入力されたら、次の問題へ
			fprintf_s(stdout, u8"次の問題へ進むには、好きなキーを押してください。\n");
			system("pause");
			fprintf_s(stdout, "\n\n");
		}
		else {
			auto endTime = std::chrono::high_resolution_clock::now();							// プレイ時間計測終了
			playTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);	// プレイ時間記録
			fprintf_s(stdout, u8"----------------------GAME-FINISH----------------------\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
		}
	}
	return correct;
}