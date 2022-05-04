#include <iostream>
#include <vector>
using namespace std;
bool visited[100000];
vector<int> a[100000];
int ans,n,s,d;
int dfs(int cur){
	visited[cur]=true;
	int depth=0;
	for(int i=0;i<a[cur].size();i++){
		int next = a[cur][i];
		if(!visited[next]){
			int temp = dfs(next);
			if(temp<d)ans-=2;
			depth=max(temp+1,depth);
		}
	}
	return depth;
}
int main(){
	cin>>n>>s>>d;
	s--;
	ans=(n-1)*2;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(s);
	cout<<ans;
	return 0;
}
