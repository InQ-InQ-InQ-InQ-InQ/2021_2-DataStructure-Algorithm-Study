#include <stdio.h>
#include <malloc.h>

typedef struct {
    int x;
    int y;
} Coordinate;

// a의 값이 더 크면 1을 반환
int Compare(const Coordinate* a, const Coordinate* b)
{
    if (a->x == b->x) {
        if (a->y > b->y) return 1;
        else return 0;
    }
    else if (a->x > b->x) return 1;
    else return 0;
}

void Swap(Coordinate* arr, int idx1, int idx2)
{
    Coordinate tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int Partition(Coordinate* arr, int left, int right)
{
    Coordinate pivot = arr[left]; // 정렬 중심점
    int low = left + 1; // 정렬 대상에서 pivot을 제외한 맨 왼쪽 지점
    int high = right; // 정렬 대상에서 pivot을 제외한 맨 오른쪽 지점

    while (low <= high) {
        // 피벗보다 큰 값(우선순위가 낮은 값) 탐색
        while (Compare(&pivot, arr + low) && low <= right) low++;

        // 피벗보다 작은 값(우선순위가 높은 값) 탐색
        while (Compare(arr + high, &pivot)&& high >= left + 1) high--;

        // low와 high가 교차되지 않았으면 우선순위가 높은 값이 앞에 오도록 자리를 바꿈
        if (low <= high) Swap(arr, low, high);
    }

    // pivot과 high의 자리를 바꿈으로써
    // pivot을 기준으로 왼쪽은 우선순위가 높은 값, 오른쪽은 우선순위가 낮은 값이 오게 함
    Swap(arr, left, high);

    // pivot의 위치를 반환함 (다음 정렬에서 pivot의 위치를 기준으로 좌우로 나누기 위함)
    return high;
}

void QuickSort(Coordinate* arr, int left, int right)
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
    Coordinate* arr;

    scanf("%d", &n);
    arr = (Coordinate*)malloc(n * sizeof(Coordinate));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    free(arr);

    return 0;
}