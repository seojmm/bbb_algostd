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
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				a[i][j]=s[j];
			}
		}
		for(int i=0;i<m;i++){
			queue<int> q;
			for(int j=n-1;j>=0;j--){
				if(a[j][i]=='*')q.push(j);
			}
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				a[cur][i]='.';
				for(int j=cur+1;j<=n;j++){
					if(j==n||a[j][i]=='*'||a[j][i]=='o'){
						a[j-1][i]='*';
						break;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<a[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}
