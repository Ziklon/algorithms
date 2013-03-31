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

int N,p,q,ans,start,key_cnt;
string cad;

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(scanf("%d\n",&N)==1 && N){
        getline(cin,cad);
        ans=0;
        start=0;
        key_cnt=0;
        vector<int> cont(256,0);
        REP(i,cad.size()){
            if(cont[cad[i]]==0)key_cnt++;
            cont[cad[i]]++;            
            while(start<i && key_cnt>N){
                if(cont[cad[start]]==1)key_cnt--;
                cont[cad[start]]--;
                start++;
            }
            ans=max(ans,i-start+1);
        }
        printf("%d\n",ans);
   }
   return 0;      
}
