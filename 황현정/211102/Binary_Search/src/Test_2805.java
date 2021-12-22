import java.util.*;

public class Test_2805 {
    static int[] trees;
    static int m, n, result;

    static void binarysearch(int low, int high) {
        int mid = (low + high) / 2;
        long sum = 0;
        if (low <= high) {
            for (int i = 0; i < n; i++) {
                if (trees[i] > mid)
                    sum = sum + trees[i] - mid;
            }
            if (sum >= m) {
                if (result < mid) result = mid;
                binarysearch(mid + 1, high);
            } else binarysearch(low, mid - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt(); //나무의 수 입력
        trees = new int[n]; //나무 배열 생성
        m = scan.nextInt(); //가져갈 나무 길이 입력
        int max = 0;

        //배열 입력
        for (int i = 0; i < n; i++) {
            trees[i] = scan.nextInt();
            if (trees[i] > max) max = trees[i];
        }
        binarysearch(1, max);
        System.out.println(result);
    }
}
