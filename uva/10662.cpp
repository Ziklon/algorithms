/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int R,H,T,ans,a,b,c;
     while(scanf("%d %d %d",&T,&R,&H)==3){
        vector<vector<int> >vT(T,vector<int>(R));
        vector<vector<int> >vR(R,vector<int>(H));
        vector<vector<int> >vH(H,vector<int>(T));
        vector<int> viT(T);
        vector<int> viR(R);
        vector<int> viH(H);
        ans=1<<30;
        for(int i=0;i<T;i++){
          scanf("%d",&viT[i]);
          for(int j=0;j<R;j++)scanf("%d",&vT[i][j]);
        }
        for(int i=0;i<R;i++){
          scanf("%d",&viR[i]);
          for(int j=0;j<H;j++)scanf("%d",&vR[i][j]);
        }
        for(int i=0;i<H;i++){
          scanf("%d",&viH[i]);
          for(int j=0;j<T;j++)scanf("%d",&vH[i][j]);
        } 
        for(int i=0;i<T;i++)
          for(int j=0;j<R;j++)
            for(int k=0;k<H;k++){
              if(!vT[i][j] && !vR[j][k] && !vH[k][i]){
                if(ans>(viT[i]+viR[j]+viH[k])){
                  a=i;
                  b=j;
                  c=k;
                  ans=(viT[i]+viR[j]+viH[k]);
                }
              }
            }
       if(ans<(1<<30))printf("%d %d %d:%d\n",a,b,c,ans);
       else printf("Don't get married!\n");
     }
    
    //system("pause");
    return 0;
}
