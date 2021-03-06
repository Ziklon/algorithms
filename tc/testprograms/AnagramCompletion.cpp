#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
void fills(vector<int>&v,string& s){
	for(int i=0;i<s.sz;i++)
		if(s[i]!='.')
			v[s[i]-'A']++;
}
int pt(string& s){
	for(int i=s.sz-1;i>=0;i--)
		if(s[i]=='.')
			return i;
	return -1;
	
}
void replaceAll(string&s){
	for(int i=0;i<s.sz;i++)if(s[i]=='.')s[i]='A';
}
class AnagramCompletion {
public:vector <string> complete(string word1, string word2) {	
		vector<int>a(26,0);
		vector<int>b(26,0);
		fills(a,word1);
		fills(b,word2);
		for(int i=0;i<a.sz;i++)
			a[i]-=b[i];
					
		for(int i=25;i>=0;i--){
			while(a[i]<0 && pt(word1)>=0){
				int p=pt(word1);
				word1[p]='A'+i;
				a[i]++;
			}
		}
		for(int i=25;i>=0;i--){
			while(a[i]>0 && pt(word2)>=0){
				int p=pt(word2);
				word2[p]='A'+i;
				a[i]--;
			}
		}
		replaceAll(word1);	
		replaceAll(word2);
		vector<string>dev;
		string sa=word1;sort(all(sa));
		string sb=word2;sort(all(sb));
		cout<<sa<<" "<<sb<<endl;
		if(sa!=sb)return dev;
		dev.pb(word1);
		dev.pb(word2);
		
		return dev;
		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, vector <string> p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	AnagramCompletion *obj;
	vector <string> answer;
	obj = new AnagramCompletion();
	clock_t startTime = clock();
	answer = obj->complete(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
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
	
	string p0;
	string p1;
	vector <string> p2;
	
	{
	// ----- test 0 -----
	p0 = "AB.AC.";
	p1 = "ABD..E";
	string t2[] = {"ABDACE","ABDACE"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "ABC...";
	p1 = "DEF...";
	string t2[] = {"ABCDEF","DEFABC"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "......";
	p1 = "......";
	string t2[] = {"AAAAAA","AAAAAA"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "TOPCODER";
	p1 = "D.E..TR.";
	string t2[] = {"TOPCODER","DCEOOTRP"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "ABC.";
	p1 = "DEF.";
	p2.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "TEFAT..PVSKKJT.QBJEB..NPN..NBL";
	p1 = "...B...E.ND.LNE...HW.ANTB.TKBD";
	string t2[] = {"TEFATAAPVSKKJTAQBJEBDDNPNHWNBL","AAABFJJEKNDPLNEPQSHWTANTBVTKBD"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "O";
	p1 = ".";
	all_right = KawigiEdit_RunTest(6, p0, p1, false, p2) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
