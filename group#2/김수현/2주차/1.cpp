#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string,int> m;
    vector<set<string>> vs(id_list.size(),set<string>());
    for(int i=0;i<id_list.size();i++){
        m[id_list[i]] = i;
    }
    for(int i=0;i<report.size();i++){
        string temp1="",temp2="";
        for(int j=0;j<report[i].size();j++){
            if(report[i][j]!=' ')temp1+=report[i][j];
            else{
                for(int k=j+1;k<report[i].size();k++){
                    temp2+=report[i][k];
                }
                if(!vs[m[temp2]].count(temp1)){
                    vs[m[temp2]].insert(temp1);
                }
                break;
            }
        }
    }
    vector<int> answer(id_list.size(),0);
    for(int i=0;i<id_list.size();i++){
        if(vs[i].size()>=k){
            for(auto it=vs[i].begin();it!=vs[i].end();it++){
                answer[m[*it]]++;
            }
        }
    }
    
    return answer;
}
