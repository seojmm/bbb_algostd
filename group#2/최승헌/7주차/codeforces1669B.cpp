#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m, j;
        bool b = true;
        cin >> m;
        int arr[200001] = {0, };
        for(j = 0; j < m; j++){
            int x;
            cin >> x;
            arr[x]++;
            if(arr[x] == 3 && b != false) {
                cout << x << endl;
                b = false;
            }
        }
        if(b && j == m) cout << -1 << endl;
    }

    return 0;
}