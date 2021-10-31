import java.util.*;

public class Test_2805 {
    static int[] trees;

    static int binarysearch(int key, int low, int high) {
        int mid;
        int sum = 0;
        if (low <= high) {
            mid = (low + high) / 2;
            for (int i = 0; i < trees.length; i++) {
                if (trees[i] >= mid)
                    sum = sum + trees[i] - mid;
            }
            if (sum == key) { //탐색 성공
                return mid;
            } else if (key > sum) {
                return binarysearch(key, low, mid);
            } else return binarysearch(key, mid, high);
        }
        return -1; //탐색 실패
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(); //나무의 수 입력
        trees = new int[n]; //나무 배열 생성
        int hight = scan.nextInt(); //가져갈 나무 길이 입력

        //배열 입력
        for (int i = 0; i < n; i++)
            trees[i] = scan.nextInt();

        int max = trees[0];
        for(int i=0;i<n;i++) //array.sort로 해도 시간초과나서 for문으로 했는데도 시간초과 남ㅠㅠ
            if(trees[i]>max) max = trees[i];

        System.out.println(binarysearch(hight, 1, max));
    }
}
