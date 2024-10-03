#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;

int m, n, arr[1000001], res;

bool judge(int mid) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i] / mid;
    }
    return cnt >= m;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int left = 0, right = MAX;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (judge(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
}
