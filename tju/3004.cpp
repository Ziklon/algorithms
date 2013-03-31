#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;
int N,p;
char text[1024];
string aux;
int main(){
	scanf("%d",&N);
	vector<string> v;
	while(N--){
		scanf("%d %s",&p,text);
		aux=text;
		aux.erase(p-1,1);
		v.push_back(aux);
	}
	for(int i=0;i<v.size();i++)
		printf("%d %s\n",i+1,v[i].c_str());
	return 0;
}
