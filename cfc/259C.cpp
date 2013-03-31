#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
string number,ans;

int main(){
	ios::sync_with_stdio(false);
	cin>>number;
	int index=0;
	for(int i=0;i<number.size();i++)if(number[i]=='0'){
		index=i;
		break;
	}		
	ans=number.substr(0,index)+number.substr(index+1);
	cout<<ans<<endl;					
	return 0;
}
