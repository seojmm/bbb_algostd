#include <string>
#include <vector>

using namespace std;

vector<int> solution(int r, int c, vector<vector<int>> q) {
    vector<vector<int>> a(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[i][j]=i*c+1+j;
        }
    }
    vector<int> answer;
    for(int i=0;i<q.size();i++){
        int x1=q[i][0]-1,x2=q[i][2]-1,y1=q[i][1]-1,y2=q[i][3]-1;
        int minnum = 10000;
        int cur = a[x1][y1];
        for(int j=y1+1;j<=y2;j++){
            minnum = min(minnum,cur);
            int temp = a[x1][j];
            a[x1][j]=cur;
            cur = temp;
        }
        for(int j=x1+1;j<=x2;j++){
            minnum = min(minnum,cur);
            int temp = a[j][y2];
            a[j][y2]=cur;
            cur = temp;
        }
        for(int j=y2-1;j>=y1;j--){
            minnum = min(minnum,cur);
            int temp = a[x2][j];
            a[x2][j]=cur;
            cur = temp;
        }
        for(int j=x2-1;j>=x1;j--){
            minnum = min(minnum,cur);
            int temp = a[j][y1];
            a[j][y1]=cur;
            cur=temp;
        }
        minnum = min(minnum,cur);
        answer.push_back(minnum);
    }
    
    return answer;
}
