#include "setting.h"

int introduction() {
	double d;
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-----------------�����ԈႢ�T���Q�[��------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");

	fprintf_s(stdout, u8"���[�h��I�����āA0�`3�̐�������͂��Ă��������B\n");
	fprintf_s(stdout, u8"0�F�Q�[�����v���C\n");
	fprintf_s(stdout, u8"1�F�Q�[���̐�����ǂ�\n");
	fprintf_s(stdout, u8"2�F�Q�[���̃v���C����������\n");
	fprintf_s(stdout, u8"3�F�Q�[�����I������\n\n");
	fprintf_s(stdout, u8"���́F");

	while (1) {
		if (scanf_s("%lf", &d) == 1 and d >= 0 and d <= 3)
			break;
		fprintf_s(stdout, u8"0�`3�̐�������͂��Ă��������B\n");
		scanf_s("%*[^\n]");
	}

	if (d == 0)
		return 0;
	else if (d == 1)
		return 1;
	else if (d == 2)
		return 2;
	else if (d == 3)
		return 3;
}