// 목적: 큰 원반 n개를 A에서 C로 이동
// 1. 작은 원반 n - 1개를 A에서 B로 이동
// 2. 큰 원반 1개를 A에서 C로 이동
// 3. 작은 원반 n - 1개를 B에서 C로 이동

#include <stdio.h>

HanoiTower(int n, char from, char by, char to) {
	if (n == 1) // 이동할 원반의 수가 1개라면
		printf("%c %c\n", from, to);
	else {
		// 1. 작은 원반 n - 1개를 A에서 B로 이동
		HanoiTower(n - 1, from, to, by);
		// 2. 큰 원반 1개를 A에서 C로 이동
		printf("%c %c\n", from, to);
		// 3. 작은 원반 n - 1개를 B에서 C로 이동
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

	// 목적: 큰 원반 n개를 A에서 C로 이동
	HanoiTower(n, '1', '2', '3');

	return 0;
}