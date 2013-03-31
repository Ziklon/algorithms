#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;

#define NMAX 50
typedef long long ll;

ll pascal[50][50];



int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   REP(i,NMAX)pascal[i][i]=pascal[i][0]=1;
   
   for(int i=2;i<NMAX;i++)
        for(int j=1;j<i;j++)pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
   
   
   
   
    
   return 0;      
}
