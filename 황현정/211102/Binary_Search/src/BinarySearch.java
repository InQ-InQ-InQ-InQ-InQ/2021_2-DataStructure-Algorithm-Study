public class BinarySearch {
    static int[] arr = {1, 3, 5, 7, 9, 10};

    public static void main(String[] args) {
        System.out.println(binarysearch(5, 0, arr.length - 1));
    }

    static int binarysearch(int key, int low, int high) {
        int mid;
        if (low <= high) {
            mid = (low + high) / 2;
            if (key == arr[mid]) { //탐색 성공
                return mid;
            } else if (key < arr[mid]) {
                return binarysearch(key, low, mid - 1);
            } else return binarysearch(key, mid + 1, high);
        }
        return -1; //탐색 실패
    }
}
