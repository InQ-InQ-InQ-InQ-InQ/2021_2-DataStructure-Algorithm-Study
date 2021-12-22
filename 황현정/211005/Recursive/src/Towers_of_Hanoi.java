import java.util.*;


//no = 원반의 개수, x = 시작기둥의 번호, y = 목표기둥의 번호
public class Towers_of_Hanoi {
    static void move(int no, int x, int y){
        //시작기둥에서 중간기둥으로 이동
        if(no>1)
            move(no-1,x,6-x-y); //6-x-y = 중간기둥의 번호
        System.out.println("원반[" + no+"]을 "+x+"기둥에서 "+y+"기둥으로 옮김");
        //중간기둥에서 목표기둥으로 이동
        if(no>1)
            move(no-1,6-x-y,y);
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        System.out.println("원반의 개수 : ");
        int n = scan.nextInt();

        move(n,1,3);
    }
}
