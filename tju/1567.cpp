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
long long gcd(long long a, long long b){return __gcd(a,b);}
struct line{
	int x1,x2,y2,y1;
	int A,B,C;
	void calc(){
		A=y2-y1;
		B=x1-x2;
		C=A*x1+B*y1;	
	}	
};
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int nC;
  cin>>nC;
  while(nC--){
	line X,Y;
	cin>>X.x1>>X.y1>>X.x2>>X.y2>>Y.x1>>Y.y1>>Y.x2>>Y.y2;
	X.calc();
	Y.calc();
	double det=X.A*Y.B-Y.A*X.B;
	if(det==0){
		if((X.x1-X.x2)*(Y.y1-Y.y2)==(Y.x1-Y.x2)*(X.y1-X.y2))
			printf("LINE\n");
		else
			printf("NONE\n");	
	}else{
		double x = (Y.B*X.C - X.B*Y.C)/det;
        double y = (X.A*Y.C - Y.A*X.C)/det;
		printf("%.2f %.2f\n",x,y);		
	}
  }
  //system("pause");
  return 0;
}
