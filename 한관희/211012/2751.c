#include <stdio.h>
#include <malloc.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int lIdx = left;
    int rIdx = mid + 1;
    int ptr = left;
    int *sortedArr = (int*)malloc((right + 1) * sizeof(int));

    // 투포인터 알고리즘을 이용해 정렬함 (오름차순)
    while (lIdx <= mid && rIdx <= right) {
        if (arr[lIdx] <= arr[rIdx])
            sortedArr[ptr++] = arr[lIdx++];
        else
            sortedArr[ptr++] = arr[rIdx++];
    }
    while (lIdx <= mid) sortedArr[ptr++] = arr[lIdx++];
    while (rIdx <= right) sortedArr[ptr++] = arr[rIdx++];

    // 정렬된 값을 arr에 복사함
    for (int i = left; i <= right; i++) {
        arr[i] = sortedArr[i];
    }

    free(sortedArr);
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right) {
        // 배열을 절반으로 나누기 위해 인덱스의 중앙값을 구함
        int mid = (left + right) / 2;

        // 배열을 중앙을 기준으로 좌우로 1/2토막 냄
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // 나눠진 두 배열을 정렬하고 병합함
        MergeTwoArea(arr, left, mid, right);
    }
}

int main()
{
    int n;
    int *arr;

    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}