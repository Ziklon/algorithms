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
int N,C;
char cad[1<<6];
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   map<string,int> M;
   scanf("%d",&N);
   REP(t,N){
        scanf("%s\n",cad);        
        if(M.count(cad))
            printf("%s%d\n",cad,M[cad]);
        else
            printf("OK\n");
        M[cad]++;
   }
   return 0;      
}
