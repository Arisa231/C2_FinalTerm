#include "setting.h"

void showRanking(playData* firstData) {
	playData* previous = NULL;
	playData* tmp = firstData;

	for (int i = 0; i < 10; i++) {
		fprintf_s(stdout, "%d  , %s  , %d  , %lf  \n", (i + 1), tmp->name, tmp->correct, tmp->playTime);
		previous = tmp;
		tmp = previous->next;
	}
}

void updateRanking(char name[10], int correct, std::chrono::seconds playTime, playData* firstData) {

}

// �����L���O��ǂݍ���
void CSV2struct(const char* fileName, playData* firstData) {
	FILE* fp;
	char* p;
	char s[BUFFSIZE];
	int index = 0;
	int i, n;
	n = 0;

	// CSV�f�[�^���\���̂Ɋi�[
	firstData = NULL;
	playData* previousData = NULL;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		char* ctx;
		fgets(s, BUFFSIZE, fp);	// �ŏ��̍s�͎̂Ă�

		for (i = 0; i < 10; i++) {
			playData* tmp = new playData();
			fgets(s, BUFFSIZE, fp);

			// �����N���i�[
			p = strtok_s(s, ", ", &ctx);
			tmp->rank = atof(p);

			// ���O���i�[
			p = strtok_s(NULL, ", ", &ctx);
			sprintf_s(s, "%s", p);
			tmp->name = s;

			// ���𐔂��i�[
			p = strtok_s(NULL, ", ", &ctx);
			// �f�[�^���������ꍇ
			if (p != "-") {
				tmp->isData = true;
				tmp->correct = atof(p);
			}

			// �Q�[���I���ɂ����������Ԃ��i�[
			p = strtok_s(NULL, ", ", &ctx);
			// �f�[�^���������ꍇ
			if (tmp->isData == true) {
				tmp->playTime = atof(p);
			}

			if (i == 0) {
				firstData = tmp;
			}
			else {
				previousData->next = tmp;
			}
			previousData = tmp;
		}
		fclose(fp);
	}
}

void struct2CSV(const char* fileName, playData * firstData) {
	FILE* fp;
    int i;
    char s[BUFFSIZE];
    errno_t error;

	playData* tmp = firstData;
	playData* previous = NULL;

    error = fopen_s(&fp, fileName, "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {
        sprintf_s(s, "����,���O,����������萔,������������(s)\n");
        fputs(s, fp);
        for (i = 0; i < 10; i++) {
            sprintf_s(s, "%d,%s,%d,%lf\n", (i + 1), tmp->name, tmp->correct, tmp->playTime);
            fputs(s, fp);
			if (i != 9) {
				previous = tmp;
				tmp = previous->next;
			}
        }
        fclose(fp);
    }
}