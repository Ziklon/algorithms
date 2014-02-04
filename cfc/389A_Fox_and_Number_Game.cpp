#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;

int main(){
    int N,ans =0, num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        ans=__gcd(num,ans);
    }
    cout<<ans*N<<endl;
    return 0;
}
