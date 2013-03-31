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
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
void print(string s){
     printf("%s\n",s.c_str());
     cerr<<s<<endl;
}

int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int n,x,y;
    char a[124],b[124];
    scanf("%d\n",&n);
    bool adj[26][26];
    for(int i=0;i<n;i++){
        scanf("\n");
        scanf("%d %d\n",&x,&y);
        mem(adj,0);
        for(int i=0;i<x;i++){
            scanf("%s %s\n",a,b);
            adj[a[0]-'A'][b[0]-'A']=1;
            adj[b[0]-'A'][a[0]-'A']=1;
        }
        for(int i=0;i<y;i++){
            scanf("%s %s\n",a,b);
            queue<string>Q;
            Q.push(string(1,a[0]));
            vector<bool>vis(26,0);
            vis[a[0]-'A']=1;
            string dev="";
            while(!Q.empty()){
                string cur=Q.front();
                Q.pop();
                char ult=cur[cur.sz-1];
                if(ult==b[0]){
                    dev=cur;
                    break;
                }
                for(int j=0;j<26;j++){
                    if(adj[ult-'A'][j] && !vis[j]){
                        Q.push(cur+string(1,'A'+j));
                        vis[j]=1;
                    }
                }
            }
            print(dev);
        }
        if(i+1!=n)print("");
        
    }
    
    return 0;

}


