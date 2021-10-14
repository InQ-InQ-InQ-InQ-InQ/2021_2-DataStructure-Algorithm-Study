#include <stdio.h>
#include <malloc.h>

int n, m, res;

int BinarySearch(int* arr, int start, int end)
{
    int mid;
    long long int sum = 0; // 나무의 최대 길이 2,000,000,000
    
    if (start > end)
        return -1;
    
    mid = (start + end) / 2;
    
    // mid(높이)를 기준으로 가져갈 수 있는 나무의 길이를 구함
    for (int i = 0; i < n; i++) {
		if (arr[i] > mid) {
			sum += arr[i] - mid;
		}
	}

    // 가져가려는 길이보다 길면 mid(높이)를 더 높여 높이의 최대값을 구함
    if (sum >= m) {
        if (res < mid) res = mid;
        BinarySearch(arr, mid + 1, end);
    }
    // 그렇지 않으면 높이를 낮춰 가져가려는 길이에 충족하도록 함
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
        // 나무의 최대 길이를 구해 최대 탐색 범위를 지정
        if (tree[i] > max) max = tree[i];
    }

    // 집에 가져가려고 하는 나무의 길이는 최소 1이기 때문에 1부터 시작
    BinarySearch(tree, 1, max);
    printf("%d\n", res);

    free(tree);

    return 0;
}