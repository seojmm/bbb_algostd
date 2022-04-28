#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int answer = 0;
    int rope[100000];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &rope[i]);
    }

    sort(rope, rope + N);

    for (int i = 0; i < N; i++)
    {
        answer = max(answer, (N - i) * rope[i]);
    }

    printf("%d", answer);

    return 0;
}