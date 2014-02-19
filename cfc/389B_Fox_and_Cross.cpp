#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;
int N;
char board[100][100];
bool seen[100][100];

int dx[] = {1,2,1,1};
int dy[] = {0,0,1,-1};

int main(){
    scanf("%d\n",&N);
    memset(seen,0,sizeof seen);
    
    REP(i,N){
        REP(j,N)scanf("%c",&board[i][j]);
        scanf("\n");
    }
    
    
    bool can = true;    
    REP(i,N)REP(j,N)if(board[i][j]=='#'  && !seen[i][j]){
        seen[i][j]=1;
        int cnt = 1;
        REP(k,4){
            int x = i + dx[k];
            int y = j + dy[k];
            if(min(x,y)>=0 && max(x,y)< N  && board[x][y]=='#' && seen[x][y]==0){
                seen[x][y]=1;
                cnt++;
            } 
        }
        if(cnt!=5){
            can=false;
        }  
        
    }
    
    puts(can?"YES":"NO");
    
        
    
    return 0;
}
