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
int win(char a, char b){
   if(a==b)return 0;
   if(a=='R' && b=='S')return 1;
   if(a=='S' && b=='P')return 1;
   if(a=='P' && b=='R')return 1;
   return 2;   
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int Nc,gm;
  char A[3],B[3];
  scanf("%d\n",&Nc);
  while(Nc--){
	int a=0,b=0,c=0;
	scanf("%d\n",&gm);
	while(gm--){
		scanf("%s %s",A,B);
		if(win(A[0],B[0])==1)a++;
		if(win(A[0],B[0])==2)b++;
	}
	if(a==b)printf("TIE\n");
	if(a>b)printf("Player 1\n");
	if(a<b)printf("Player 2\n");	
  
  }
  //system("pause");
  return 0;
}
