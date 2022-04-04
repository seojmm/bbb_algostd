#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string,int> m,summ;
    vector<pair<string,int>> v;
    for(int i=0;i<records.size();i++){
        string name = records[i].substr(6,4);
        int temp = ((records[i][0]-'0')*10+records[i][1]-'0')*60+(records[i][3]-'0')*10+records[i][4]-'0';
        if(records[i].size()==13){
            m[name]=temp;
            cout<<"in"<<temp<<'\n';
        }else{
            cout<<"out"<<temp<<'\n';
            summ[name]+= temp-m[name];
            m[name]=-1;
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second!=-1){
            summ[it->first]+=23*60+59-it->second;
        }
    }   
    for(auto it=summ.begin();it!=summ.end();it++){
        v.push_back({it->first,it->second});
    }                         
    sort(v.begin(),v.end());
    vector<int> answer(v.size());                        
    for(int i=0;i<v.size();i++){
        int temp = v[i].second;
        answer[i]=fees[1];
        if(v[i].second-fees[0]>0){
            answer[i]+=(v[i].second-fees[0])/fees[2]*fees[3];
            if((v[i].second-fees[0])%fees[2]!=0)answer[i]+=fees[3];
        }
    }
    
    return answer;
}
