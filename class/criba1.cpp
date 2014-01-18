#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
#define first fst
#define second snd
#define sz size()
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;

/**
 * 1 2 3
 *
 *
 *
 *
 **/

#define MAXN 1000005

bool  criba[MAXN];



int main(){
    
    memset(criba,0,sizeof criba);
    
    // Sqrt(N)*log(N)
    //N=10^9
    //sqrt(N)*long(N)
    //
    //

    for(int i = 2; i*i <= MAXN ; i++)
        if(criba[i]==0){
            // el primo es i
            // aca i es primo
            // 
            for(int j = i*i; j< MAXN ; j += i )
                criba[j] = 1;        
        }

    for(int i=2;i<100;i++)
        if(criba[i]==0)
            cout<<i<<endl;
    return 0;
}

