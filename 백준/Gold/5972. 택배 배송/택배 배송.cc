#include <iostream>
#include <vector>
#include <queue>
#define MAX 500001

using namespace std;

int n, m, dist[MAX];
vector<pair<int, int> > load[MAX];

void dijkstra() {
    int res = 987654321;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 1});
    fill(dist, dist + MAX, 987654321);
    while (!pq.empty()) {
        int cost = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        for (int i = 0; i < load[s].size(); i++) {
            int nxt = load[s][i].first;
            int minCost = load[s][i].second;
            if (dist[nxt] > minCost + cost) {
                dist[nxt] = minCost + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        load[a].push_back({b, c});
        load[b].push_back({a, c});
    }
    dijkstra();
    cout << dist[n];
}
