import java.util.*;

public class Test {
    static int[] buff; //작업용 배열

    //배열을 앞뒤로 정렬
    static void __mergesort(int[] a, int left, int right ){
        if (left < right) {
            int i;
            int center = (left + right) / 2;
            int p = 0; int j = 0; int k = left;
            __mergesort(a, left, center); //배열 앞부분 정렬
            __mergesort(a, center + 1, right); //배열 뒷부분 정렬

            //버퍼에 배열 복사
            for (i = left; i <= center; i++)
                buff[p++] = a[i];
            //배열 정렬
            while (i <= right && j < p) //작은 값 저장
                a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
            while (j < p) //남은 요소 복사
                a[k++] = buff[j++];
        }
    }

    static void mergesort(int[] a, int n) {
        buff = new int[n]; //작업용 배열 생성
        __mergesort(a, 0, n - 1); //배열 전체 정렬
        buff = null; //작업용 배열 해제
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int nx = scan.nextInt(); //수의 개수 입력
        int[] x = new int[nx]; //수를 입력받을 배열 생성

        //배열 입력
        for (int i = 0; i < nx; i++)
            x[i] = scan.nextInt();

        mergesort(x, nx);

        //배열 출력
        for (int i = 0; i < nx; i++)
            System.out.println(x[i]);
    }
}
