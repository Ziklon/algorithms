#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(0);
	priority_queue<ll> Q;
	Q.push(2);
	Q.push(5);
	Q.push(10);
	
	while(!Q.empty()){
        ll top = Q.top();Q.pop();
        
        cout<<top<<endl;
        
        
	}
	
	return 0;
}
