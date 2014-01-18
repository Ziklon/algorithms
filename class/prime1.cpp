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

ll N= 100000000007;

/**
 *10 = { 1 ,2 ,5, 10}  = 3 
 * 20 = {1, 2, 4, 5, 10,20 } = 4 
 *25= {1, 5, 25 } = 5
 *
 *10/1 = 10
  10/2 = 5
 
  25/1 = 25
  25/5 = 5
   
20/1 = 20
20/2 = 10
20/4 = 5


 * */


bool esPrimo(ll  n){
    if(n<=1)return false;
    if(n = 2)return true;
    
    if(n%2==0)return false;

    for(ll i = 3 ; i*i<=n ;i+=2)
        if( n%i==0)
            return false;
    return true;
}



int main(){
    
    cout<<esPrimo(N)<<endl;

    printf("hello");
    return 0;
}

