#include <stdio.h>

HanoiTower(int n, char from, char by, char to) {
	if (n == 1)
		printf("%c %c\n", from, to);
	else {
		HanoiTower(n - 1, from, to, by);
		printf("%c %c\n", from, to);
		HanoiTower(n - 1, by, from, to);
	}
}

int main()
{
	int n;
	int cnt = 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		cnt *= 2;
	}
	printf("%d\n", cnt - 1);

	HanoiTower(n, '1', '2', '3');

	return 0;
}