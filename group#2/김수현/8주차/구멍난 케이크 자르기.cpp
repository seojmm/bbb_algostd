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

int main(){
	fast
	int n,m,h,v;
	cin>>n>>m;
	int count=0,count2=0;
	cin>>h;
	for(int i=0;i<h;i++){
		int x;
		cin>>x;
		if(x>=-m&&x<=m)count++;
	}
	cin>>v;
	for(int j=0;j<v;j++){
		int x;
		cin>>x;
		if(x>=-m&&x<=m)count2++;
	}
	int ans = (h+1)*(v+1);
	if(count&&count2)ans-=(count-1)*(count2-1);
	if(count==0&&count2>0){
		ans+=count2-1;
	}
	if(count2==0&&count>0){
		ans+=count-1;
	}
	cout<<ans;

	return 0;
}
