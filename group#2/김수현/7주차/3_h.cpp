#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define pll pair<ll,ll>
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};
char a[50][50];
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		ll ans=0;
		for(int i=30;i>=0;i--){
			int count=0;
			for(int j=0;j<n;j++){
				if((a[j]&(1<<i))==0)count++;
			}
			if(k>=count){
				ans+=(1<<i);
				k-=count;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
