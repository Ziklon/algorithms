#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int a,b,N,x,y;
char s[124];
bool found=false;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
string cord="UDLR";

int func(int& sx,int& sy){
    REP(i,N){
        int idx=cord.find(s[i]);
        if(sx==a && sy==b)found=true;
        sx+=dx[idx];
        sy+=dy[idx];
    }
    if(sx==a && sy==b)found=true;
    return abs(sx-a)+abs(sy-b);
}



int main(){
    scanf("%d %d\n",&a,&b);
    scanf("%s",s);
    N=strlen(s);
    x=0;
    y=0;
    int dist3=abs(a)+abs(b);
    int dist=func(x,y);
    int dist2=abs(x)+abs(y);
    
    
    int xx=x;int yy=y;
    REP(i,600)func(xx,yy);
    
    
    
    if(abs(x-a)+abs(y-b)< abs(a)+abs(b) ){
         int nn=(abs(a)+abs(b))/dist2;
         nn=max(nn-500,1);
         x*=nn;
         y*=nn;
         REP(j,600)func(x,y);        
    }    
    puts(found?"Yes":"No");    
    return 0;      
}
