import java.util.*;

public class Test_11650 {
    public static void quick_sort(int left, int right, int[][] arr) {
        int i, j;
        for (int k = 0; k < 5; k++) {
            System.out.print(arr[k][0] + " ");
            System.out.print(arr[k][1] + " ");
        }

        if (left < right) {
            i = left + 1;
            j = right;

            int pivot = left;
            System.out.println(left + " " + right + " " + i + " " + j);
            while (i < j) {
                while (i < j && arr[i][0] <= arr[pivot][0] || (arr[i][0] == arr[pivot][0] && arr[i][1] > arr[pivot][1]))
                    i++;
                while (i < j && arr[j][0] >= arr[pivot][0] || (arr[j][0] == arr[pivot][0] && arr[j][1] > arr[pivot][1]))
                    j--;
                System.out.println(i + " " + j);
                swap(arr, i, j);
            }
            if (i != left + 1 || j != right) {
                int[] tmp = arr[left];
                arr[left] = arr[j];
                arr[j] = tmp;
            }
            for (int k = 0; k < 5; k++) {
                System.out.print(arr[k][0] + " ");
                System.out.print(arr[k][1] + " ");
            }
            System.out.println(left + "" + right);
            quick_sort(left, i - 1, arr);
            quick_sort(i + 1, right, arr);
        }
    }

    public static void swap(int arr[][], int i, int j) {

        int[] temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = scan.nextInt();
            arr[i][1] = scan.nextInt();
        }
        quick_sort(0, n - 1, arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i][0] + " ");
            System.out.println(arr[i][1]);
        }
    }
}
