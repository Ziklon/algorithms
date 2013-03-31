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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rep(i,n) for((i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}
int K,R,M,X,Y,N,dev,tmp;
int lcs[45], sol[303];
int main(){
   dev=0;
   scanf("%d %d\n",&K,&R);
   scanf("%d\n",M);
   for(int i=0;i<(M*2);i+=2)
      scanf("%d %d\n",&lcs[i],&lcs[i+1]);
   scanf("%d\n"N);
   for(int i=0;i<(N*3);i+=3)
      scanf("%d %d %d\n",&sol[i],&sol[i+1],&sol[i+2]);
   
   for(int i=0;i<(1<<M);i++){
      vector<pair<int,int> >VP;
      int cnt=0;
      for(int j=0,m=0;j<(M*2) && cnt<K;j+=2,m++){
         if((i&(1<<j))!=0){
            Vp.push_back(make_pair(lcs[j],lcs[j+1]));
            cnt++;            
         }
      }
      tmp=0;
      sort(all(VP));
      for(int j=0;j<VP.sz;j++){
         for(int k=0;k<(N*3);k+=3){
            if(abs(VP[j].first-sol[k])<=R && abs(VP[j].second-sol[k+1])<=R)
               tmp+=sol[k+2];
         }
      }
      dev=max(dev,tmp);      
   }
   printf("%d\n",dev);          
   return 0;
}
