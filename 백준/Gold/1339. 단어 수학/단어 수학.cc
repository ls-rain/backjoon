#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, call, con[26], len[10];
char a[10][10];

bool comp(int a, int b) {return a>b;}

int main(){
	cin >> n;
	int res = 0;
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		len[i] = s.length();
		for(int j = 0; j<len[i]; j++)
			a[i][j] = s[j];
	}
	for(int i = 0; i<n; i++){
		call = 1;
		for(int j = len[i]-1; j>=0; j--){
			con[a[i][j]-'A'] += call;
			call *= 10;
		}
	}
	sort(con, con+26, comp);
	for(int i = 0; i<10; i++) res+=con[i]*(9-i);
	cout << res;
}
