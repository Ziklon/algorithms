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

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int nC,num,aux,ans;
    cin>>nC;
    REP(i,0,nC){
        cin>>num;
        aux=num;
        ans=0;
        while(aux){
            int val=aux%10;
            if(val!=0 && num%(val)==0)ans++;
            aux/=10;
        }
        printf("Caso #%d: %d\n",i+1,ans);
        
    }
    //system("pause");
    return 0;
}
