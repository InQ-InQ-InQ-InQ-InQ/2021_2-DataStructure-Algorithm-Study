#include <stdio.h>
#include <malloc.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int lIdx = left;
    int rIdx = mid + 1;
    int ptr = left;
    int *sortedArr = (int*)malloc((right + 1) * sizeof(int));

    // �������� �˰����� �̿��� ������ (��������)
    while (lIdx <= mid && rIdx <= right) {
        if (arr[lIdx] <= arr[rIdx])
            sortedArr[ptr++] = arr[lIdx++];
        else
            sortedArr[ptr++] = arr[rIdx++];
    }
    while (lIdx <= mid) sortedArr[ptr++] = arr[lIdx++];
    while (rIdx <= right) sortedArr[ptr++] = arr[rIdx++];

    // ���ĵ� ���� arr�� ������
    for (int i = left; i <= right; i++) {
        arr[i] = sortedArr[i];
    }

    free(sortedArr);
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right) {
        // �迭�� �������� ������ ���� �ε����� �߾Ӱ��� ����
        int mid = (left + right) / 2;

        // �迭�� �߾��� �������� �¿�� 1/2�丷 ��
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // ������ �� �迭�� �����ϰ� ������
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