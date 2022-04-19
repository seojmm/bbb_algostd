#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int last=-1,b,c,ans=1e9,lb=-1,lc=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(last!=-1){
                    if(b<=1&&c<=1)ans=min(ans,i-last+1);
                    last=i;
                    if(lb!=-1&&lb+b<=2&&lc+c<=2)ans=min(ans,7);
                    lb=b,lc=c;
                    b=0,c=0;
                    
                }else {
                    last=i;
                    b=0,c=0;
                }
            }else if(s[i]=='b')b++;
            else c++;
        }
        cout<<(ans==1e9?-1:ans)<<'\n';
    }
    
    return 0;
}
