#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
vector<string> ans;
map<string,queue<string>> m;
void dfs(string cur){
    while(!m[cur].empty()){
        string next= m[cur].front();
        m[cur].pop();
        dfs(next);
    }
    ans.push_back(cur);
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    for(int i=0;i<tickets.size();i++){
        m[tickets[i][0]].push(tickets[i][1]);
    }
    dfs("ICN");
    reverse(ans.begin(),ans.end());
    return ans;
}
