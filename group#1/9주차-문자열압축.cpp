#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for(int token=1; token<=s.length()/2; token++){
        string tmp = "";
        string ans = "";
        int cnt = 1;
        tmp = s.substr(0, token);
        for(int i=token; i<s.length(); i+=token){
            if(s.substr(i, token) == tmp) cnt++;
            else{
                if(cnt > 1) ans += to_string(cnt);
                ans += tmp;
                tmp = s.substr(i, token);
                cnt = 1;
            }
        }
        if(cnt > 1) ans += to_string(cnt);
        ans += tmp;
        if(answer > ans.length()) answer = ans.length();

    }

    return answer;
}