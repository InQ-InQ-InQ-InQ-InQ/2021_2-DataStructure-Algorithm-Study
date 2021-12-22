public class IntQueue {
    private int max; //큐 용량
    private int front; //첫번째 요소 포인터
    private int rear; //마지막 요소 포인터
    private int num; //현재 데이터 수
    private int[] que; //큐 본체

    // 큐 비어있음 예외
    public class EmptyIntAryQueueException extends RuntimeException {
        public EmptyIntAryQueueException() {
        }
    }

    // 큐 가득참 예외
    public class OverflowIntAryQueueException extends RuntimeException {
        public OverflowIntAryQueueException() {
        }
    }

    public IntQueue(int capacity) {
        num = front = rear = 0;
        max = capacity;
        try {
            que = new int[max];
        } catch (OutOfMemoryError e) {
            max = 0;
        }
    }

    //인큐
    public int enque(int x) throws OverflowIntAryQueueException {
        if (num > max)
            throw new OverflowIntAryQueueException();
        que[rear++] = x;
        num++;
        if (rear == max)
            rear = 0;
        return x;
    }

    //디큐
    public int deque() throws EmptyIntAryQueueException {
        if (num <= 0)
            throw new EmptyIntAryQueueException();
        int x = que[front++];
        num--;
        if (front == max)
            front = 0;
        return x;
    }

    //피크 데이터
    public int peek() throws EmptyIntAryQueueException {
        if (num <= 0)
            throw new EmptyIntAryQueueException();
        return que[front];
    }

    public void dump() {
        if (num <= 0)
            System.out.println("큐가 비어 있습니다.");
        else {
            for (int i = 0; i < num; i++)
                System.out.print(que[(i + front) % max] + " ");
            System.out.println();
        }
    }
}
