#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int n, a[MAX], dp[MAX], res;
//dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int now = 0;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) now = max(now, dp[j]);
		}
		dp[i] = now + 1;
		res = max(res, dp[i]);
	}
	cout << res;
}
