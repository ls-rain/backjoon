#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;
    for(int i = 0; i < phone_book.size(); i++){
        m[phone_book[i]] = 1;
    }
    for(int i = 0; i < phone_book.size(); i++){
        for(int j = 0; j < phone_book[i].size(); j++){
            string phone_num = phone_book[i].substr(0, j);
            if(m[phone_num]) return false;
        }
    }

    return answer;
}