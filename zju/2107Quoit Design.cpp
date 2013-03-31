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
#define MAXN 100000
#define EPS 1e-6
int N;
double x,y,xx,yy;
double X[MAXN];
double Y[MAXN];

bool check(double r){
    REP(i,N)
        if(hypot(X[i]-xx,Y[i]-yy)>r)return 0;
    return 1;
}
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(cin>>N){
        if(N==0)break;   
        xx=0;
        yy=0;
        REP(i,N){
            cin>>X[i]>>Y[i];
            xx+=X[i];
            yy+=Y[i];
        }        
        xx/=2;
        yy/=2;
        double low=0;
        double hih=1e+10;
        //cout<<xx<<" "<<yy<<endl;
        
        while(hih-low>EPS){
            double mid=(low+hih)/2;
            if(check(mid))
                hih=mid;
            else
                low=mid;
        }
        printf("%.2f\n",hih); 
        
   }
   return 0;      
}
