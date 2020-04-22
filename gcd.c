#include <stdio.h>


int gcd(int m, int n) {
	int i = (m < n ? m : n);
	for (; i > 0; i--) {
		if ( (m % i == 0) && (n % i == 0)) {return i;}
	}

}

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int val = gcd(m, n);
	printf("%d", val);
	return 0;
}
