#include <stdio.h>
#include <malloc.h>

int n, m, res;

int BinarySearch(int* arr, int start, int end)
{
    int mid;
    long long int sum = 0; // ������ �ִ� ���� 2,000,000,000
    
    if (start > end)
        return -1;
    
    mid = (start + end) / 2;
    
    // mid(����)�� �������� ������ �� �ִ� ������ ���̸� ����
    for (int i = 0; i < n; i++) {
		if (arr[i] > mid) {
			sum += arr[i] - mid;
		}
	}

    // ���������� ���̺��� ��� mid(����)�� �� ���� ������ �ִ밪�� ����
    if (sum >= m) {
        if (res < mid) res = mid;
        BinarySearch(arr, mid + 1, end);
    }
    // �׷��� ������ ���̸� ���� ���������� ���̿� �����ϵ��� ��
    else BinarySearch(arr, start, mid - 1);
}

int main()
{
    int max = 0;
    int *tree;

    scanf("%d %d", &n, &m);
    tree = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
        // ������ �ִ� ���̸� ���� �ִ� Ž�� ������ ����
        if (tree[i] > max) max = tree[i];
    }

    // ���� ���������� �ϴ� ������ ���̴� �ּ� 1�̱� ������ 1���� ����
    BinarySearch(tree, 1, max);
    printf("%d\n", res);

    free(tree);

    return 0;
}