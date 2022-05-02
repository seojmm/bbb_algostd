#include <string>
#include <vector>

using namespace std;
int ans=0;
void dfs(int cur,int sum, vector<int> &numbers, int &target){
    if(cur==numbers.size()){
        if(sum==target)ans++;
    }else{
        dfs(cur+1,sum+numbers[cur],numbers,target);
        dfs(cur+1,sum-numbers[cur],numbers,target);
    }
    
}
int solution(vector<int> numbers, int target) {
    dfs(0,0,numbers,target);
    return ans;
}
