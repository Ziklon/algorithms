#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int T;
string board[5];

bool isWin(set<char>& S, char& c){
    if(S.size()>2)return 0;
    if(S.size()==1 && S.count(c)==1)return 1;
    if(S.count(c)==1 && S.count('T')==1)return 1;
    return 0;
}

bool check(char c){
   REP(i,4){
        set<char> S1,S2;    
        REP(j,4)S1.insert(board[i][j]);
        REP(j,4)S2.insert(board[j][i]);
        if(isWin(S1,c) || isWin(S2,c))return 1;        
   } 
   set<char> S1,S2;
   REP(i,4){
      S1.insert(board[i][i]);
      S2.insert(board[i][4-i-1]); 
   }
   if(isWin(S1,c) || isWin(S2,c))return 1;
   return 0;
}

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   scanf("%d\n",&T);
   REP(t,T){
      bool ok1=0;
      REP(i,5){
        getline(cin,board[i]);
        if(board[i].find('.')!=-1)ok1=1;
      }
      //mdebug(board,4,4);
      printf("Case #%d: ",t+1);
      if(check('X'))printf("X won\n");
      else if(check('O'))printf("O won\n");
      else if(ok1==0)printf("Draw\n");
      else printf("Game has not completed\n");   
   }   
   return 0;      
}


