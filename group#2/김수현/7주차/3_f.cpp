#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define pll pair<ll,ll>
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		int l=-1,r=n;
		int lsum=0,rsum=0,ans=0;
		while(l+1<r){
			if(lsum>rsum){
				r--;
				rsum+=a[r];

			}else{
				l++;
				lsum+=a[l];
			}
			if(lsum==rsum){
				ans = l+n-r+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
