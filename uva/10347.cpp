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
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	double m1,m2,m3;
	double a,b,c,area,S;
	while(cin>>m1>>m2>>m3){
		a=(8*m2*m2)+(8*m3*m3)-(4*m1*m1);
		b=(8*m1*m1)+(8*m3*m3)-(4*m2*m2);
		c=(8*m2*m2)+(8*m1*m1)-(4*m3*m3);
		a=sqrt(a)/3.0;
		b=sqrt(b)/3.0;
		c=sqrt(c)/3.0;
		double A[]={a,b,c};
		sort(A,A+3);
		S=(a+b+c)/2.0;
		area=sqrt(S*(S-a)*(S-b)*(S-c));
		if(A[2]<(A[1]+A[0]) && area>0.0){
			printf("%0.3f\n",area);
		}else
			printf("-1.000\n");
	}
	return 0;
}