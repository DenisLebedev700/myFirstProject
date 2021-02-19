#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int searchWords(char* string, int size) {
	int amount = 0, curLength = 0;
	char* ptr;
	while (*string != '\0') {
		if (isalpha(*string)) {
			curLength++;
		}
		else {
			if (curLength == size) {
				amount++;
			}
			curLength = 0;
		}
		string++;
	}
	if (curLength == size) {
		amount++;
	}
	return amount;
}

int main() {
	char* str = NULL;
	unsigned int strSize;
	unsigned int wrdSize;

	printf("type string's size: ");
	scanf("%lu", &strSize);
	if (strSize > 1000) {
		strSize = 100;
		printf("uncorrect value, changed to 100\n");
	}
	char tmp = getchar();
	str = (char*)malloc(strSize * sizeof(char));
	printf("\ntype string: ");
	for (int i = 0; i < strSize; i++) {
		str[i] = getchar();
		if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}
	}

	printf("\ntype word's size: ");
	scanf("%lu", &wrdSize);

	int result = searchWords(str, wrdSize);
	printf("\n%d - your result!", result);

	free(str);
	return 0;
}