/*
ID: winftc2
PROG: milk
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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
string B=" ",aux,cif;
vector<string> dic;
map<char,int>M;
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    while(getline(cin,aux)){
      if(aux=="#")break;
      dic.push_back(aux);
    }
    M[' ']=0;
    getline(cin,cif);
    
    for(int i=0;i<26;i++){
      B+=('A'+i);
      M[('A'+i)]=i+1;
    }
    sort(all(dic));
    int k=0;
    int cnt=0;
    for(int i=0;i<28;i++){
      aux=cif;
      for(int j=0;j<cif.sz;j++){
        int x=(M[cif[j]]+i)%27;
        aux[j]=B[x];       
      }
      stringstream ss(aux);
      int xx=0;
      while(ss>>aux){
        if(binary_search(all(dic),aux))
          xx++;
      }
      
      if(xx>cnt){
        cnt=xx;
        k=i;
      }
    }
    REP(i,0,cif.sz){
      int x=(M[cif[i]]+k)%27;
      cif[i]=B[x]; 
    }
    printf("%s\n",cif.c_str());
    
    
   return 0;
}
