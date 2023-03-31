#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int Ponavljanje(char*);

void main() {
	char novi_string[50], string[50], pom[2];
	int i = 0, br_pon, j = 0, k;
	scanf("%s", &string);

	while (i < strlen(string)) {
		br_pon = Ponavljanje(&string[i]);
		if (br_pon <= 2) {
			for (k = 0; k < br_pon; k++)
				novi_string[j++] = string[i];
			novi_string[j] = '\0';
		}
		else {
			itoa(br_pon, pom, 10);
			novi_string[j++] = pom[0];
			novi_string[j++] = string[i];
			novi_string[j] = '\0';
		}
		i += br_pon;
	}
	printf("%s", novi_string);
}