#include <iostream>
using namespace std;

class BlackJack
{
    int n; // 카드의 개수
    int m;
    int answer = 0;
    int cards[100];

public:
    BlackJack()
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> cards[i];
        }

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if ((cards[i] + cards[j] + cards[k]) <= m && answer < (cards[i] + cards[j] + cards[k]))
                    {
                        answer = cards[i] + cards[j] + cards[k];
                    }
                }
            }
        }
        cout << answer;
    }
};

int main()
{
    BlackJack t;

    return 0;
}