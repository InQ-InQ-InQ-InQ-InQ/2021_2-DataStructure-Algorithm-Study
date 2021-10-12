// ����: ū ���� n���� A���� C�� �̵�
// 1. ���� ���� n - 1���� A���� B�� �̵�
// 2. ū ���� 1���� A���� C�� �̵�
// 3. ���� ���� n - 1���� B���� C�� �̵�

#include <stdio.h>

HanoiTower(int n, char from, char by, char to) {
	if (n == 1) // �̵��� ������ ���� 1�����
		printf("%c %c\n", from, to);
	else {
		// 1. ���� ���� n - 1���� A���� B�� �̵�
		HanoiTower(n - 1, from, to, by);
		// 2. ū ���� 1���� A���� C�� �̵�
		printf("%c %c\n", from, to);
		// 3. ���� ���� n - 1���� B���� C�� �̵�
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

	// ����: ū ���� n���� A���� C�� �̵�
	HanoiTower(n, '1', '2', '3');

	return 0;
}