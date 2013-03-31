#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <functional>
#include <numeric>
#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
string tos(int n) { stringstream ss; ss<<n; return ss.str();}
long long  toi(string s){ istringstream ss(s); long long n; ss>>n; return n;}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}
long dev=0;
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,1,-1,-1};
int main(){
  freopen("11.in","r",stdin);
  freopen("11.out","w",stdout);    
  int dat[20][20];
  for(int i=0;i<20;i++)
   for(int j=0;j<20;j++)
     cin>>dat[i][j];
  for(int i=0;i<20;i++)
   for(int j=0;j<20;j++){     
     for(int k=0;k<8;k++){
       int x=i;
       int y=j;
       long tmp=1;     
       for(int m=0;m<4;m++){
         x+=dx[k];
         y+=dy[k];        
         if(x>=0 && x<20 && y>=0 && y<20)
           tmp*=dat[x][y];
         else
           break;
       }
       dev=max(dev,tmp);
     } 
   }
  cout<<dev<<endl;   
  system("pause"); 
}
