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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
struct node{
   string name;
   int win,lose,played, gols,gains,tie,point,dif;
   node(string nam){
      name=nam;
      win=0;
      lose=0;
      played=0;
      gols=0;
      gains=0;
   }
   void update(){
      tie=played-win-lose;
      point=tie+win*3;
      dif=gols-gains;
   }      
};

string lower(string str){
   for(int i=0;i<str.sz;i++)
      if(isalpha(str[i]))
         str[i]=toupper(str[i]);
   return str;
}
bool orden(node p, node q){
   if(p.point!=q.point)return p.point>q.point;
   if(p.win!=q.win)return p.win>q.win;
   if(p.dif!=q.dif)return p.dif>q.dif;
   if(p.gols!=q.gols)return p.gols>q.gols;
   if(p.played!=q.played)return p.played<q.played;
   return lower(p.name)<lower(q.name);
}

vector<string> split(string str){
   vector<string> ans;
   int x=-1;
   str=str+"#";
   for(int i=0;i<str.sz;i++){
      if(str[i]=='#' || str[i]=='@'){
         ans.push_back(str.substr(x+1,i-x-1));
         x=i;
      }
   }
   return ans;
}

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t,G,L;
   string tour,team;
   cin>>t;
   cin.get();
   for(int i=0;i<t;i++){
      getline(cin,tour);
      cin>>G;
      cin.get();
      map<string,int>M;
      vector<node> teams;
      for(int j=0;j<G;j++){
         getline(cin,team);
         M[team]=j;
         teams.push_back(node(team));
      }
      cin>>L;
      cin.get();
      for(int j=0;j<L;j++){
         string teamA,teamB;
         int x,y;
         getline(cin,team);
         vector<string> vs=split(team);
         teamA=vs[0];
         teamB=vs[3];
         x=toi(vs[1]);
         y=toi(vs[2]);
         teams[M[teamA]].played++;
         teams[M[teamA]].gols+=x;
         teams[M[teamA]].gains+=y;
         if(x>y){
            teams[M[teamA]].win++;
            teams[M[teamB]].lose++;
         }else if(x<y){
            teams[M[teamB]].win++;
            teams[M[teamA]].lose++;
         }
         teams[M[teamB]].played++;
         teams[M[teamB]].gols+=y;  
         teams[M[teamB]].gains+=x;       
      }
      for(int j=0;j<G;j++)teams[j].update();
      sort(all(teams),orden); 
      printf("%s\n",tour.c_str());
      for(int j=0;j<teams.sz;j++){
         printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",j+1,teams[j].name.c_str(),
         teams[j].point,teams[j].played,teams[j].win,teams[j].tie,teams[j].lose, teams[j].dif,
         teams[j].gols,teams[j].gains);
      }
     if(i<t)printf("\n");
      
   }
   return 0;
}
