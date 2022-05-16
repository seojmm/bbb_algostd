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
        vector<int> v;
        bool ans = true;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(int j = 2; j < m; j++){
            if(v[j] % 2 != v[j - 2] % 2){
                ans = false;
            }
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}