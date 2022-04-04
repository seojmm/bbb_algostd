#include <string>
#include <vector>

using namespace std;
int maxn=0;
vector<int> ans(10,0);
bool com(vector<int> &a, vector<int> &b){
    for(int i=10;i>=0;i--){
        if(a[i]>b[i]){
            return true;
        }else if(a[i]<b[i]){
            return false;
        }
    }
}
void solve(vector<int> &in,vector<int>& v,int temp,int n){
    if(temp==11){
        int sum=0,ot=0;
        for(int i=0;i<11;i++){
            if(v[i]>in[i]){
                sum += 10-i;
            }else if(in[i]!=0&&in[i]>=v[i]){
                sum -= 10-i;
            }
        }
        if(sum>maxn){
            ans = v;
            maxn = sum;
        }else if(sum==maxn){
            if(com(v,ans)){
                ans = v;
            }
        }
        return;
    }
    for(int i=0;i<=n;i++){
        v[temp]=i;
        solve(in,v,temp+1,n-i);
    }
}
vector<int> solution(int n, vector<int> info) {
    vector<int> v(11,0);
    solve(info,v,0,n);
    vector<int> answer = ans;
    if(maxn==0)return {-1};
    return answer;
}
