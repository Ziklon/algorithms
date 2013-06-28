#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <deque> 
#include <queue> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <cmath> 
#include <cstdlib> 
#include <ctime>
#include <cstring>
#include <cstdio>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 

int dist[40][40][40][40];
bool seen[40][40];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct GameOnABoard {
   int optimalChoice( vector <string> cost ) {       
       
       REP(i,cost.size())REP(j,cost[i].size()){
           deque<pair<int,int> >Q;
           Q.push_back(make_pair(i,j));
           dist[i][j][i][j]=cost[i][j]-'0';
           memset(seen,0,sizeof seen);
           while(!Q.empty()){
                int xx=Q.front().first;
                int yy=Q.front().second;
                Q.pop_front();
                REP(k,4){
                   int x=xx+dx[k];
                   int y=yy+dy[k];
                   if(min(x,y)>=0 && x<cost.size() && cost[0].size()>y && seen[x][y]==0){
                        seen[x][y]=1;                        
                        if(cost[x][y]=='1'){
                            dist[i][j][x][y]=dist[i][j][xx][yy]+1;
                            Q.push_back(make_pair(x,y));
                        }else{
                            dist[i][j][x][y]=dist[i][j][xx][yy];
                            Q.push_front(make_pair(x,y));
                        }                       
                   } 
                }       
           }  
       
       }
       int ans=1<<20;
       REP(i,cost.size())REP(j,cost[i].size()){
            int maxi=0;
            REP(a,cost.size())REP(b,cost[a].size()){            
               maxi=max(maxi,dist[i][j][a][b]); 
            }
            ans=min(ans,maxi);
       
       }
       return ans;
       
            
   }
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing GameOnABoard (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1371691896;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GameOnABoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cost[] = {"11",
				                 "10"};
				_expected = 2;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}
			case 1:
			{
				string cost[] = {"01",
				                 "10"};
				_expected = 1;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}
			case 2:
			{
				string cost[] = {"111001",
				                 "001000",
				                 "111111",
				                 "001111",
				                 "001100",
				                 "001011",
				                 "111001",
				                 "010011"};
				_expected = 3;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}
			case 3:
			{
				string cost[] = {"001001101011",
				                 "110011001101",
				                 "111111000001",
				                 "111101010001",
				                 "011100101111",
				                 "110010111000",
				                 "111111110101",
				                 "111011110111",
				                 "111100100011",
				                 "000000000110",
				                 "101011011110",
				                 "011111000111",
				                 "101111001011"};
				_expected = 5;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}
			case 4:
			{
				string cost[] = {"110010100101010110100010001100111011",
				                 "001000000110100011010100000001001000",
				                 "011000110111101001011101110111000100",
				                 "111001011000100101111010100110110011",
				                 "111000011101001010000100001010000010",
				                 "111001110010100101000001001100011011",
				                 "111110100111010101100000100111000111",
				                 "011111111100100111111110000001110111",
				                 "110000010101001111100011110000001000",
				                 "010010110111111100011101100000011010",
				                 "110001100001111001101000101110110001",
				                 "110010000111011110000010110111010101",
				                 "100100110101001001101000001101101101",
				                 "001011101101001100111110101111001110",
				                 "111010111111111100110100000011111100",
				                 "110101101000001001000100101011100000",
				                 "011011001011010001001000100000110101",
				                 "011111111100000011010111010011010100",
				                 "111001111110001110001110010100111010",
				                 "000001111000001100101010000001101110",
				                 "010000110000010010111110111000010101",
				                 "100010010100110011000111101001101011",
				                 "111010110001101011010001111101111100",
				                 "000111110000110000000101100101000110",
				                 "110000010111001001110001101010111100",
				                 "011111101101001011011010011111100010",
				                 "110101111101010100110010000011001101",
				                 "101101111001010100101111100001110001",
				                 "000110010100101111011011110010010010",
				                 "110101010011101000111011100000010011",
				                 "110001010001110011010100110000010001",
				                 "111010101100111100100011001101010100",
				                 "011000000000100001011010000100010001",
				                 "100000110110000001010001001111010000",
				                 "100011111110010011011011001110011111",
				                 "101100001111100101001101100000100001",
				                 "010000111011010110011001110011111000",
				                 "100010100111110111001010100101111010",
				                 "000110011110111011111000101000001000"};
				_expected = 7;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}
			/*case 5:
			{
				string cost[] = ;
				_expected = ;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string cost[] = ;
				_expected = ;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string cost[] = ;
				_expected = ;
				_received = _obj.optimalChoice(vector <string>(cost, cost+sizeof(cost)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
