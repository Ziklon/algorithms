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
	freopen("input","r",stdin);
    int N,K;
    cin>>N>>K;
    vector<pair<int,int> > v(N);

    for(int i=0;i<N;i++)cin>>v[i].first>>v[i].second;
    double dist=0;
    for(int i=0;i+1<N;i++){
        int ii=(i+1)%N;
        dist+=hypot(v[i].first-v[ii].first,v[i].second-v[ii].second);
    }
    dist=(dist*K)/50.0;
    printf("%.6f\n",dist);
}


