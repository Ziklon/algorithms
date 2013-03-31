#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int rn=0;
	while(cin>>rn){
   	if(rn==-1)
   		break;
   	string s1,s2;
   	cin>>s1>>s2;
   	int dev=0;
   	for(int j=0;j<s2.size();++j){
			 if(s1.find(s2[j])==string::npos)
			 	dev++;
		}
		printf("Round %d\n",rn);
		if(dev==0)
			 printf("You win.\n");
		else
			if(dev>=7)
				printf("You Lose.\n");
			else
				printf("You chickened out.\n");
	}
	return 0;
}
