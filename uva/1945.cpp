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
  freopen("out.txt","w",stdout);
  int aux;
  printf("hello");
  for(int N=6;N<=200;N++){
		for(int i=0;i*i*i<=N;i++){
			for(int j=i+1;(i*i*i+j*j*j)<=N;j++){
		       int k=N-(i*i*i + j*j*j);
		       if(k<0)break;
		       aux=(int)(pow(k,1.0/3.0));
			   if(aux*aux*aux==k) 
				if(i*i*i + k*k*k + j*j*j ==N){
					printf("Cube = %d, Triple = (%d,%d,%d)\n",N,i,j,k);	
				}

			}	
		}		
  }
  //system("pause");
  return 0;
}
