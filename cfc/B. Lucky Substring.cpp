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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    vector<int>A(10,0);
    string num;
    cin>>num;
    
    REP(i,0,num.sz)A[num[i]-'0']++;
    
    if(A[7]==0 && A[4]==0){
        cout<<"-1"<<endl;
    }else{
        if(A[7]>A[4])cout<<"7"<<endl;
        else cout<<"4"<<endl;
    }

    //system("pause");
    return 0;
}
