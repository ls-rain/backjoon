#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100001], res[2];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int s = 0, e = n - 1;
    int minV = 2000000001;
    sort(arr, arr + n);
    while (s < e) {
        int sum = arr[s] + arr[e];
        if (minV > abs(sum)) {
            minV = abs(sum);
            res[0] = arr[s];
            res[1] = arr[e];
        } if (0 < sum) {
            e--;
        }
        else s++;
    }
    cout << res[0] << " " << res[1];
}
