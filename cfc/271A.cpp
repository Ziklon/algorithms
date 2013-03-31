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
	int year,tmp;
	while(cin>>year){
		
		for(int i=year+1;;i++){
			tmp=i;
			set<int> S;			
			while(tmp){
				S.insert(tmp%10);
				tmp/=10;
			}
			if(S.size()==4){
				tmp=i;
				break;
			}
		}
		cout<<tmp<<endl;
	}	
	
	return 0;
}
