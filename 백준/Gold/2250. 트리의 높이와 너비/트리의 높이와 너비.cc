#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001
#define INF 987654321

int n, idx;
int node[MAX], low[MAX], high[MAX];
pair<int, int> tree[MAX];
void dfs(int nodeNum, int depth) {
	if (tree[nodeNum].first > 0) dfs(tree[nodeNum].first, depth + 1);
	low[depth] = min(low[depth], idx);
	high[depth] = max(high[depth], idx++);
	if (tree[nodeNum].second > 0) dfs(tree[nodeNum].second, depth + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < MAX; i++) low[i] = INF;
	for (int i = 0; i < n; i++) {
		int p, l, r;
		cin >> p >> l >> r;
		node[p]++;
		if (l != -1) node[l]++;
		tree[p].first = l;
		if (r != -1) node[r]++;
		tree[p].second = r;
	}

	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (node[i] == 1){ root = i;
	}
}
	idx = 1;
	dfs(root, 1);

	int res = high[1] - low[1] + 1;
	int level = 1;
	for (int i = 2; i <= n; i++) {
		int temp = high[i] - low[i] + 1;
		if (temp > res) {
			res = temp;
			level = i;
		}
	}
	cout << level << " " << res << "\n";
	return 0;
}