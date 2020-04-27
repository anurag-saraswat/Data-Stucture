#include "stdio.h"

int main () {

	int i = 0;
	int count = 0;
	char s[] = "My   name is  anurag";

	while (s[i] != '\0') {

		if (s[i] == ' ' && s[i - 1] != ' ') {
			count++;
		}

		i++;
	}
	printf("No. of words in string are: ");
	printf("%d\n", ++count);
	return 0;
}