#include <stdio.h>

int RecursiveBinarySearch(int arr[], int start, int end, int key)
{
    int mid;
    
    if (start > end)
        return -1;
    
    mid = (start + end) / 2;
    
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return RecursiveBinarySearch(arr, start, mid - 1, key);
    else
        return RecursiveBinarySearch(arr, mid + 1, end, key);

}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int idx, key;

    printf("Å½»ö °ª: ");
    scanf("%d", &key);
    
    idx = RecursiveBinarySearch(arr, 0, sizeof(arr) / sizeof(int) - 1, key);
    if (idx == -1)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("arr[%d] = %d\n", idx, arr[idx]);

    return 0;
}