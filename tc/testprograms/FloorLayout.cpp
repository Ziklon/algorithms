#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime> 
using namespace std; 
typedef long long ll;

class FloorLayout {
public:
	int countBoards(vector <string> layout) {
		int ans=0,n=layout.size(),m=layout[0].size();
		bool vis[55][55];
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			if(vis[i][j])continue;
			ans++;
			if(layout[i][j]=='|'){
				int k=i;
				while(k<n && layout[k][j]=='|'){
					vis[k][j]=1;
					k++;
				}	
			}else{
				int k=j;
				while(k<m && layout[i][k]=='-'){
					vis[i][k]=1;
					k++;
				}
			}
		}
		return ans;
		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	FloorLayout *obj;
	int answer;
	obj = new FloorLayout();
	clock_t startTime = clock();
	answer = obj->countBoards(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	{
	// ----- test 0 -----
	string t0[] = {"----","----","----","----"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"-||--||--","--||--||-","|--||--||","||--||--|","-||--||--","--||--||-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 31;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"--------","|------|","||----||","|||--|||","||----||","|------|","--------"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"||-||-|||-","||--||||||","-|-|||||||","-|-||-||-|","||--|-||||","||||||-||-","|-||||||||","||||||||||","||---|--||","-||-||||||"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 41;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"-||--|","||||||","|||-|-","-||||-","||||-|","||-||-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 19;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
