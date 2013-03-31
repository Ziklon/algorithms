/*
ID: winftc2
PROG: in.txt
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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int T,N,i,j,k,p,r,s,t;
char *  sangria(int init){
   static char buf[1024];
   sprintf(buf, "  %*s", 2*init, "");
   return buf;
}
void adj(int copy[8][8]){
   for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
         for(int k=0;k<N;k++)
            if(copy[i][j] && copy[j][k])
               copy[i][k]=1;
}
void backTrack(int vars[8][8], int init){
   int copy[8][8];
   int done=0;
   for(int i=0;i<N;i++)
      for(int j=0;j<N;j++){
         if(i!=j && !vars[i][j] && !vars[j][i]){
            printf("%sif %c < %c then\n", sangria(init), 'a'+i, 'a'+j);
            memcpy(copy, vars, sizeof(copy));
            copy[i][j]=1;
            adj(copy);
            backTrack(copy, init+1);
            printf("%selse\n", sangria(init));
            memcpy(copy, vars, sizeof(copy));
				copy[j][i]=1;
				adj(copy);
				backTrack(copy, init+1);            
				return;            
         }
      }
   printf("%swriteln(", sangria(init));
	for(int i=0; i<N; i++) {
		done=1;
		for(int j=0; j<N; j++) {
			if (i!=j && !vars[i][j]) {
				done=0;
				break;
			}
		}
		if (done) {
			printf("%c", 'a'+i);
			vars[i][i]=1;
			break;
		}
	}
	while(1) {
		int all_done=1;
		for(int i=0; i<N; i++) {
			if (vars[i][i]) {
				continue;
			}
			done=1;
			for(int j=0; j<N; j++) {
				if (i==j || vars[j][j]) {
					continue;
				}
				if (!vars[i][j]) {
					done = 0;
					break;
				}
			}
			if (done) {
				all_done=0;
				printf(",%c", 'a'+i);
				vars[i][i]=1;
				break;
			}
		}
		if (all_done) {
			break;
		}
	}
	printf(")\n");
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&T);
    REP(i,0,T){
      scanf("%d",&N);
      if(i>0)printf("\n");      
      printf("program sort(input,output);\n");
      printf("var\n");
      REP(j,0,N){
         printf("%c",'a'+j);
         if(j+1<N)
            printf(",");
      }
      printf(": integer;\n");
      printf("begin\n");
         printf("  readln(");
         REP(j,0,N){
            printf("%c",'a'+j);
            if(j+1<N)
               printf(",");
         }
         printf(");\n");
         int vars[8][8];
         REP(j,0,N)
            REP(k,0,N)
               vars[j][k]=0;
         backTrack(vars,0);
         
      printf("end.\n");
      //
    }  
    //system("pause");
    return 0;
}
