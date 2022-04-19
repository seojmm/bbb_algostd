#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int a=0,b=0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]!=0){
            if(find(win_nums.begin(), win_nums.end(), lottos[i])!=win_nums.end()){
                a++;
            }
        }else b++;
        
    }
    vector<int> answer;
    if(a+b==0)answer.push_back(6);
    else answer.push_back(7-a-b);
    
    if(a==0)answer.push_back(6);
    else answer.push_back(7-a);
    
    return answer;
}
