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
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
typedef long long ll; 
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};

bool seen[55][55];
bool can;
int parts;

set<pair<int,int> >vertices;

void dfs(int x, int y, int px, int py,vector<string>& v){
    if(can==0)return;
    parts++;
    if(parts>20)can=0;
    seen[x][y]=1;
    int childs=0;
    vertices.insert(make_pair(x,y));    
    REP(i,4){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X==px && Y==py)continue;
        if(min(X,Y)>=0 && X<v.size() && Y<v[0].size() && v[X][Y]=='1'){
            if(seen[X][Y])can=0;
            else{
                childs++;
                dfs(X,Y,x,y,v);
            }
        }
    }
    if(childs>1)can=0;   
}


struct SnakeCount {
   int number( vector <string> image ) {
		int ans=0;
		//memset(seen,0,sizeof seen);
		
		REP(i,image.size())REP(j,image[i].size())if(seen[i][j]==0 && image[i][j]=='1'){
            vertices.clear();            
            can=1;
            parts=0;
            dfs(i,j,-1,-1,image);   
            vector<pair<int,int> > v(vertices.begin(),vertices.end());    
            //cout<<parts<<" "<<can<<" -> "<<i<<" "<<j<<endl;     
            if(parts>=3 && parts<=20 && can){
                can=1;               
                REP(k,v.size()){                    
                    REP(m,4){
                        int X=dx[m+4]+v[k].first;
                        int Y=dy[m+4]+v[k].second;
                        pair<int,int> curPar=make_pair(X,Y);
                        if(min(X,Y)>=0 && X<image.size() && Y<image[0].size() && image[X][Y]=='1' && vertices.count(curPar)==0)can=0;
                    }
                }            
            }else can=0;
            if(can)ans++;
            else
                REP(k,v.size())seen[v[k].first][v[k].second]=0;
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
		cout << "Testing SnakeCount (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365149806;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SnakeCount _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string image[] = {"11111111",
				                  "00000010",
				                  "11100000",
				                  "00010001",
				                  "10110011"};
				_expected = 1;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 1:
			{
				string image[] = {"110111",
				                  "110101",
				                  "000110"};
				_expected = 1;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 2:
			{
				string image[] = {"111","101","111"};
				_expected = 0;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 3:
			{
				string image[] = {
				                 "11111111111111111111111111111111111111111111111111",
				                 "00000000000000000000000000000000000000000000000001",
				                 "11111111111111111111111111111111111111111111111111"
				                 };
				_expected = 0;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			
			case 4:
			{
				string image[] = {
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "10101010101010101010101010101010101010101010101010",
				                 "00000000000000000000000000000000000000000000000000",
				                 "11011011011011011011011011011011011011011011011011",
				                 "10010010010010010010010010010010010010010010010001"
				                 };
				_expected = 317;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			
			/*case 5:
			{
				string image[] = ;
				_expected = ;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string image[] = ;
				_expected = ;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string image[] = ;
				_expected = ;
				_received = _obj.number(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
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
