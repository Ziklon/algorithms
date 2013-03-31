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
int A[3][3],B[3][3];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   REP(i,3)REP(j,3)cin>>A[i][j],B[i][j]=1;
   
   REP(i,3)REP(j,3){
        REP(k,A[i][j]&1){
            B[i][j]=(B[i][j]^1);    
            REP(m,4){
                int x=i+dx[m];
                int y=j+dy[m];
                if(min(x,y)>=0 && max(x,y)<3)
                    B[x][y]=(B[x][y]^1);
            }
        }
   }
   REP(i,3){
        REP(j,3)cout<<B[i][j];
        cout<<endl;
   }    
   return 0;      
}
