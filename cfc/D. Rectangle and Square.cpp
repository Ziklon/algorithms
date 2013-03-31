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

bool isSquare(vector<pair<int,int> >&v,vector<int>&a){
    
    int X[4];
    int Y[4];
    REP(i,0,4){
        int j=(i+1)%4;
        X[i]=abs(v[a[i]].first- v[a[j]].first);
        Y[i]=abs(v[a[i]].second-v[a[j]].second);
    }
    REP(i,0,3){
        if(X[i]!=Y[i+1])return false;
        if(Y[i]!=X[i+1])return false;
    }
    return true;   
}

bool isRectangle(vector<pair<int,int> >&v, vector<int>&a){
    int X[4];
    int Y[4];
    REP(i,0,4){
        int j=(i+1)%4;
        X[i]=abs(v[a[i]].first- v[a[j]].first);
        Y[i]=abs(v[a[i]].second-v[a[j]].second);
    }
    REP(i,0,2){
        if(X[i]!=X[i+2])return false;
        if(Y[i]!=Y[i+2])return false;
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,y,lim;
    vector<pair<int,int> >v;
    REP(i,0,8){
        cin>>x>>y;
        v.push_back(make_pair(x,y));    
    }
    lim=1<<8;
    vector<int> a,b;
    bool ok=0;
    REP(mask,1,lim){
       if(__builtin_popcount(mask)==4){
            a.clear();
            b.clear();
            REP(i,0,8){
                if(mask&(1<<i))
                    a.push_back(i);
                else
                    b.push_back(i);
            }
            ok=0;
            do{
                if(isSquare(v,a)){
                    sort(all(b));
                    do{
                        if(isRectangle(v,b)){
                            ok=1;
                            break;
                        }
                    }while(next_permutation(all(b)));
                }
            }while(next_permutation(all(a)));            
            if(ok)break;
        } 
    }
    if(ok){
        printf("YES\n");
        printf("%d",a[0]+1);
        REP(i,1,4) printf(" %d",a[i]+1);
        printf("\n");
        printf("%d",b[0]+1);
        REP(i,1,4) printf(" %d",b[i]+1);
        printf("\n");
        
    }else{
        printf("NO\n");
    }
    //system("pause");
    return 0;
}
