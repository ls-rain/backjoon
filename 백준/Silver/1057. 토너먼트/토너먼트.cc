#include <vector>
#include <iostream>
using namespace std;

int n, kim, im, cnt;
//홀수 일때 마지막 한명 부전승
//라운드 마다 참가자의 번호를 순서 유지하며, 다시 번호 매김
int main(){
	cin >> n >> kim >> im;
	while (kim != im) {
		cnt++;
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;
	}
	cout << cnt;
}
