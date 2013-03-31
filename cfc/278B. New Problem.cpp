#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
int N;
char buff[30];
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d\n",&N);
   vector<string> vs(N);
    REP(i,N){
       scanf("%s\n",buff);
       vs[i]=buff;     
    }
  queue<string>Q;
  REP(i,26)Q.push(string(1,'a'+i));
  string ans;
  while(!Q.empty()){
      string cur=Q.front();Q.pop();
      bool flag=1;
      REP(i,N)if(vs[i].find(cur)!=-1)flag=0;
      if(flag){
        ans=cur;
        break;
      }
      REP(i,26){
          Q.push(cur+string(1,'a'+i));          
      }
    
  }
  printf("%s\n",ans.c_str());     
    
  return 0;      
}
