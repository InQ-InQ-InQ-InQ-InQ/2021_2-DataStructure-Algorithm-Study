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
    int arr[9] = { 5, 3, 6, 1, 8, 4, 2, 9, 7 };

    MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}