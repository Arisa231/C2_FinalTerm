#include "Setting.h"


// ���̍쐬
int makeQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size) {
	// ���Ɏg�p���镶����I��
	int random;
	srand(time(NULL));
	char currentDirectory[BUFFSIZE];
	getCurrentDirectory(currentDirectory);
	char section[BUFFSIZE];
	random = rand() % 3 + 1;
	sprintf_s(section, "section%d", random);
	char file[BUFFSIZE];
	random = (rand() % 5 + 1) * 10;
	sprintf_s(file, "Q%d", random);
	char settingFile[BUFFSIZE];
	sprintf_s(settingFile, "%s\\characters.ini", currentDirectory);
	GetPrivateProfileString(section, file, "none", char1, BUFFSIZE, settingFile);

	random += 1;
	sprintf_s(file, "Q%d", random);
	GetPrivateProfileString(section, file, "none", char2, BUFFSIZE, settingFile);

	// �����ƂȂ�ꏊ(������������قȂ�ꏊ)�̌���
	random = 0;
	int answer = 0;

	for (int i = 0; i < 2; i++) {
		random = rand() % size + 1;
		answer = answer * 10 + random;
	}

	fprintf_s(stdout, "%d\n", answer);
	return answer;
}

// ���̏o��
void printQuestion(char char1[BUFFSIZE], char char2[BUFFSIZE], int size, int answer) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (i == 0 && j == 0) {
				fprintf_s(stdout, "   ");
			}
			else if (i == 0) {
				fprintf_s(stdout, "%d ", j);
			}
			else if (j == 0) {
				fprintf_s(stdout, "%d ", i);
			}
			else if ((i * 10 + j) == answer) {
				fprintf_s(stdout, "%s", char2);
			}
			else {
				fprintf_s(stdout, "%s", char1);
			}

			if (j == size) {
				fprintf_s(stdout, "\n");
			}
		}
	}
}