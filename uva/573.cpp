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
int H,U,D,F;

int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d %d %d %d",&H,&U,&D,&F)==4 && H){
		
		
		H=H*100;
		U=U*100;
		D=D*100;
		long long initial=0;
		long long climBed=U;
		long long afterClimb=U;
		long long afterSlid=U-D;
		long long percen=(U*F)/100;		
		int day=1;
		
		while(afterClimb<=H && afterSlid>=0){			
			initial=afterSlid;			
			climBed=max(0LL,U-(day*percen));
			
			afterClimb=initial+climBed;
			afterSlid=afterClimb-D;	
			
			day++;
										
		}
		if(afterClimb>H)printf("success");
		else printf("failure");
		
		printf(" on day %d\n",day);
		
	}
	return 0;	
}