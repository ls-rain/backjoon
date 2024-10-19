#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;

int n, c, arr[200001], res;

bool judge(int mid) {
    int s = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] - s >= mid) {
            cnt++;
            s = arr[i];
        }
    }
    return cnt >= c;
}

// 첫 번째 집은 반드시 포함!
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int left = 1;
    int right = arr[n - 1] - arr[0] + 1;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (judge(mid)) {
            left = mid;
            res = max(res, left);
        } else right = mid;
    }
    cout << left;
}
