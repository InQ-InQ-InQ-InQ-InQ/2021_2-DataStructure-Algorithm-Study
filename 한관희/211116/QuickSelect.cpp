#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef int Data;

Data QuickSelect(vector<Data> vec, int k)
{
    vector<Data> A, B, M;
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

    srand((unsigned int)time(NULL));

    vector<Data> vec;
    int k = 3;

    cout << "=========== vector ===========" << "\n";
    for (int i = 0; i < 10; i++) {
        vec.push_back(rand() % 100 + 1);
        cout << vec[i] << " ";
    }
    cout << "\n";

    cout << k << "st number: " << QuickSelect(vec, k - 1) << "\n";

    sort(vec.begin(), vec.end());

    cout << "\n" << "=========== sorted vector ===========" << "\n";
    for (int i = 0; i < 10; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

    return 0;
}