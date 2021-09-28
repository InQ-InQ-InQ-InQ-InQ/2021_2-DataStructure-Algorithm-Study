/* 
             _______1_______
            2               3
        4_______5       6_______7
*/

#include <stdio.h>

void DFS(int L)
{
    if (L > 7) return;
    else {
        //printf("%d ", L); // ������ȸ ���: 1 2 4 5 3 6 7
        DFS(L * 2);
        //printf("%d ", L); // ������ȸ ���: 4 2 5 1 6 3 7
        DFS(L * 2 + 1);
        //printf("%d ", L); // ������ȸ ���: 4 5 2 6 7 3 1
    }
}

int main()
{
    DFS(1);

    return 0;
}