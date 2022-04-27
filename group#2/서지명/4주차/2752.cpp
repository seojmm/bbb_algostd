#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int num[3];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for(int i=0; i<3; i++) cin >> num[i];

  int min, index, tmp;

  for(int i=0; i<3; i++){
    min = 1000001;
    for(int j=i; j<3; j++){
      if(min > num[j]){
        min = num[j];
        index = j;
      }
    }
    if(num[i] > min){
      tmp = num[i];
      num[i] = num[index];
      num[index] = tmp;
    }

  }

  for(int i=0; i<3; i++){
    printf("%d ", num[i]);
  }
  
  return 0;
}