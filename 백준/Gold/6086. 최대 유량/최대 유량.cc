#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 52
using namespace std;

int n, capacity;
char pip1, pip2;

int cap[MAX][MAX];
int flow[MAX][MAX];

char get_index(char c) {
	if (c >= 'A' && c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int edmonds(int start, int end) {
	memset(flow, 0, sizeof(flow));
	int res= 0;
	while (true) {
		vector<int> path(MAX, -1);
		queue<int> q;
		path[start] = start;
		q.push(start);
		while (!q.empty()&& path[end] == -1) {
			int cur = q.front();
			q.pop();
			for(int nxt = 0; nxt<MAX; nxt++)
				if (cap[cur][nxt] - flow[cur][nxt] > 0 && path[nxt] == -1) {
					q.push(nxt);
					path[nxt] = cur;
				}
		}		//BFS로 탐색
		if (path[end] == -1) break;		//종료조건
		int remain = 987654321;
		for (int p = end; p != start; p = path[p]) remain = min(cap[path[p]][p] - flow[path[p]][p], remain);
		for (int p = end; p != start; p = path[p]) {
			flow[path[p]][p] += remain;
			flow[p][path[p]] -= remain;
		}
		res += remain;
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pip1 >> pip2 >> capacity;
		pip1 = get_index(pip1);
		pip2 = get_index(pip2);
		cap[pip1][pip2] += capacity;
		cap[pip2][pip1] += capacity;
	}
	cout << edmonds(0, 'Z' - 'A');
}