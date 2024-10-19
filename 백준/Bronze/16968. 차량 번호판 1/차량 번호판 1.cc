#include <iostream>

using namespace std;

string s;
int res = 1;

int main() {
    cin >> s;
    int c = 26;
    int n = 10;
    char prev;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'c') {
            if (prev == 'c') {
                res *= (c - 1);
            } else {
                res *= c;
            }
            prev = 'c';
        } else {
            if (prev == 'd') {
                res *= (n - 1);
            } else res *= n;
            prev = 'd';
        }
    }
    cout << res;
}
