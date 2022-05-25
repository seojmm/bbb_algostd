#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
int have[100000];
map<string,int> m;
vector<int> solution(vector<string> gems) {
    int cur=0,count=0;
    for(int i=0;i<gems.size();i++){
        if(!m.count(gems[i]))m.insert({gems[i],cur++});
    }
    int l=0,r=0;
    vector<pair<int,vector<int>>> ans;
    have[m[gems[0]]]++;
    count++;
    if(count==cur){
        vector<int> c = {l+1,r+1};
        ans.push_back({r-l,c});
    }
    while(true){
        if(count<cur||l==r){
            r++;
            if(r==gems.size())break;
            int t = m[gems[r]];
            have[t]++;
            if(have[t]==1){
                count++;
                if(count==cur){
                    vector<int> c = {l+1,r+1};
                    ans.push_back({r-l,c});
                }
            }
        }else{
            int t = m[gems[l]];
            have[t]--;
            if(have[t]==0)count--;
            l++;
            if(count==cur){
                vector<int> c = {l+1,r+1};
                ans.push_back({r-l,c});
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans[0].second;
}
//투포인터 현재 영역에서 모든 종류를 가지고 있으면 왼쪽을 옮기고 그렇지 않다면 오른쪽을 옮긴다. 
//영역의 길이와 영역 벡터를 같이 넣고 정렬해서 길이가 가장 짧으면서도 앞부분의 숫자가 작은 정답이 맨 앞으로 오게한다.
