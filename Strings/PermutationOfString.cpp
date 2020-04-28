#include "iostream"
using namespace std;

void permute(char S[], int k) {

	static int A[10] = {0};
	static char Res[10];
	int i;
	if (S[k] == '\0') {
		Res[k] = '\0';
		puts(Res);
	}
	else {
		for (int i = 0; S[i] != '\0'; i++) {
			{
				if (A[i] == 0) {
					Res[k] = S[i];
					A[i] = 1;
					permute(S, k + 1);
					A[i] = 0;
				}
			}
		}
	}
}

int main() {

	char s[] = "ABC";
	cout << "Possible Permutations Are: ";
	permute(s, 0);

	return 0;
}