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
bool visited[500][500];
char a[500][500];
int dist[500][500];
int main(){
	fast
	int n,m;
	cin>>n>>m;
	int sx,sy;
	queue<pair<int,pair<int,int>>> q;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][j]=s[j];
			if(a[i][j]=='V'){
				sx=i,sy=j;
			}else if(a[i][j]=='J'){
				ex=i,ey=j;
			}else if(a[i][j]=='+'){
				q.push({0,{i,j}});
				visited[i][j]=true;
				dist[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		int cx = q.front().second.first, cy = q.front().second.second;
		int cv = q.front().first;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = cx+dx[i],ny=cy+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
				q.push({cv+1,{nx,ny}});
				visited[nx][ny]=true;
				dist[nx][ny]=cv+1;
			}
		}
	}
	memset(visited,false,sizeof(visited));
	priority_queue<pair<int,pair<int,int>>> pq;
	visited[sx][sy]=true;
	pq.push({dist[sx][sy],{sx,sy}});
	int ans;
	while(!pq.empty()){
		int cx= pq.top().second.first,cy = pq.top().second.second;
		int cv=pq.top().first;
		if(a[cx][cy]=='J')ans=cv;
		pq.pop();
		for(int i=0;i<4;i++){
			int nx = cx+dx[i],ny=cy+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
				pq.push({min(dist[nx][ny],cv),{nx,ny}});
				visited[nx][ny]=true;

			}
		}
	}
	cout<<ans;
	return 0;
} 
//각 칸의 나무까지의 거리를 미리 구하고 거리가 가장 긴 좌표를 우선으로 bfs를 하면 된다.
