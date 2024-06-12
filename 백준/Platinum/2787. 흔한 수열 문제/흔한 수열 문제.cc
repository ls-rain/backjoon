#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int low[222], high[222], map[222][222];
int a[222], b[222], visited[222];

bool dfs(int node){
	visited[node] = 1;
	for(int i = 1; i <= n; i++){
		if(!map[node][i]) continue;
		if(b[i] == -1 || !visited[b[i]] && dfs(b[i])){
			a[node] = i;
			b[i] = node;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) map[i][j] = 1;
	for(int i = 1; i <= n; i++) low[i] = 1, high[i] = n;
	while(m--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		for(int i = 1; i <= n; i++){
			if(i < b || i > c) map[i][d] = 0;
			else if(a == 1) high[i] = min(high[i], d);
			else low[i] = max(low[i], d);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < low[i]; j++) map[i][j] = 0;
		for(int j = high[i] + 1; j <= n; j++) map[i][j] = 0;
	}
	int cnt = 0;
	memset(a, -1, sizeof(a));
	memset(b,-1,sizeof(b));
	for(int i = 1; i <= n; i++){
		if(a[i] == -1){
			memset(visited, 0, sizeof(visited));
			cnt += dfs(i);
		}
	}
	if(cnt < n){
		cout << -1;
		return 0;
	}
	for(int i = 1; i<= n; i++) cout << a[i] << " ";
}