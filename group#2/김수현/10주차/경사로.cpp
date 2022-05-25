#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define pll pair<ll,ll>
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};
const int MOD = pow(10,9)+7;
int b[100][100];
int main(){
    fast    
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    int countn,ans=0;
    for(int i=0;i<n;i++){
        countn=0;
        vector<pair<int,int>> pv;
        for(int j=0;j<n;j++){
            if(j==0){
                countn++;
            }else{
                if(b[i][j]==b[i][j-1]){
                    countn++;
                }else{
                    pv.push_back({b[i][j-1],countn});
                    countn=1;
                }
            }
        }
        pv.push_back({b[i][n-1],countn});
        bool check=true;
        for(int j=0;j<pv.size()-1;j++){
            if(pv[j].first-1==pv[j+1].first){
                if(pv[j+1].second>=l){
                    pv[j+1].second-=l;
                }else {
                    check=false;
                    break;
                }
            }else if(pv[j].first+1==pv[j+1].first){
                if(pv[j].second>=l){
                    pv[j].second-=l;
                }else {
                    check=false;
                    break;
                }
            }else check=false;
        }    

        if(check)ans++;
    }
    for(int i=0;i<n;i++){
        countn=0;
        vector<pair<int,int>> pv;
        for(int j=0;j<n;j++){
            if(j==0){
                countn++;
            }else{
                if(b[j][i]==b[j-1][i]){
                    countn++;
                }else{
                    pv.push_back({b[j-1][i],countn});
                    countn=1;
                }
            }
        }
        pv.push_back({b[n-1][i],countn});
        bool check=true;
        for(int j=0;j<pv.size()-1;j++){
            if(pv[j].first-1==pv[j+1].first){
                if(pv[j+1].second>=l){
                    pv[j+1].second-=l;
                }else {
                    check=false;
                    break;
                }
            }else if(pv[j].first+1==pv[j+1].first){
                if(pv[j].second>=l){
                    pv[j].second-=l;
                }else {
                    check=false;
                    break;
                }
            }else check=false;
        }    
        if(check)ans++;
    }
    cout<<ans;
    
}
