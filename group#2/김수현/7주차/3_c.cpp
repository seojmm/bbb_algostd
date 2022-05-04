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
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		int u=a[0]%2,v=a[1]%2;
		bool ans= true;
		for(int i=2;i<n;i++){
			if(i%2==0){
				if(u!=a[i]%2)ans=false;
			}else{
				if(v!=a[i]%2)ans=false;
			}
		}
		cout<<(ans?"YES\n":"NO\n");
	}
	return 0;
}
