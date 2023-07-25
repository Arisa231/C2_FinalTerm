#include "setting.h"

void showRanking(playData* firstData) {
	playData* previous = NULL;
	playData* tmp = firstData;

	for (int i = 0; i < 10; i++) {
		if (tmp->isData == true) 
			fprintf_s(stdout, "%d  , %s  , %d  , %lf  \n", (i + 1), tmp->name, tmp->correct, tmp->playTime);
		else
			fprintf_s(stdout, "%d  , ---  , ---  , ---  \n", (i + 1));
		previous = tmp;
		tmp = previous->next;
	}
}

void updateRanking(const char* fileName, playData* firstData) {
	// 最新のプレイ結果を読み込む
	FILE* fp;
	char* p;
	char s[BUFFSIZE];
	int index = 0;
	int i, n;
	n = 0;

	// CSVデータを構造体に格納
	playData* latest = NULL;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		char* ctx;
		fgets(s, BUFFSIZE, fp);
		fgets(s, BUFFSIZE, fp);

		playData* tmp = new playData();
		fgets(s, BUFFSIZE, fp);

		// 名前を格納
		p = strtok_s(NULL, ", ", &ctx);
		sprintf_s(s, "%s", p);
		latest->name = s;

		// 正解数を格納
		p = strtok_s(NULL, ", ", &ctx);
		latest->correct = atof(p);

		// ゲーム終了にかかった時間を格納
		p = strtok_s(NULL, ", ", &ctx);
		latest->playTime = atof(p);
	}

	// ランキングのどこに入るかを探して、入れる
	if (latest != NULL) {
		playData* previous = NULL;
		playData* tmp = firstData;

		for (int i = 0; i < 10; i++) {
			if (tmp->correct == latest->correct and tmp->playTime <= latest->playTime) {
				if (previous == NULL) {
					firstData = latest;
					firstData->next = tmp;
				}
				else {
					// データ差し込み
					previous->next = latest;
					latest->rank = tmp->rank;
					latest->next = tmp;
					while (1) {
						tmp->rank += 1;
						if (tmp->rank == 11) {
							previous->next == NULL;
							break;
						}
						previous = tmp;
						tmp = previous->next;
					}
				}
			}
			else if (tmp->correct < latest->correct) {
				if (previous == NULL) {
					firstData = latest;
					firstData->next = tmp;
				}
				else {
					// データ差し込み
					previous->next = latest;
					latest->rank = tmp->rank;
					latest->next = tmp;
					while (1) {
						tmp->rank += 1;
						if (tmp->rank == 11) {
							previous->next == NULL;
							break;
						}
						previous = tmp;
						tmp = previous->next;
					}
				}
			}
		}
	}
}

// ランキングを読み込む
void CSV2struct(const char* fileName, playData* firstData) {
	FILE* fp;
	char* p;
	char s[BUFFSIZE];
	int index = 0;
	int i, n;
	n = 0;

	// CSVデータを構造体に格納
	firstData = NULL;
	playData* previousData = NULL;

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		char* ctx;
		fgets(s, BUFFSIZE, fp);	// 最初の行は捨てる

		for (i = 0; i < 10; i++) {
			playData* tmp = new playData();
			fgets(s, BUFFSIZE, fp);

			// ランクを格納
			p = strtok_s(s, ", ", &ctx);
			tmp->rank = atof(p);

			// 名前を格納
			p = strtok_s(NULL, ", ", &ctx);
			sprintf_s(s, "%s", p);
			tmp->name = s;

			// 正解数を格納
			p = strtok_s(NULL, ", ", &ctx);
			// データがあった場合
			if (p != "-") {
				tmp->isData = true;
				tmp->correct = atof(p);
			}

			// ゲーム終了にかかった時間を格納
			p = strtok_s(NULL, ", ", &ctx);
			// データがあった場合
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
        sprintf_s(s, "順位,名前,正解した問題数,かかった時間(s)\n");
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