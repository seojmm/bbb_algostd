#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
#define ll long long
ll solve(vector<pair<char,ll>> &v,vector<int> &a){
    ll ref=0;
    vector<pair<char,ll>> temp[2];
    for(int i=0;i<v.size();i++){
        temp[0].push_back(v[i]);
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<temp[i%2].size();j++){
            if(temp[i%2][j].second==a[i]&&temp[i%2][j].first=='c'){
                if(a[i]==-3)temp[(i%2)^1].back().second-=temp[i%2][j+1].second;
                else if(a[i]==-2)temp[(i%2)^1].back().second+=temp[i%2][j+1].second;
                else temp[(i%2)^1].back().second*=temp[i%2][j+1].second;
                j++;
            }else{
                temp[(i%2)^1].push_back(temp[i%2][j]);
            }
        }
        temp[i%2].clear();
    }
    assert(temp[1].size());
    return abs(temp[1].back().second);
}
long long solution(string e) {
    vector<pair<char,ll>> v;
    ll temp=0;
    for(int i=0;i<e.size();i++){
        if(e[i]>='0'&&e[i]<='9'){
            temp*=10;
            temp+=(int)e[i]-'0';
        }else{
            v.push_back({'i',temp});
            temp=0;
            if(e[i]=='-')v.push_back({'c',-3});            //'c'는 연산자, 'i'는 피연산자
            else if(e[i]=='+')v.push_back({'c',-2});
            else v.push_back({'c',-1});
        }
    }
    v.push_back({'i',temp});
    vector<int> a = {-3,-2,-1};
    long long ans = 0;
    do{
        ans = max(ans,solve(v,a));
    }while(next_permutation(a.begin(),a.end()));
    return ans;
}
//어떤 연산자를 먼저 계산할지 6가지 경우의 수를 모두 해본다.
