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
        vector<int> ans;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')count++;
        }
        for(int i=0;i<count;i++){
            if(s[i]=='1')ans.push_back(i+1);
        }
        for(int i=count;i<n;i++){
            if(s[i]=='0')ans.push_back(i+1);
        }
        if(ans.size()!=0)cout<<1<<'\n';
        cout<<ans.size()<<' ';
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}
