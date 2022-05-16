#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        string s;
        cin >> s;
        bool ans = true;
        vector<string> subs = split(s,'W');
        for(auto k:subs){
            int r = 0, b = 0;
            for(auto c:k){
                if(c == 'R'){
                    r += 1;
                }
                else if(c == 'B'){
                    b += 1;
                }
            }
            if(r + b > 0 && (r == 0 || b == 0)) ans = false;
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}