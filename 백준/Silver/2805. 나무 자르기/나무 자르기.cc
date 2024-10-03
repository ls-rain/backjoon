#include <iostream>

#define MAX 1000000000
using namespace std;

int n, m, arr[1000001];

bool judge(int mid) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] - mid >= 0 ? arr[i] - mid : 0);
    }
    return sum >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
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
