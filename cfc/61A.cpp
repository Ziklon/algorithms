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
	string a,b,ans;
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i])
            ans+="0";
        else
            ans+="1";
    }
    cout<<ans<<endl;
}

