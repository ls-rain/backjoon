#include <iostream>

#define MAX 100001
using namespace std;

int n, arr[MAX], brr[MAX], cnt = 0;
string a, b, tmp;
int res = 987654321;

void solve(int s) {
    tmp = a;
    cnt = 0;
    // 첫 번째 전구를 누르는 경우
    if (s == 0) {
        tmp[0] = (tmp[0] == '0') ? '1' : '0';
        tmp[1] = (tmp[1] == '0') ? '1' : '0';
        cnt++;
    }
    for (int i = 1; i < n; i++) {
        if (tmp[i - 1] != b[i - 1]) {
            if (i > 0) tmp[i - 1] = (tmp[i - 1] == '0') ? '1' : '0';
            tmp[i] = (tmp[i] == '0') ? '1' : '0';
            if (i < n - 1) tmp[i + 1] = (tmp[i + 1] == '0') ? '1' : '0';
            cnt++;
        }
    }
    if (tmp == b) res = min(res, cnt);
}

int main() {
    cin >> n;
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; i++) {
        arr[i] = a[i] - '0';
        brr[i] = b[i] - '0';
    }
    solve(0);
    solve(1);
    if (res != 987654321) cout << res;
    else cout << -1;
}
