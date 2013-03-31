#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

string v[]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "11", "12", "13", "14", "15", "16", "17",
	"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE",
	"GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main(){
	//freopen("R.in","r",stdin);
	//freopen("R.out","w",stdout);
	int n;
	while(cin>>n) {
		if(n == -1)break;
		int con=0;
		string s;
		for(int c=0;c<n;c++) {
			cin>>s;
			for(int kk=0; kk<29 ;kk++){
				if(v[kk] == s){
					con++;
					break;
				}
			}
		}
		cout<<con<<endl;
	}
}
