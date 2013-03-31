#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int e=0,f=0,c=0;
	int n;
	cin>>n;
	while(n--){
		cin>>e>>f>>c;
		int tot=e+f;
		int dev=0;
		while(tot>=c){
			int r=tot%c;
			tot/=c;
			dev+=tot;
			tot+=r;
		}
		cout << dev<<endl;		
	}
	return 0;
}
