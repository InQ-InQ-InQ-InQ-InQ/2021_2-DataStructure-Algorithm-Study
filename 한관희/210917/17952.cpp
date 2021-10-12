#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int flag, a, t;
    int total = 0;
    stack<pair<int, int>> stk;

    cin >> n;
    while (n--) {
        cin >> flag;
        if (flag == 1) { // ù �Է¿� '1'�� ������ a, t�� ���ÿ� ����
            cin >> a >> t;
            stk.push({a, t});
        }

        if (!stk.empty()) { // �� �� �ֱٿ� push�� �������� t�� 1�� ����
            stk.top().second--;
            if (stk.top().second == 0) { // t�� 0�� �Ǹ� ���� �Ϸ� -> pop, ���� �ݿ�
                total += stk.top().first;
                stk.pop();
            }
        }
    }
    cout << total << "\n";

    return 0;
}