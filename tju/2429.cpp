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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
int A[20005];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    char dna[25];
    while(scanf("%d %d\n",&n,&m)==2 && n && m){
        map<string,int>M;
        REP(i,0,n){
          scanf("%s\n",dna);
          A[i+1]=0;
          M[dna]++;
        }
        foreach(M,it)
          A[it->second]++;
        
        REP(i,0,n){
          printf("%d\n",A[i+1]);
        }     
    } 
    //system("pause");
    return 0;
}
