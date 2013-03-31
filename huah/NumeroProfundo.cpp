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
        int res=0;
        
        while(num>9){
            aux=num;
            num=1;
            while(aux>0){
                num*=aux%10;
                aux/=10;
            }
            res++;
            
        }
        printf("Caso #%d: %d\n",i+1,res);
        
    }
    //system("pause");
    return 0;
}
