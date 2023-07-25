#include "setting.h"

// �Q�[�����v���C
void playGame(char name[10], std::chrono::seconds playTime) {
	question* firstQuestion = NULL;
	question* previous = NULL;
	int correct = 0;

	// ���쐬
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

		// �Q�[���̊J�n
		fprintf_s(stdout, u8"-------------------------------------------------------\n");
		fprintf_s(stdout, u8"----------------------GAME-START-----------------------\n");

		auto startTime = std::chrono::high_resolution_clock::now();	// �v���C���Ԍv���J�n

		// 5���E���h
		for (int i = 1; i < ROUND+1; i++) {
			// ���\��
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
			fprintf_s(stdout, u8"��%d��F\n\n", i);
			printQuestion(tmp->char1, tmp->char2, tmp->size, tmp->answer);
			fprintf_s(stdout, "\n\n");

			// �𓚓���
			int playersAnswer = getAnswer(tmp->size, tmp->answer);
			fprintf_s(stdout, "\n");

			// �������킹
			if (tmp->answer == playersAnswer) {
				fprintf_s(stdout, u8"-------------------�����ł��I-------------------\n\n");
				correct += 1;
			}
			else
				fprintf_s(stdout, u8"-------------------�s�����ł�.-------------------\n\n");

			tmp = tmp->next;

			if (i != 5) {
				// Enter�L�[�����͂��ꂽ��A���̖���
				fprintf_s(stdout, u8"���̖��֐i�ނɂ́A�D���ȃL�[�������Ă��������B\n");
				system("pause");
				fprintf_s(stdout, "\n\n");
			}
			else {
				auto endTime = std::chrono::high_resolution_clock::now();							// �v���C���Ԍv���I��
				playTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);	// �v���C���ԋL�^
				fprintf_s(stdout, u8"----------------------GAME-FINISH----------------------\n");
				fprintf_s(stdout, u8"-------------------------------------------------------\n");
			}
		}

		// �v���C���ʕ\��
		result(name, correct, playTime);

		// ������x�������Ńv���C���邩�̊m�F
		double d;
		fprintf_s(stdout, u8"������x�A�������Ńv���C���܂����H\n");
		fprintf_s(stdout, u8"�v���C����Ȃ�1���A���Ȃ��Ȃ�2�������Ă��������B\n");
		while (1) {
			fprintf_s(stdout, u8"���́F");
			if (scanf_s("%lf", &d) == 1 and (d == 1 or d == 2))
				break;
			fprintf_s(stdout, u8"1��2����͂��Ă��������B\n");
			scanf_s("%*[^\n]");
		}

		if (d == 2) {
			break;
		}
	}
}