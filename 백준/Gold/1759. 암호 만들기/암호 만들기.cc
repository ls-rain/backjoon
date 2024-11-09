#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 모음 1개이상, 자음 2개이상
// 오름차순

struct info {
    char ch;
    bool check;
};

int l, c;
vector<info> v;

void dfs(int idx, int aCount, int bCount, int total, string s) {
    if (total == l) {
        if (aCount >= 1 && bCount >= 2) {
            cout << s << '\n';
        }
        return;
    }
    for (int i = idx + 1; i < v.size(); i++) {
        if (v[i].check) dfs(i, aCount + 1, bCount, total + 1, s + v[i].ch);
        else dfs(i, aCount, bCount + 1, total + 1, s + v[i].ch);
    }
}

// 오름차순 정렬
bool cmp(info a, info b) {
    return a.ch < b.ch;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char a;
        cin >> a;
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') v.push_back({a, true});
        else v.push_back({a, false});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].check) dfs(i, 1, 0, 1, string(1, v[i].ch));
        else dfs(i, 0, 1, 1, string(1, v[i].ch));
    }
}
