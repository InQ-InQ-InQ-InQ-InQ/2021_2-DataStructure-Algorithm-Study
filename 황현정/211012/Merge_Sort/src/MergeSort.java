import java.util.*;

public class MergeSort {
    static int[] buff; //작업용 배열

    static void __mergesort(int[] a, int left, int right) {
        if (left < right) {
            int i;
            int center = (left + right) / 2;
            int p = 0; int j = 0; int k = left;
            __mergesort(a, left, center);
            __mergesort(a, center + 1, right);

            for (i = left; i <= center; i++)
                buff[p++] = a[i];
            while (i <= right && j < p)
                a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
            while (j < p)
                a[k++] = buff[j++];
        }
    }

    static void mergesort(int[] a, int n) {
        buff = new int[n];
        __mergesort(a, 0, n - 1);
        buff = null;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("병합정렬");
        System.out.println("요솟수 : ");
        int nx = scan.nextInt();
        int[] x = new int[nx];

        for (int i = 0; i < nx; i++) {
            System.out.println("x[" + i + "] : ");
            x[i] = scan.nextInt();
        }
        mergesort(x, nx);
        System.out.println("오름차순으로 정렬했습니다.");
        for (int i = 0; i < nx; i++)
            System.out.println("x[" + i + "] = " + x[i]);
    }
}
