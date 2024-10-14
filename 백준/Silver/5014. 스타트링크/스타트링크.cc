#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int arr[1000001];
int dir[] = {1, -1};

void bfs(int s) {
    queue<int> q;
    q.push(s);
    arr[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nxt = 0;
            if (i == 0) nxt = cur + dir[i] * U;
            else nxt = cur + dir[i] * D;
            if (nxt < 1 || nxt > F) continue;
            if (arr[nxt] > arr[cur] + 1) {
                arr[nxt] = arr[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;
    fill(arr, arr + 1000001, 1000000000);
    bfs(S);
    if (arr[G] == 1000000000) {
        cout << "use the stairs";
    } else cout << arr[G];
}
