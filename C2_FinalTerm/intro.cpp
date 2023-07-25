#include "setting.h"

int introduction() {
	double d;
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-----------------•¶šŠÔˆá‚¢’T‚µƒQ[ƒ€------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");

	fprintf_s(stdout, u8"ƒ‚[ƒh‚ğ‘I‘ğ‚µ‚ÄA0`3‚Ì”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
	fprintf_s(stdout, u8"0FƒQ[ƒ€‚ğƒvƒŒƒC\n");
	fprintf_s(stdout, u8"1FƒQ[ƒ€‚Ìà–¾‚ğ“Ç‚Ş\n");
	fprintf_s(stdout, u8"2FƒQ[ƒ€‚ÌƒvƒŒƒC—š—ğ‚ğŒ©‚é\n");
	fprintf_s(stdout, u8"3FƒQ[ƒ€‚ğI—¹‚·‚é\n\n");
	fprintf_s(stdout, u8"“ü—ÍF");

	while (1) {
		if (scanf_s("%lf", &d) == 1 and d >= 0 and d <= 3)
			break;
		fprintf_s(stdout, u8"0`3‚Ì”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
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