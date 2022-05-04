#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int M, N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[101][101];
vector<vector<int>> picture;

int dfs(int x, int y)
{
    int ret = 1;
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (visited[nx][ny])
            continue;
        if (picture[x][y] != picture[nx][ny])
            continue;

        ret += dfs(nx, ny);
    }

    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> graph)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    picture = graph;
    memset(visited, 0, sizeof(visited));

    M = m;
    N = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && picture[i][j] != 0)
            {
                max_size_of_one_area = max(max_size_of_one_area, dfs(i, j));
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}