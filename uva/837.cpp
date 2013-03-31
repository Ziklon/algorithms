#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define sz size()
#define MAX 5000
using namespace std;
struct Point{
    double x1,x2,por;
    
    Point(double _x, double _y, double _por){
        x1=_x;
        x2=_y;
        por=_por;
    }
    void change(){
        if(x1>x2)swap(x1,x2);
    }
};


int N,T;

int main(){
    //freopen("in.txt","r",stdin);
    
    cin>>N;
    
    REP(i,0,N){
        cin>>T;
			
        vector<Point> V;
        set<double> Xs;
        
        
        double x,y,a,b,p;
        REP(j,0,T){
			
            cin>>x>>y>>a>>b>>p; 
            Xs.insert(x);Xs.insert(a);  
			if(x>a)swap(x,a);
            Point p1(x,a,p);        
            V.push_back(p1);
        }
        vector<double> Vx(all(Xs));      
      
        printf("%d\n",Vx.sz+1);    
		printf("-inf %.3f 1.000\n",Vx[0]);
		sort(all(Vx));
		double peki;
		REP(j,1,Vx.sz){
			peki=1.0;		   
			REP(k,0,V.sz){				
				if(V[k].x1<=Vx[j-1] && Vx[j]<=V[k].x2){							
					peki*=V[k].por;
				}
			}
			printf("%.3f %.3f %.3f\n",Vx[j-1],Vx[j],peki);
					
		}
		printf("%.3f +inf 1.000\n",Vx[Vx.sz-1]);
		if((i+1)<N)printf("\n");
    }
    
    
    return 0;    
}