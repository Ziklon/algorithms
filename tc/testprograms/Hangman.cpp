#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef pair<int, int> pii; 
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)


class Hangman {
public:string guessWord(string feedback, vector <string> words) {	
		vector<string> peki;
		vector<char> vc;
		REP(i,0,feedback.sz)if(feedback[i]!='-')
			vc.push_back(feedback[i]);
		sort(all(vc));
		REP(i,0,words.sz){
			if(words[i].sz!=feedback.sz)continue;
			
			bool ok=1;
			REP(j,0,words[i].sz){				
				if(feedback[j]=='-' && binary_search(all(vc),words[i][j]))ok=0;
				if(feedback[j]!='-' && words[i][j]!=feedback[j])ok=0;		
			}
			if(ok)peki.push_back(words[i]);
		}
		if(peki.sz==1)return peki[0];
		return "";		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Hangman *obj;
	string answer;
	obj = new Hangman();
	clock_t startTime = clock();
	answer = obj->guessWord(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	string p0;
	vector <string> p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "N-N-A";
	string t1[] = {"NINJA","NINJAS","FLIPS","OUT","FRISBEE"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NINJA";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "B--B--";
	string t1[] = {"BRINGS","BARBED","BUBBLE"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "BARBED";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "---------";
	string t1[] = {"MONKEY","FORCE","IS","GAINING","STRENGTH"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "-AAA--";
	string t1[] = {"CAAABB","BAAACC"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "---H-O-H-B-OPHOB--";
	string t1[] = {"ROSACEA","GYROVAGUE","SHACONIAN","ALTITONANT","BRACHIATION","CERCOPITHECAN","SCOLECOPHAGOUS","RESISTENTIALISM","SLUBBERDEGULLION","AICHMORHABDOPHOBIA","SPECTOCLOACAPHOBIA","ULTRACREPIDARIANISM","HIPPOPOTOMONSTROSESQUIPEDALIAN","CHARGOGGAGOGGMANCHAUGGAGOGGCHAUBUNAGUNGAMAUGG"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "AICHMORHABDOPHOBIA";
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
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
