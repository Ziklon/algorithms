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
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
using namespace std;



int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int nC,x;
	cin>>nC;
	vector<int> v;
	REP(i,0,nC){
		cin>>x;
		v.push_back(x);
	}
	int a=0;
	int ia=0;
	int ib=0;
	REP(i,0,v.sz)if(v[i]>a){
		ia=i;
		a=v[i];
	}
	a=200;
	REP(i,0,v.sz)if(v[i]<=a){
		ib=i;
		a=v[i];
	}
	int peki=ia+(nC-1-ib);
	if(ia>ib)peki--;
	cout<<peki<<endl;
	
	return 0;

}