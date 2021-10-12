package BJ_2751;
import java.util.*;

public class BJ_2751 {	
	private static int[] arr, temp;
	
	private static void mergeSort(int begin, int end) {
		if(begin < end) {
			int mid = (begin+end) / 2;
			mergeSort(begin, mid);
			mergeSort(mid+1, end);
			
			int p = begin;
			int q = mid+1;
			int index = p;
			
			while(p<=mid || q<=end) {
				if(q>end || (p<=mid && arr[p]<=arr[q]))
					temp[index++] = arr[p++];
				else
					temp[index++] = arr[q++];
			}
			
			for(int i=begin;i<=end;i++)
				arr[i] = temp[i];
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		arr = new int[N];
		temp = new int[arr.length];
		
		for(int i=0;i<N;i++)
			arr[i] = sc.nextInt();
		
		mergeSort(0, arr.length-1);
		
		for(int i=0;i<N;i++)
			System.out.println(arr[i]);
		
		sc.close();
	}
}
