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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int D,MM,a,b,ans,x,y,mv;
string line;


void bfs(vector<vector<int> > v, int n,map<vector<vector<int> > ,int>&M){
   
      queue<vector<vector<int> >  >Q;
      Q.push(v);
      M[v]=0;
      while(!Q.empty()){
         vector<vector<int> >  cur=Q.front();
         Q.pop();
         mv=M[cur];
         if(mv>=n)continue;
         for(int i=0;i<cur.sz;i++)
            for(int j=0;j<cur[i].sz;j++)
               if(cur[i][j]==-1){
                  x=i;
                  y=j;
               }
         for(int k=0;k<4;k++){
            int X=x+dx[k];
            int Y=y+dy[k];
            if(X>=0 && Y>=0 && X<D && Y<D){
               swap(cur[x][y],cur[X][Y]);
               if(!M.count(cur)){
                  Q.push(cur);
                  M[cur]=mv+1;
               }
               swap(cur[x][y],cur[X][Y]);
         }
      }           
   }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("START %d %d\n",&D,&MM)==2){
         vector<vector<int> > _init,_end,aux; 
         map<vector<vector<int> > ,int>M;
         map<vector<vector<int> >,int>W;      
         for(int i=0;i<D;i++){
            vector<int>vv;
            getline(cin,line);
            stringstream ss(line);
            while(ss>>line){
               if(line=="X")
                  vv.push_back(-1);
               else
                  vv.push_back(toi(line));               
            }            
            _init.push_back(vv);
         }
         for(int i=0;i<D;i++){
           vector<int>vv;
            getline(cin,line);
            stringstream ss(line);
            while(ss>>line){
               if(line=="X")
                  vv.push_back(-1);
               else
                  vv.push_back(toi(line));               
            }
            _end.push_back(vv);
         }
         scanf("END\n");
         a=MM/2;
         b=MM-a;
         ans=50;
         bfs(_init,a,M);
         bfs(_end,b,W);
         
         foreach(M,it){
           aux=(*it).first;
           mv=(*it).second;
           if(W.count(aux))ans=min(ans,mv+W[aux]);
         }
         if(ans!=50 && ans<=MM)printf("SOLVABLE WITHIN %d MOVES\n",ans);
         else printf("NOT SOLVABLE WITHIN %d MOVES\n",MM);    
         printf("\n");     
    }    
    return 0;
}
