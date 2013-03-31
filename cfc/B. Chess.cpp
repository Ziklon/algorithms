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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;

int table[8][8];
int getX(string s){
    return s[0]-'a';
}
int getY(string s){
    return s[1]-'1';
}

int di[]={0,0,1,-1,1,-1,1,-1, 2,1,-1,-2,-1,-2,1,2};
int dj[]={1,-1,0,0,1,-1,-1,1, 1,2,-2,-1,2,1,-2,-1};

bool cab(int x1, int y1, int x2, int y2){
    if(table[x1][y1])return false;
    REP(i,8,16){
        int X=di[i]+x1;
        int Y=dj[i]+y1;
        if(X==x2 && Y==y2)return false;
    }
    return true;
}

bool torr(int x1, int y1, int x2, int y2){
    if(x1==x2)return false;
    if(y1==y2)return false;
    return true;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    int xa=getX(a);
    int ya=getY(a);
    int xb=getX(b);
    int yb=getY(b);   
    fill(table,0);
    table[xa][ya]++;
    table[xb][yb]++;
    
    int ans=0;
    
    REP(i,0,8)
        REP(j,0,8){
            if(cab(i,j,xa,ya) && cab(i,j,xb,yb) && torr(xa,ya,i,j))
                ans++;
          
        }
    
            
            
    cout<<ans<<endl;
    
    
    
    //system("pause");
    return 0;
}
