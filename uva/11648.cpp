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

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
    double T,a,b,c,d;
    cin>>T;
    double h,ha,hi,lo;
    long long x,y;
    double x1,x2,r1,s1,pp,tt;
    long long p,q,r;
    REP(i,0,T){
      
      cin>>a>>c>>d>>b;

      ha=((a+c)*sqrt((-a+b+c+d)*(a-b+c+d)*(a-b+c-d)*(a-b-c+d)))/(4.0*(a-c));
      h=sqrt((4*(a-c)*(a-c)*d*d)-(( d*d+((a-c)*(a-c)) -(b*b))*( d*d+((a-c)*(a-c)) -(b*b))))/(2.0*(a-c));
      ha=(a+c)*h/2;
      lo=0;
      hi=h;
      cout<<h<<" "<<ha<<" "<<b<<" "<<d<<endl;
      
      for(int i=0;i<50;i++){
        double h1=(hi+lo)/2.0;
        x1=(h1*d)/h;
        x2=(h1*b)/h;
        
        s1=sqrt((x1*x1)-(h1*h1));
        r1=sqrt((x2*x2)-(h1*h1));
        //cout<<x1<<" "<<x2<<" "<<h1<<" "<<s1<<" "<<r1<<endl;
        pp=a-s1-r1;
        tt=((pp+a)*h1);
        if(tt>=ha || x1<=h1 || x2<=h1)
          hi=h1;  
        else
          lo=h1;
                
      }
      x1=(lo*d)/h;
      x2=(lo*b)/h;
      printf("Land #%d: %.8f %.8f\n",i+1,x1,x2);
      
    }
   //system("pause");
   return 0;
}
