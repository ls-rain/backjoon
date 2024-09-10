#include <iostream>
#include <vector>
#define MAX 1000000001
#define MIN -1000000001

using namespace std;

long long n, arr[100001];

// 두 수의 합의 절댓값이 가장 작은 것 고르기
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int left = 0, right = n - 1;
    long long a = arr[left], b = arr[right];
    int init = abs(a + b);
    while (left < right) {
        int mid = arr[left] + arr[right];
        if (abs(mid) < init) {
            init = abs(mid);
            a = arr[left], b = arr[right];
        }
        if (mid < 0) left++;
        else right--;
    }
    cout << a << ' ' << b;
}
