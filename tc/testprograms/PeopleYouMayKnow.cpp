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
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
int N;
bool G1[55][55],G2[55][55],used[55];
int flow[55][55],cap[55][55],prev[55];

int bfs(int s, int t){
	memset(prev,-1,sizeof prev);
	prev[s]=-2;
	queue<int> Q;Q.push(s);
	bool found=0;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		if(u==t){
			found=1;
			break;
		}
		REP(i,N)if(cap[u][i]>flow[u][i] && prev[i]==-1){
			prev[i]=u;
			Q.push(i);
		}
	}
	if(!found)return 0;
	int u,v=t;
	while(v!=s){
		u=prev[v];
		flow[u][v]+=1;
		flow[v][u]-=1;
		v=u;
	}	
	return 1;
}

int maxFlow(int s, int t){
	int ans=0;
	while(bfs(s,t))ans++;
	return ans;	
}
class PeopleYouMayKnow {
public:int maximalScore(vector <string> friends, int p1, int p2) {	
		int ans=0;
		N=friends.size();
		
		memset(used,0,sizeof used);
		
		REP(i,N)REP(j,N)G1[i][j]=friends[i][j]=='Y';
		memcpy(G2,G1,sizeof G2);
		
		REP(k,N)REP(i,N)REP(j,N)G2[i][j]|=(G2[i][k]&&G2[k][j]);
		
		if(G2[p1][p2]==0)return ans;
		
		REP(i,N)if(G1[p1][i] && G1[i][p2]){
			ans++;
			used[i]=1;
		}
		memset(flow,0,sizeof flow);
		memset(cap,0,sizeof cap);
	
		REP(i,N)if(!used[i])REP(j,N)if(used[j]==0 && G1[p1][i] && G1[i][j] && G1[j][p2]){
			cap[i][j]=1;
			cap[p1][i]=1;
			cap[j][p2]=1;
		}
		ans+=maxFlow(p1,p2);				
		return ans;		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	PeopleYouMayKnow *obj;
	int answer;
	obj = new PeopleYouMayKnow();
	clock_t startTime = clock();
	answer = obj->maximalScore(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	int p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"NN","NN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	p3 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"NYNN","YNYN","NYNY","NNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 3;
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"NYNYYYN","YNYNNYY","NYNNNNY","YNNNNNN","YNNNNYN","YYNNYNY","NYYNNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 3;
	p3 = 1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"NYYYYNNNN","YNNNNYYYN","YNNNNNNYN","YNNNNNNYN","YNNNNNNNY","NYNNNNNNY","NYNNNNNNY","NYYYNNNNY","NNNNYYYYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
	p2 = 0;
	p3 = 3;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
