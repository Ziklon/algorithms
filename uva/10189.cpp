#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int di[8]={1,1,1,-1,-1,-1,0,0};
int dj[8]={1,-1,0,1,-1,0,1,-1};
int M,N,X=0,Y=0,r,Z;

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   Z=1;
   while(scanf("%d %d",&M,&N)==2){
      if(M==0&&N==0)break;
	  if(Z!=1)printf("\n");      
      char board[M][N+1];
      for(int i=0;i<M;i++)
      	scanf("%s",&board[i]);
      	
      for(int i=0;i<M;i++)
         for(int j=0;j<N;j++){
            if(board[i][j]=='.'){
              r=0;              
              for(int k=0;k<8;k++){
                  X=i+di[k];
                  Y=j+dj[k];
                  if(X>=0 && Y>=0 && X<M && Y<N && board[X][Y]=='*')
                     r++;                                    
              }
              board[i][j]='0'+r;                         
            }
         }
      printf("Field #%d:\n",Z++);
      for(int i=0;i<M;i++)
         printf("%s\n",board[i]);       
   }
   return 0;

}

