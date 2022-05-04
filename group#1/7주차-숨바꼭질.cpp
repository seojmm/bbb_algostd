#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, K;
queue<int> q;
int time[100001] = {
    0,
}; // 각 인덱스는 해당 좌표에 도착할 때까지 걸린 최소 시간을 의미

int main()
{
    scanf("%d %d", &N, &K);

    // 현재 위치 push
    q.push(N);

    int tmp;
    // bfs 수행
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();

        if (tmp == K)
        {
            printf("%d", time[tmp]);
            break;
        }

        if ((0 <= tmp - 1 && tmp - 1 <= 100000) && !time[tmp - 1])
        {
            q.push(tmp - 1);
            time[tmp - 1] = time[tmp] + 1;
        }
        if ((0 <= tmp + 1 && tmp + 1 <= 100000) && !time[tmp + 1])
        {
            q.push(tmp + 1);
            time[tmp + 1] = time[tmp] + 1;
        }
        if ((0 <= tmp * 2 && tmp * 2 <= 100000) && !time[tmp * 2])
        {
            q.push(tmp * 2);
            time[tmp * 2] = time[tmp] + 1;
        }
    }

    return 0;
}