#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


int main(void) {
    int n;
    cin >> n;
   

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        int map[11][11] = {0,};
        int row[11] = {0,};
        int col[11] = {0,};
        for(int j = 0; j < m; j++){
            string s;
            cin >> s;
            map[s[0] - 'a'][s[1] - 'a'] += 1;
            row[s[0] - 'a'] += 1;
            col[s[1] - 'a'] += 1;
        }
        long long ans = 0;
        for(int j = 0; j < 11; j++){
            for(int k = 0; k < 11; k++){
                ans += 1ll * map[j][k] * (row[j] + col[k] - 2 * map[j][k]);
            }
        }
        cout << ans / 2 << endl;
    }

    return 0;
}