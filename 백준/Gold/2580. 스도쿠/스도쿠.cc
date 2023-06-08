#include <iostream>
#include <vector>
using namespace std;

int cnt;
int map[9][9];
vector<pair<int, int> > v;
bool judge = false;

bool promising(pair<int, int> p){
	int x = p.first;
	int y = p.second;
	int divide_x = x/3;
	int divide_y = y/3;
	for(int i = 0; i<9; i++){
		if(map[x][i] == map[x][y] && i!=y) return false;
		if(map[i][y] == map[x][y] && i!=x) return false;
	}
	for(int i = 3*divide_x; i<3*divide_x+3; i++)
		for(int j = 3*divide_y; j<3*divide_y+3; j++)
			if(map[i][j] == map[x][y])
				if(i != x && j!=y) return false;
	return true;			
}

void sudoku(int n){
	if(n == cnt){
		for(int i = 0; i<9; i++){
			for(int j = 0; j<9; j++){
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}
		judge = true;
		return;
	}
	for(int i = 1; i<=9; i++){
		map[v[n].first][v[n].second] = i;
		if(promising(v[n])) sudoku(n+1);
		if(judge) return;
	}
	map[v[n].first][v[n].second] = 0;
	return;
}

int main(){
	cnt = 0;
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			cin >> map[i][j];
			if(map[i][j]==0){
			v.push_back(make_pair(i, j));
			cnt++;
			}
		}
	}
	sudoku(0);
}