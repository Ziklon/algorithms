#include <cstdio>
#include <iostream>
#include <fstream>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;

int mul(string s){
   int ans=1;
   for(int i=0;i<s.sz;i++)
      ans=((s[i]-'A'+1)*ans)%47;
   return ans;
}
int main(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin>>a>>b;
    if(mul(a)==mul(b))
      fout<<"GO"<<endl;
   else
      fout<<"STAY"<<endl;
    return 0;
}
