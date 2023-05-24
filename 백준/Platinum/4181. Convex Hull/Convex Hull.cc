#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
ll n, point_x, point_y;
char c;

struct Point {
	ll x, y, dx, dy;
	Point() {};
	Point(ll x, ll y, ll dx = 0, ll dy = 0) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		}
	bool operator<(Point p){
		if (x != p.x) return x < p.x;
		else if (y != p.y) return y < p.y;
	}
	//최우선 x기준 오름차순 연산자 오버로딩
};
vector<Point> v;

bool comp(Point a, Point b) {
	if (a.dx * b.dy != a.dy * b.dx) return b.dx * a.dy < a.dx * b.dy;
	else if (a.dx * b.dy == a.dy * b.dx) {
		if (a.x == b.x) return a.y > b.y;
		else {
			if (a.y == b.y) return a.x < b.x;
			else return a.y > b.y;
		}
	}
}
int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> point_x >> point_y >> c;
		if (c == 'Y') {
			v.push_back(Point(point_x, point_y));
			cnt++;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) {
		v[i].dx = v[i].x - v[0].x;
		v[i].dy = v[i].y - v[0].y;
	}
	sort(v.begin()+1, v.end(), comp);
	cout << cnt << '\n';
	for (auto i : v) cout << i.x << " " << i.y << '\n';
}