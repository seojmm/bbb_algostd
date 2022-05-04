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
	int a[11][11];
	while(t--){
		memset(a,0,sizeof(a));
		ll n,ans=0;
		string s;
		cin>>n;
		vector<string> v;
		for(int i=0;i<n;i++){
			cin>>s;
			v.push_back(s);
			for(int j=0;j<11;j++){
				if(s[1]-'a'==j)continue;
				a[s[0]-'a'][j]++;
			}
			for(int j=0;j<11;j++){
				if(s[0]-'a'==j)continue;
				a[j][s[1]-'a']++;
			}
		}
		for(int i=0;i<n;i++){
			ans+=a[v[i][0]-'a'][v[i][1]-'a'];
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
