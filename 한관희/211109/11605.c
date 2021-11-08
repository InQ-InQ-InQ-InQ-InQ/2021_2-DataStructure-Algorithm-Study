// https://fennecfox38.github.io/2021/01/24/BOJ-11650.html

#include <stdio.h>
#include <malloc.h>

typedef struct{ int x, y; } coordinate;

int compare(const coordinate* const a, const coordinate* const b)
{
    if(a->x == b->x) // x의 값이 동일할 경우 y값 비교 (같으면 0, 다르면 -1 반환)
    	return (a->y > b->y ? 1 : (a->y == b->y ? 0 : -1));
    else
    	return (a->x > b->x ? 1 : -1);
}

void quickSort(coordinate *array, int left, int right)
{
    int low = left, high = right;
    coordinate pivot = array[(left + right) / 2]; // 가급적 중간에 해당하는 값을 피벗으로 선택함(성능을 높이기 위함)
    coordinate tmp;
    
    // low와 high가 교차됐음은 모두 이미 pivot까지 탐색을 마치고 pivot을 지나쳐 서로 반대편에 진입한 것이므로 반복문을 탈출함
    while(low <= high) {
        // 피벗보다 큰 값(우선순위가 낮은 값) 탐색
    	while(compare(&pivot, array + low) == 1) ++low;

        // 피벗보다 작은 값(우선순위가 높은 값) 탐색
        while(compare(array + high, &pivot) == 1) --high;
        
        // low와 high가 교차되지 않았으면 우선순위가 높은 값이 앞에 오도록 자리를 바꿈
        if(low <= high) {
            tmp = array[low];
            array[low] = array[high];
            array[high] = tmp;
            ++low; --high;
        }
    }
	
    // 반복문을 탈출하면 high는 pivot 바로 전, low는 pivot 바로 이후로 오기 때문에
    // pivotIndex를 쓰지 않고, low와 high를 재활용함
    if(high > left) quickSort(array, left, high);
    if(right > low) quickSort(array, low, right);
}

int main()
{
    int N, i;
    coordinate* array;
    
    scanf("%d", &N);
    array = malloc(N * sizeof(coordinate));
    for(i = 0; i < N; ++i) {
    	scanf("%d %d", &(array[i].x), &(array[i].y));
    }

    quickSort(array, 0, N - 1);
    
    for(i = 0; i < N; ++i) {
    	printf("%d %d\n", array[i].x, array[i].y);
    }

    free(array);

    return 0;
}