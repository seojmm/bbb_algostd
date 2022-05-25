#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        a[i] = make_pair(u,v);
    }
    
    sort(a.begin(),a.end());
    
    int d[n];
    
    for(int i=0;i<n;i++){
        d[i]=1;
        for(int j=0;j<i;j++){
            if(a[j].second<a[i].second&&d[j]>=d[i]){
                d[i] = d[j]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans, d[i]);
    }
    
    cout<<n-ans;
    return 0;
}
