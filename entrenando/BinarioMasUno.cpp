#include <iostream>
using namespace std;
//Powered by [Ziklon]
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int N=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		string line="";
		cin >> line;
		int dec=0;
		for(int i=0;i<line.size();i++){
			dec=(int)(line[i])+dec*2;
		}
		
	}
}
