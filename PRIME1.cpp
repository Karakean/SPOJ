#include <stdio.h>
bool is_prime(int x) {
	if ((x == 0) || (x == 1))
		return false;
	else if (x==2)
		return true;
	else if (x % 2 == 0) {
		return false;
	}
	for (int i = 3; i*i <= x; i+=2) {
		if (x % i == 0)
			return false;
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int m, n;
		scanf("%d %d", &m, &n);
		for (int j = m; j <= n; j++) {
			if (is_prime(j))
				printf("%d\n", j);
		}
	}
	return 0;
}
