#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
#define MOD 1000003
int dfs_cnt[55],counter=0;
bool found=0;
int cmp=0;
void dfs(vector<string>&G, int u, int p){
	dfs_cnt[u]=counter++;
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]=='Y'){
			if(i==p)continue;
			if(dfs_cnt[i]==-1){
				dfs(G,i,u);
			}else if(abs(dfs_cnt[i]-dfs_cnt[u])%2==0){
				found=1;
			}
		}
	}
}
int fast_expo(int a, int b){
	int ans=1;
	for(int i=0;i<b;i++)ans=(ans*1LL*a)%MOD;
	return ans;
}

class MagicLabeling {
public:int count(vector <string> graph, int M) {	
		int ans=1;
		counter=0;
		found=0;
		memset(dfs_cnt,-1,sizeof dfs_cnt);
		cmp=0;
		for(int i=0;i<graph.size();i++)if(dfs_cnt[i]==-1){
			dfs(graph,i,-1);
			cmp++;
		}
		int MM=0;
		for(int i=0;i<graph.size();i++){
			int C=std::count(graph[i].begin() , graph[i].end() , 'Y');
			if(C==0)MM++;
		}
		if(found==1){
			if(MM)return (M + fast_expo(M,MM))%MOD;
			return M;		
		}
		if(MM>0)ans=fast_expo(M,MM);
		if(cmp==MM)return ans;

		map<int,int> M1;
		for(int i=1;i<=M;i++)for(int j=1;j<=M;j++)M1[i+j]++;

		vector<pair<int,int> >v(M1.begin(),M1.end());
		int tmp=0;
		for(int i=0;i<v.size();i++){
			tmp=(tmp+fast_expo(v[i].second,cmp-MM) )%MOD;
		}
		ans=(ans*1LL*tmp)%MOD;
		return ans;		
	}
};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	MagicLabeling *obj;
	int answer;
	obj = new MagicLabeling();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 970003;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"NNNNN","NNNNN","NNNNY","NNNNN","NNYNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 970003;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"NYY","YNN","YNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	p2 = 100;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"NYNN","YNNN","NNNY","NNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 19;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"NYY","YNY","YYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15;
	p2 = 15;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
//With unused code cleaner (beta) by ahmed_aly
