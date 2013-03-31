#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <cstdio>
#define sz size()


using namespace std;
int toi(string s){istringstream is(s);int x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

int T,N,Q,C;
string line,a,b,c;

int main(){
	freopen("out.txt","w",stdout);
	scanf("%d\n",&T);
	map<string,int>M;
	M["LU"]=0;
	M["MA"]=1;
	M["MI"]=2;
	M["JU"]=3;
	M["VI"]=4;
	M["SA"]=5;
	M["DO"]=6;
	C=1;
	while(T){
		scanf("%d\n",&N);
		vector<vector<bool> >alo;
		for(int i=0;i<N;i++){
			getline(cin,line);
			vector<bool>tmp(200,0);
			istringstream ss(line);
			while(ss>>a>>b>>c){
				for(int i=(24*M[a])+toi(b);i<=(24*M[a])+toi(c);i++)
					tmp[i]=1;
			}
			alo.push_back(tmp);
		}
		scanf("%d\n",&Q);
		vector<vector<bool> >liz;
		for(int i=0;i<Q;i++){
			getline(cin,line);
			vector<bool>tmp(200,0);
			istringstream ss(line);
			while(ss>>a>>b>>c){
				for(int i=(24*M[a])+toi(b);i<=(24*M[a])+toi(c);i++)
					tmp[i]=1;
			}
			liz.push_back(tmp);		
		}
		vector<string> res;
		for(int i=0;i<liz.sz;i++){
			vector<bool> Va=liz[i];
			double cnt=0;
			for(int j=0;j<alo.sz;j++){
				vector<bool> Vb=alo[j];
				bool ok=1;
				for(int x=0;x<Va.sz;x++)
					if(Va[x]==1 && Vb[x]==0){
						ok=0;
						break;
					}
				if(ok)cnt++;
			}
			if(cnt*2>=N)res.push_back("Si");
			else res.push_back("No");
		
		}
		printf("Caso #%d:",C);
		for(int i=0;i<res.sz;i++)
			printf(" %s",res[i].c_str());
		printf("\n");		
		C++;
		T--;	
	}

}
