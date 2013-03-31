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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int M,N,x;
    vector<pair<int,int> >team;
    vector<pair<int,int> > table;
    while(scanf("%d %d\n",&M,&N)==2 && M && N){
      team.clear();
      table.clear();
      for(int i=0;i<M;i++){
        scanf("%d",&x);
        team.push_back(make_pair(x,i));
      }
      for(int i=0;i<N;i++){
        scanf("%d",&x);
        table.push_back(make_pair(x,i));
      }
      sort(team.rbegin(),team.rend());
      vector<vector<int> >v(M,vector<int>());
      bool ok=1;
      for(int i=0;i<team.sz && ok;i++){
         sort(table.rbegin(),table.rend());
         int cur=team[i].first;
         int index=team[i].second;
         for(int j=0;j<N && cur;j++){
            if(table[j].first>0){
                v[index].push_back(table[j].second+1);
                table[j].first--;
                cur--;
            }
         }
         sort(all(v[index]));
         if(cur>0)ok=0;         
      }
      if(ok){
        printf("1\n");
        for(int i=0;i<M;i++){
          printf("%d",v[i][0]);
          for(int j=1;j<v[i].sz;j++)
            printf(" %d",v[i][j]);
          printf("\n");
        }
      }else
        printf("0\n");
      
              
    }
    
    //system("pause");
    return 0;
}
