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
		cout<<"Division ";
		if(n<=1399)cout<<4;
		else if(n<=1599)cout<<3;
		else if(n<=1899)cout<<2;
		else cout<<1;
		cout<<'\n';
		}
	return 0;
}
