
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
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
unsigned long long toi(string s){istringstream is(s);unsigned long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}


unsigned long long tra;
int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int n,dev=0;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    for(int i=0;i<n;i++){
        int j=i-1;
        int aux=1,cur;
        int k=i+1;
        cur=v[i];
        while(j>=0 && v[j]<=cur){
            cur=v[j];
            aux++;
            j--;
        }
        cur=v[i];
        while(k<n && v[k]<=cur){
            cur=v[k];
            aux++;
            k++;
        }
        dev=max(dev,aux);
    }
    cout<<dev<<endl;
    return 0;

}

 
