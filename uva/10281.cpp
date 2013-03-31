#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

long long hour=0,aux,velo=0;
double ans,adv=0;
long long getTime(string s){
	int a,b,c;
	sscanf(s.c_str(),"%d:%d:%d",&a,&b,&c);
	return ((a*3600)+(b*60)+c);
}

int toint(string s){
	int a;
	istringstream is(s);
	is>>a;
	return a;
}
int main(){
	//freopen("in.txt","r",stdin);
	string line,cad;
	while(getline(cin,line)){
		vector<string> vs;
		stringstream ss(line);
		while(ss>>cad)vs.push_back(cad);
		if(vs.size()==2){//update velocity			
			aux=getTime(vs[0])-hour;
			adv+=(aux*velo*1.0)/3600.0;
			//cout<<adv<<endl;
			hour=getTime(vs[0]);
			velo=toint(vs[1]);
		}else{
			aux=getTime(vs[0])-hour;
			ans=((aux*velo*1.0)/3600.0)+adv;
			printf("%s %.2f km\n",vs[0].c_str(),ans);
		}
	}
	return 0;

}