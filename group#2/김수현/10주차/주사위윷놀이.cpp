#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <cstring>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define pll pair<ll,ll>
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};
const int mod = 1e9+7;
using lint = long long;
int a[10],x[4];
vector<pair<vector<int>,int>> path={{{1},0},{{2},2},{{3},4},{{4},6},{{5},8},{{10,6},10},{{7},13},{{8},16},{{9},19},{{25},25},{{11},12},{{12},14},{{13},16},{{14},18},{{17,15},20},{{16},22},{{9},24},{{18},22},{{19},24},{{20},26},{{21},28},{{31,22},30},{{23},28},{{24},27},{{9},26},{{26},30},{{27},35},{{32},40},{{27},38},{{28},36},{{29},34},{{30},32},{{-1},0}};
int move(int cur,int remain, bool first){
	if(remain==0||cur==32){
		return cur;
	}
	if(first){
		return move(path[cur].first.back(),remain-1,false);
	}else{
		return move(path[cur].first[0],remain-1,false);
	}
}
int solve(int cur){
	if(cur==10)return 0;
	int ref=-1e9;
	for(int i=0;i<4;i++){
		if(x[i]==32)continue;
		int next = move(x[i],a[cur],true);
		bool check=false;
		for(int j=0;j<4;j++){
			if(i==j)continue;
			if(next!=32&&next==x[j])check=true;
		}
		if(check)continue;
		int temp = x[i];
		x[i]=next;
		ref = max(ref,solve(cur+1)+path[x[i]].second);
		x[i]=temp;
	}
	return ref;
}

int main(){
	fast
	int ans=0;
	for(int i=0;i<10;i++)cin>>a[i];
	cout<<solve(0);
	return 0;
}
//4^10 완전탐색
