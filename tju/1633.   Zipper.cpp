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
int N,M;
string a,b,c,d,e;
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   cin>>N;
   REP(t,N){
        cin>>a>>b>>c;
        M=min(a.size(),b.size());
        d=e="";
        for(int i=0;i<M;i++){
            d+=string(1,a[i]);
            d+=string(1,b[i]);
            e+=string(1,b[i])+string(1,a[i]);
        }
        if(a.size()!=b.size()){
            if(a.size()>b.size()){
                d+=string(1,a[M]);
            }else{
                e+=string(1,b[M]);
            }            
        }
        cout<<d<<" "<<e<<endl;
        
        if(d==c || e==c)cout<<"Data set "<<(t+1)<<": yes"<<endl;
        else cout<<"Data set "<<(t+1)<<": no"<<endl;
        
   }
   return 0;      
}
