/*
ID: winftc2
PROG: crypt1
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

bool exits(int n, vector<int>& v){
  while(n){
    if(!binary_search(all(v),n%10))return 0;
    n/=10;
  }
  return 1;
}

set<int>S;
vector<int> vv;
void generateA(int k,int n){
  if(k==0){
    S.insert(n);
  }else{
     for(int i=0;i<vv.sz;i++){
        int nn=n*10+vv[i];
        generateA(k-1,nn); 
     } 
  }
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++)cin>>v[i];
    
    sort(all(v));
    S.clear();
    for(int mask=1;mask<(1<<(N));mask++){
        if(__builtin_popcount(mask)>3)continue;
        vector<int> cur;
        for(int i=0;i<N;i++)
          if(mask&(1<<i))
            cur.push_back(v[i]);
        
        vv=cur;
        generateA(3,0);                 
    }
    vector<int> A(all(S));
    S.clear();
    for(int mask=1;mask<(1<<(N));mask++){
        if(__builtin_popcount(mask)>2)continue;
        vector<int> cur;
        for(int i=0;i<N;i++)
          if(mask&(1<<i))cur.push_back(v[i]);
        vv=cur;
        generateA(2,0);       
    }
    
    vector<int> B(all(S));
    int ans=0;
    for(int i=0;i<A.sz;i++){
      for(int j=0;j<B.sz;j++){
          int x=A[i]*(B[j]%10);
          int y=A[i]*(B[j]/10);
          int z=A[i]*B[j];
          if(x>=100 && x<=999 && y>=100 && y<=999 && z>=1000 && z<=9999){
            if(exits(x,v) && exits(y,v) && exits(z,v))
              ans++; 
          }
          
      }
    }
    cout<<ans<<endl;  
    //system("pause");
    return 0;
}
