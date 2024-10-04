#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// 1. k개의 접시 연속해서 먹으면 정액할인 가격
// 2. 1번에 해당할때, 초밥 번호 쿠폰발행, 그 번호 공짜, 번호 없으면 새로 만들어줌

vector<int> v;
int n, d, k, c, visited[3001];

int main() {
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		int rice;
		cin >> rice;
		v.push_back(rice);
	}
	int flag = 0, coupon = 0, res = 0;
	//슬라이딩 윈도우
	for (int i = 0; i < n; i++) {
		flag = 0;
		coupon = 1;
		for (int j = i; j < i + k; j++) {
			if (visited[v[j % n]] == 1) flag++;
			//처음 등장한 초밥
			else visited[v[j % n]] = 1;
			//쿠폰일경우
			if (v[j % n] == c) coupon = 0;
		}
		res = max(res, k - flag + coupon);
		memset(visited, 0, sizeof(visited));
	}
	cout << res;
}
