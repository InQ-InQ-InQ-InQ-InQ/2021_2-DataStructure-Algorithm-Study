public class Quick_Sort {
    public static void quick_sort(int left, int right, int[] arr){
        int i,j,pivot,temp;

        if(left<right){
            i=left;
            j=right;
            pivot=arr[left];

            while(i<j) {
                while (arr[j] > pivot) j--;
                while (i < j && arr[i] <= pivot) i++;

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            arr[left]=arr[i];
            arr[i]=pivot;
            quick_sort(left, i-1,arr);
            quick_sort(i+1,right,arr);
        }
    }
    public static void main(String[] agrs){
        int[] arr= {3,1,4,5,7,9,2,6,8};
        quick_sort(0,8,arr);
        for(int i =0;i<9;i++)
            System.out.print(arr[i]+" ");
    }
}
