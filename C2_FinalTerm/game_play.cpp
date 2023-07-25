#include "setting.h"

// ゲームをプレイ
void playGame(char name[10], std::chrono::seconds playTime) {
	question* firstQuestion = NULL;
	question* previous = NULL;
	int correct = 0;

	// 問題作成
	for (int i = 1; i < ROUND+1; i++) {
		question* tmp = new question;
		tmp->size = i * 4;
		tmp->answer = makeQuestion(tmp->char1, tmp->char2, tmp->size);
		if (i == 1) {
			firstQuestion = tmp;
		}
		else {
			previous->next = tmp;
		}
		previous = tmp;
	}

	for (;;) {
		question* tmp = new question;
		tmp = firstQuestion;

		// ゲームの開始
		fprintf_s(stdout, u8"-------------------------------------------------------\n");
		fprintf_s(stdout, u8"----------------------GAME-START-----------------------\n");

		auto startTime = std::chrono::high_resolution_clock::now();	// プレイ時間計測開始

		// 5ラウンド
		for (int i = 1; i < ROUND+1; i++) {
			// 問題表示
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
			fprintf_s(stdout, u8"第%d問：\n\n", i);
			printQuestion(tmp->char1, tmp->char2, tmp->size, tmp->answer);
			fprintf_s(stdout, "\n\n");

			// 解答入力
			int playersAnswer = getAnswer(tmp->size, tmp->answer);
			fprintf_s(stdout, "\n");

			// 答え合わせ
			if (tmp->answer == playersAnswer) {
				fprintf_s(stdout, u8"-------------------正解です！-------------------\n\n");
				correct += 1;
			}
			else
				fprintf_s(stdout, u8"-------------------不正解です.-------------------\n\n");

			tmp = tmp->next;

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

		// プレイ結果表示
		result(name, correct, playTime);

		// もう一度同じ問題でプレイするかの確認
		double d;
		fprintf_s(stdout, u8"もう一度、同じ問題でプレイしますか？\n");
		fprintf_s(stdout, u8"プレイするなら1を、しないなら2を押してください。\n");
		while (1) {
			fprintf_s(stdout, u8"入力：");
			if (scanf_s("%lf", &d) == 1 and (d == 1 or d == 2))
				break;
			fprintf_s(stdout, u8"1か2を入力してください。\n");
			scanf_s("%*[^\n]");
		}

		if (d == 2) {
			break;
		}
	}
}