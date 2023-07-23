#include "Setting.h"

int main()
{
	// Set the code page of the output console to UTF-8(日本語が文字化けしないため)
	SetConsoleOutputCP(CP_UTF8);

	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int answer = 0;
	int size = 5;

	answer = makeQuestion(char1, char2, size);

	fprintf_s(stdout, "%d\n", answer);

	printQuestion(char1, char2, size, answer);

	fprintf_s(stdout, "\n\n");
	fprintf_s(stdout, u8"一つだけ異なる文字は、何列目ですか？(解答を入力したらEnterを押してください。\n");
	double d;
	
	while (1) {
		fprintf_s(stdout, u8"解答：");
		scanf_s("%lf", &d);

		if (d > size or d < 1) {
			fprintf_s(stdout, u8"1から%d列までしかありません。もう一度入力してください。\n", size);
		}
		else if (isdigit(d) == false) {
			fprintf_s(stdout, u8"数字を入力してください。\n");
		}
		else {
			break;
		}
	}



}