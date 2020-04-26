#include "stdio.h"

int main() {
	char s[] = "Anurag Saraswat";
	int i = 0;
	int temp;

	while (s[i] != '\0') {

		temp = s[i];
		if (temp >= 'A' && temp < 'a') {
			s[i] = s[i] - 'A' + 'a';
		}
		else if (temp >= 'a' && temp <= 'z') {
			s[i] = s[i] + 'A' - 'a';

		}

		i++;
	}
	puts(s);
	return 0;
}