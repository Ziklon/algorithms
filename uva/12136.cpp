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
string a,b,c,d;
int N;
int aTs,aFs,cTs,cFs;
int getTime(string s){
	int x,y,ans;
	sscanf(s.c_str(),"%d:%d",&x,&y);
	ans=x*60+y;
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	cin>>N;
	REP(i,0,N){
		cin>>a>>b>>c>>d;
		aTs=getTime(a);
		aFs=getTime(b);		
		cTs=getTime(c);
		cFs=getTime(d);
		printf("Case %d: ",i+1);
		if(cFs<aTs || cTs>aFs)
			printf("Hits Meeting");
		else
			printf("Mrs Meeting");
		printf("\n");
		
		
	}
	return 0;
}