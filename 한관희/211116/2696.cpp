#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int QuickSelect(vector<int> vec, int k)
{
    vector<int> A, B, M;
    int pivot = vec[(0 + vec.size()) / 2];

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) A.push_back(vec[i]);
        else if (vec[i] > pivot) B.push_back(vec[i]);
        else M.push_back(vec[i]);
    }

    

    if (A.size() > k) return QuickSelect(A, k);
    else if (A.size() + M.size() < k) return QuickSelect(B, k - (A.size() + M.size()));
    else return pivot;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    
    cin >> t;
    while (t--) {
        vector<int> vec;
        vector<int> tmp;
        int m, cnt = 0;
        int idx = 0, k = 1;

        cin >> m;
        for (int i = 0; i < m; i++) {
            int n;
            cin >> n;
            vec.push_back(n);
        }

        cout << m / 2 + 1 << "\n";
        tmp.push_back(vec[idx++]);
        while (k <= m / 2 + 1) {
            cout << QuickSelect(tmp, k++) << " ";
            if (idx < vec.size()) tmp.push_back(vec[idx++]);
            if (idx < vec.size()) tmp.push_back(vec[idx++]);
            cnt++;
            if (cnt % 10 == 0) cout << "\n";
        }
        cout << "\n";
    }


    return 0;
}