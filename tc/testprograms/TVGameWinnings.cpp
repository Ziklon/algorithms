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

int getVal(char c){
	if(c>='0' && c<='9')return c-'0';
	return -(c-'A'+1);
}

int col[10],N;
int B[10][10];

vector<vector<pair<int,int> > >sols;

void backTrack(int x){
	if(x==N){
		vector<pair<int,int> >v;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++)if(B[i][j]==1)v.push_back(make_pair(i,j));	
		sols.push_back(v);
		return;
	}
	for(int i=0;i<N;i++){
		if(col[i]==0){
			col[i]=1;
			B[x][i]=1;
			backTrack(x+1);
			B[x][i]=0;
			col[i]=0;
		}	
	}
}

int dfs(vector<pair<int,int> >&v, int mask, int idx, int start, vector<bool>& vis){
	
	if(v[start].first==v[idx].second)return mask;
	for(int i=0;i<N;i++)
		if(vis[i]==0 && v[i].first==v[idx].second)
			return dfs(v,mask|(1<<i),i,start,vis);
	return 0;
}




class TVGameWinnings {
public:vector <int> getMinMax(vector <string> board) {	
		vector <int> ans;
		N=board.size();
		sols.clear();
		memset(B,0,sizeof B);
		memset(col,0,sizeof col);		
		backTrack(0);
		int mini=1<<30;
		int maxi=-1<<30;
		for(int i=0;i<sols.size();i++){
			vector<pair<int,int> >v=sols[i];
			vector<bool> vis(N,0);
			int MM=N;
			for(int j=0;j<N;j++){
				int mask=dfs(v,1<<j,j,j,vis);
				if(mask>0){
					MM-=(__builtin_popcount(mask)-1);
					for(int k=0;k<N;k++)if(mask&(1<<k))vis[k]=1;
				}
			}			
			
			int tmp=1;
			for(int j=0;j<N;j++)tmp*=getVal(board[v[j].first][v[j].second]);
			if((MM&1)==0)tmp*=-1;
			maxi=max(maxi,tmp);
			mini=min(mini,tmp);
		}
		ans.push_back(mini);
		ans.push_back(maxi);		
		return ans;		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TVGameWinnings *obj;
	vector <int> answer;
	obj = new TVGameWinnings();
	clock_t startTime = clock();
	answer = obj->getMinMax(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"35","44"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-12,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"00200","0B000","00020","10000","00001"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-8,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"12A","A12","2A1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"AAAA","BBBB","CCCC","DDDD"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-24,24};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
