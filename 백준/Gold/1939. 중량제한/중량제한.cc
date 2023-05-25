#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define inf 1000000000
typedef long long ll;
using namespace std;

int n, m, A, B, C, FAC1, FAC2;
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>> pq;

int dijkstra(int fac1, int fac2) {
	vector<int> res(n + 1, -1);
	res[fac1] = inf;
	pq.push({ inf, fac1 });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_weight = pq.top().first;
		pq.pop();
		if (res[cur] > cur_weight) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int k = v[cur][i].second;
			int k_weight = min(v[cur][i].first, cur_weight);
			if (res[k] < k_weight) {
				res[k] = k_weight;
				pq.push({ k_weight, k });
			}
		}
	}
	return res[fac2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ C, B });
		v[B].push_back({ C, A });
	}
	cin >> FAC1 >> FAC2;
	cout << dijkstra(FAC1, FAC2);
}