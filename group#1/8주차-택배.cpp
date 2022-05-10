#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int, int>> graph[201];
int dist[201];
int pos[201]; // pos[i] = j : i 이전 정점이 j

void dijkstra(int start){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int cur = pq.top().first;
        int d = -pq.top().second;
        pq.pop();

        if(dist[cur] < d) continue;
        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int nextD = d + graph[cur][i].second;

            if(nextD < dist[next]){
                dist[next] = nextD;
                pq.push({next, -nextD});
                pos[next] = cur;
            }

        }
    }

    for(int i=1; i<=n; i++){
        if(i == start) printf("- ");
        else if(pos[i] == start) printf("%d ", i);
        else{
            int curNode = i;
            while(1){
                if(pos[curNode] == start){
                    printf("%d ", curNode);
                    break;
                }
                curNode = pos[curNode];
            }
        }
    }
    printf("\n");
}

int main(){
    scanf("%d %d", &n, &m);
    int a, b, w;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &w);
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    for(int i=1; i<=n; i++){
        dijkstra(i);
    }

    return 0;
}