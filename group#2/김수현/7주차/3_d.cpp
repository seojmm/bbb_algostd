#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,a[20][20];
bool visited[20][20];
int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		bool ans=true;
		string s;
		cin>>n>>s;
		int start = 0;
		vector<string> v;
		string curs;
		for(int i=0;i<n;i++){
			if(curs!=""&&s[i]=='W'){
				v.push_back(curs);
				curs.clear();
			}
			if(s[i]!='W')curs+=s[i];
		}
		if(curs!="")v.push_back(curs);
		for(int i=0;i<v.size();i++){
			if(v[i]==string(v[i].size(),'R')||v[i]==string(v[i].size(),'B')){
				ans=false;
			}
		}

		cout<<(ans?"YES\n":"NO\n");
	}
	return 0;
}
