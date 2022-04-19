#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isprime(long long n){
    bool ref=true;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            ref=false;
            break;
        }
    }
    if(n==1||n==0)ref=false;
    return ref;
}
int solution(int n, int k) {
    string s;
    while(true){
        if(n/k==0){
            s+=n+'0';
            break;
        }
        s+=(n%k)+'0';
        n/=k;
    }
    reverse(s.begin(),s.end());
    long long cur=0,ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(isprime(cur))ans++;
            cur=0;
        }else{
            cur = cur*10+s[i]-'0';
        }
    }
    if(isprime(cur))ans++;
    return ans;
}
