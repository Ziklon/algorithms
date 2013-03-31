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

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int aux,A,B,C,D,k;
  for(int N=2;N<=200;N++){
		A=N*N*N;
		for(int i=2;i*i*i<=A;i++){
			B=i*i*i;
			for(int j=i+1;(B+j*j*j)<=A;j++){
			 	C=j*j*j;
				 for(int k=j+1;(B+C+(k*k*k))<=A;k++){
					D=k*k*k;
					if(B+C+D==A)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",N,i,j,k);		
				}  
			}	
		}		
  }
  //system("pause");
  return 0;
}
