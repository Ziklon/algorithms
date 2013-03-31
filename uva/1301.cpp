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
char prod[20];
double rnd(double r){
	double a=r*100;
	a=round(a);
	return a/100.0;	
}


int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  vector<double> vd;
  int nC;
  double aux,avg;
  while(cin>>nC){
	if(nC==0)break;
	vd.clear();
	avg=0;
	for(int i=0;i<nC;i++){
		cin>>aux;
		vd.push_back(aux);
		avg+=aux;
	}
	avg=rnd(avg/nC);
	aux=0;
	for(int i=0;i<vd.sz;i++){
		if(vd[i]>avg)
			aux+=vd[i]-avg;
	}
	printf("$%0.2f\n",aux);
		
  }
  
  system("pause");
  return 0;
}
