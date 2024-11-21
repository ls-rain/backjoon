#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
// 숫자, 인덱스
vector<pair<int, int> > arr(500001);

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

// 오름차순 정렬하면서 제일 첫 번째로 바뀐 부분
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr[i] = {a, i};
    }
    sort(arr.begin() + 1, arr.begin() + n + 1, cmp);
    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (res < arr[i].second - i) res = arr[i].second - i;
    }
    cout << res + 1;
}
