#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x < 1400){
            cout << "Division 4" << endl;
        } 
        else if(x < 1600){
            cout << "Division 3" << endl;
        }
        else if(x < 1900){
            cout << "Division 2" << endl;
        }
        else {
            cout << "Division 1" << endl;
        }
    }

    return 0;
}
