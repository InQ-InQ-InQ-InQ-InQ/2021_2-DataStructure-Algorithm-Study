#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <memory.h>

#define MAX_LENGTH 10

void Swap(char** arr, int idx1, int idx2)
{
    char tmp[MAX_LENGTH];
    strcpy(tmp, arr[idx1]);
    strcpy(arr[idx1], arr[idx2]);
    strcpy(arr[idx2], tmp);
}

int Partition(char** arr, int left, int right)
{
    char pivot[MAX_LENGTH]; // 정렬 중심점
    strcpy(pivot, arr[left]);
    int low = left + 1; // 정렬 대상에서 pivot을 제외한 맨 왼쪽 지점
    int high = right; // 정렬 대상에서 pivot을 제외한 맨 오른쪽 지점

    while (low <= high) {
        // 피벗보다 큰 값(우선순위가 낮은 값) 탐색
        while (low <= right && strcmp(pivot, arr[low]) >= 0) low++;

        // 피벗보다 작은 값(우선순위가 높은 값) 탐색
        while (high >= left + 1 && strcmp(arr[high], pivot) >= 0) high--;

        // low와 high가 교차되지 않았으면 우선순위가 높은 값이 앞에 오도록 자리를 바꿈
        if (low <= high) Swap(arr, low, high);
    }

    // pivot과 high의 자리를 바꿈으로써
    // pivot을 기준으로 왼쪽은 우선순위가 높은 값, 오른쪽은 우선순위가 낮은 값이 오게 함
    Swap(arr, left, high);

    // for (int i = 0; i < 5; i++) {
    //     printf("%s\n", arr[i]);
    // }

    // pivot의 위치를 반환함 (다음 정렬에서 pivot의 위치를 기준으로 좌우로 나누기 위함)
    return high;
}

void QuickSort(char** arr, int left, int right)
{
    // pivot +- 1로 인해 left와 right가 역전되는 순간이 올 수 있음 
    if (left <= right) {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int main()
{
    int n;
    char** arr;

    scanf("%d", &n);
    getchar();
    arr = (char*)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        arr[i] = (char**)malloc(MAX_LENGTH * sizeof(char*));
        gets(arr[i]);
    }

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}