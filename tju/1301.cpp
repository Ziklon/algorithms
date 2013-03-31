#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

long double rnd(double r){
	long double a=r*100.0;
	a=round(a);
	a=a/100.0;
	return a;	
}


int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  vector<double> vd;
  int nC,sm;
  long double aux,avg;
  while(cin>>nC){
	if(nC==0)break;
	vd.clear();
	avg=0;
	sm=0;
	for(int i=0;i<nC;i++){
		cin>>aux;
		//cout<<aux<<endl;
		avg+=aux;
		vd.pb(aux);		
	}
	avg=avg/(nC*1.0);
	avg=rnd(avg);
	aux=0;
	for(int i=0;i<vd.sz;i++){
		if(1.0*vd[i]>avg)
			aux+=(vd[i]-avg);
	}
	aux=aux*100.0;
	//cout<<aux<<endl;
	int a=(int)((aux)/100);
	int b=(int)(aux+0.5)%100;
	printf("$%d.%02d\n",a,b);	
  }
  
  //system("pause");
  return 0;
}
