/*
ID: winftc2
PROG: checker
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define oo 1<<30
using namespace std;
int n;

int columna[15];
int diagonal[15][15];
int sig[15];
int cnt=0;

int dx[]={1,1,-1,-1};
int dy[]={1,-1,-1,1};

void imprimir()
{
    cnt++;
	if(cnt<=3){
		REP(i,0,n){
			if(i!=0)printf(" ");
			printf("%d",sig[i]+1);
		}
		printf("\n");
	}  
}
void paint(int x, int i){
	  columna[i]=1;
	  for(int j=0;j<min(n-x,n-i);j++)diagonal[x+j][i+j]++;
      for(int j=0;j<min(n-x,i+1);j++)diagonal[x+j][i-j]++;
	  
}

void unpaint(int x , int i){
	columna[i]=0;
	for(int j=0;j<min(n-x,n-i);j++)diagonal[x+j][i+j]--;
    for(int j=0;j<min(n-x,i+1);j++)diagonal[x+j][i-j]--;
	
}

void reina(int x)
{
    if(x==n)imprimir();
    for(int i=0;i<n;i++){
        if(diagonal[x][i]==0 && columna[i]==0){            
            paint(x,i);            
			sig[x]=i;
            reina(x+1);
			unpaint(x,i);
        }
    }
        
}


int main()
{
    // freopen("checker.in", "r", stdin);
    // freopen("checker.out", "w", stdout);

    scanf ("%d", &n);
    cnt=0;

    fill (columna, 0);
    fill(diagonal, 0);
    reina(0);

    printf ("%d\n", cnt);


    return 0;
}

