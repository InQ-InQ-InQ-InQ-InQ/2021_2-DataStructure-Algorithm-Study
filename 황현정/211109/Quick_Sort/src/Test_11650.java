import java.util.*;

public class Test_11650 {
    public static void quick_sort(int left, int right, int[][] arr) {
        int i, j, pivot1, pivot2;

        if (left < right) {
            i = left;
            j = right;
            pivot1 = arr[left][0];
            pivot2 = arr[left][1];

            while (i < j) {
                while (arr[j][0] > pivot1) j--;
                while (i < j && arr[i][0] <= pivot1) i++;

                swap(arr, i, j);
            }
            arr[left][0] = arr[i][0];
            arr[left][1] = arr[i][1];
            arr[i][0] = pivot1;
            arr[i][1] = pivot2;
            quick_sort(left, i - 1, arr);
            quick_sort(i + 1, right, arr);
        }
    }

    public static void sort_y(int[][] arr, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if ((arr[i][0] == arr[j][0]) && (arr[i][1] < arr[j][1])) {
                    swap(arr, i, j);
                }
        }
    }

    public static void swap(int arr[][], int i, int j) {
        int temp;
        temp = arr[i][0];
        arr[i][0] = arr[j][0];
        arr[j][0] = temp;
        temp = arr[i][1];
        arr[i][1] = arr[j][1];
        arr[j][1] = temp;
    }

    public static void main(String[] agrs) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = scan.nextInt();
            arr[i][1] = scan.nextInt();
        }
        quick_sort(0, n - 1, arr);
        sort_y(arr, n);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i][0] + " ");
            System.out.println(arr[i][1]);
        }
    }
}