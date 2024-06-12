#include <iostream>
#include <vector>
#include <string>
using namespace std;

int len, visited[51];
vector<int> res;

void dfs(string s){
	if(s == ""){
		for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
		exit(0);
	}
	for(int i = 1; i <=2; i++){
		int num = stoi(s.substr(0,i));
		if(num <= len && !visited[num]){
			visited[num] = 1;
			res.push_back(num);
			dfs(s.substr(i, s.size() - i));
			visited[num] = 0;
			res.pop_back();
		}
	}
}


int main(){
	string s;
	cin >> s;
	len = s.size();
	if(len > 9) len = len - (len - 9) / 2;
	dfs(s);
}