#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v[100001];
int visited[100001], dis[100001];
int ans = 0;
int n, s, d;


int cal_dis(int cur){
    visited[cur] = 1;
    int max_dis = 0; 
    for(int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];
        if(visited[next] == 0) {
            max_dis = max(max_dis, cal_dis(next));
        }
    }
    dis[cur] = max_dis;
    return max_dis + 1;
}

void cal_ans(int cur){
    visited[cur] = 1;
    
    for(int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];
        if(visited[next] == 0){
            if(dis[next] >= d) ans++;
            cal_ans(next);
        }
    }
}

int main(void) {
    cin >> n >> s >> d;

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
	cal_dis(s);

	memset(visited, 0, sizeof(visited));
	cal_ans(s);
    cout << ans * 2;

    return 0;
}