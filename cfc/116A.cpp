#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;
typedef long long ll;

int main(){
	//freopen("input","r",stdin);
    int N;
    cin>>N;
    int ans=0;
    int cap=0;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        cap-=a;
        cap+=b;
        ans=max(ans,cap);
    }
    cout<<ans<<endl;
	return 0;
}

