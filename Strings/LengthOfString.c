#include "stdio.h"

int main() {
	char *s = "Anurag Saraswat";
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	printf("%d\n", i);
	return 0;
}