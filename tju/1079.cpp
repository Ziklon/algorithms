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
int toi(string s){istringstream is(s);int x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
string line;
long long pw=8;
double dev=0;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  
 
  	
  while(cin>>line){
  	dev=0;
  	pw=8;
	for(int i=2;i<line.sz;i++){
		double n=(line[i]-'0');
		dev=dev+ (n/pw);
		pw*=8;	
	}
	//cout<<line<<" [8] = "<<dev<<" [10]"<<endl;
	printf("%s [8] = %lf [10]\n",line.c_str(),dev);
  }
  //system("pause");
  
  return 0;
}
