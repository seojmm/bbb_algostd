#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visited[50];
bool check(string a, string b){
    int count=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])count++;
    }
    return (count==1);
}
int solution(string begin, string target, vector<string> words) {
    queue<pair<string,int>> q;
    q.push({begin,0});
    int ans=0;
    while(!q.empty()){
        string cur = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<words.size();i++){
            if(!visited[i]&&check(cur,words[i])){
                if(words[i]==target) ans=c+1;
                visited[i]=true;
                q.push({words[i],c+1});
            }
        }
    }
    return ans;
}
