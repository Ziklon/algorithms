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
bool A[1<<20]
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string text;
    cin>>text;
    int a=0;
    fill(A,0);
    REP(i,0,text.sz){
       if(text[i]=='(')a++;
       else a--;
       A[i+1]=(a==0); 
    }
    
    system("pause");
    return 0;
}
