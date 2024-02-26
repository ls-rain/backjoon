#include <vector>
#include <iostream>
#define MAX 1001
using namespace std;
const int MOD = 10007;
int n, dp[MAX][10];
// 크거나 같다인 오름차순의 개수(0으로 시작가능)
int main(){
	cin >> n;
	/*0~9 까지 10가지
	0~9로시작 0: 0~9, 1: 1~9 1~10까지 총합
	*/
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
		}
	}
	int res = 0;
	for (int i = 0; i < 10; i++) {
		res += dp[n][i];
	}
	cout << res % MOD;
}
