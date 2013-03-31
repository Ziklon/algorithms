/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
bool dia[20][20];
int table[20][20],N,K;
long long ans;
void backTrack(int x){
  if(x==K){
    ans++;
    return;
  }
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
       if(dia[i][j]==0){
          
          
          for(int k=1;k<=j;k++)dia[i+k][j-k]=1;
          for(int k=0;k<=N-i;k++)dia[i+k][j+k]=1;
          backTrack(x+1);
          for(int k=1;k<=j;k++)dia[i+k][j-k]=0;
          for(int k=0;k<=N-i;k++)dia[i+k][j+k]=0;
       } 
    }  
}





int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(cin>>N>>K && N && K){
      ans=0;
      fill(dia,0);
      backTrack(0);
      cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
