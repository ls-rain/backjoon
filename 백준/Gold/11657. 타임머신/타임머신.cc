#include <iostream>
#include <vector>
#define MAX 6001
using namespace std;

const long long inf = 987654321;
int n, m;
long long dist[501];
bool path;
struct edge{
	int a, b, weight;
};
edge v[MAX];

void bellmanford(){
	dist[1] = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			int from = v[j].a;
			int to = v[j].b;
			int weight = v[j].weight;
			if(dist[from] == inf) continue;
			if(dist[from] + weight < dist[to]){
				if(i==n){
					cout << -1;
					return;
				}
				dist[to] = dist[from] + weight;
			}
		}
	}
	for(int i = 2; i<=n; i++){
		if(dist[i]==inf) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		int A, B, C;
		cin >> A >> B >> C;
		v[i] = {A,B,C};
	}
	for(int i = 0; i<=n; i++) dist[i] = inf;
	bellmanford();
	
}