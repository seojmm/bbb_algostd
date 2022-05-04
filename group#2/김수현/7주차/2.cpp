#include <vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdlib> // abs
#include<set>

using ll = int64_t;
using namespace std;
int a[20][20];
bool visited[20][20];
int n;
int ans=0;
bool isSur[13];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
struct Pos{
    int x,y,d;
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin>>n;
    int x,y;
    int curSize=2;
    int curEat=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            visited[i][j]=false;
            if(a[i][j]==9){
                x=i;
                y=j;
            }
        }
    }
    while(true){
        //find
        queue<Pos> q;
        //cout<<x<<" "<<y<<'\n';
        //Pos pos = {x, y, 0};
        q.push({x,y,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=false;
            }
        }
        visited[x][y]=true;
        vector<pair<int,int> > v;
        int minDis=987654321;
        while(!q.empty()){
            int tx = q.front().x;
            int ty = q.front().y;
            int td = q.front().d;
            q.pop();
            if(td>=minDis)break;
            for(int i=0;i<4;i++){
                int nx = tx + dx[i];
                int ny = ty + dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n){
                    if((a[nx][ny]==curSize||a[nx][ny]==0)&&visited[nx][ny]==false){
                        q.push({nx, ny, td+1});
                        visited[nx][ny]=true;
                    }else if(a[nx][ny]!=9&&a[nx][ny]!=0&&a[nx][ny]<curSize){
                        minDis=td+1;
                        v.emplace_back(make_pair(nx,ny));
                    }
                }
            }
        }
        if(minDis==987654321)break;
        else {
            ans+=minDis;
            curEat++;
            if(curEat>=curSize){
                curEat=0;
                curSize++;
            }
            sort(v.begin(),v.end());
            int nx = v[0].first;
            int ny = v[0].second;
            a[x][y]=0;
            a[nx][ny]=9;
            x = nx;
            y = ny;
        }
    }
    cout<<ans;
    return 0;
}
