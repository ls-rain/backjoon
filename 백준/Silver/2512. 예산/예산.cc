#include <iostream>
#define MAX 10001
using namespace std;

int n, m;
int local[MAX];

int main(){
	cin >> n;
	int left = 0; int right = 0;
	for(int i = 0; i<n; i++){
		cin >> local[i];
		right = max(right, local[i]);
	}
	cin >> m;
	
	while(left <= right){
		int sum = 0;
		int mid = (left+right)/2;
		for(int i = 0; i<n; i++){
			if(mid > local[i]) sum+=local[i];
			else sum+=mid;
		}
		if(sum <=m) left = mid +1;
		else right = mid -1;
	}
	cout << right;
	return 0;
}