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
ll N;
int main(){
	//freopen("input","r",stdin);
	cin>>N;
    vector<int> v(10,0);
    while(N){
        v[N%10]++;
        N/=10;
    }
    int sum=v[4]+v[7];
    if(sum==4 || sum==7)
       cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}

