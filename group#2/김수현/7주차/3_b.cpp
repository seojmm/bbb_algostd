#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,a[20][20];
bool visited[20][20];
int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1,0);
		int ans=-1;
		for(int i=0;i<n;i++){
			int c;
			cin>>c;
			a[c]++;
			if(a[c]>=3)ans=c;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
