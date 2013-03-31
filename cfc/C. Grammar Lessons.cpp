/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
vector<string> words;
string texts[2][3]={{"soil","rte","sitini"},{"alail","arte","setini"}};

int getSex(){
    int sa=-1;
    int sb=-1;    
    REP(i,0,words.sz){
        string cur=words[i];
        reverse(all(cur));
        REP(j,0,3){
          if(cur.find(texts[0][j])==0)
            sa=0;
        }
        REP(j,0,3){
          if(cur.find(texts[1][j])==0)
            sb=0;
        }
    }
    if(sb==0 && sa==-1)return 1;
    if(sb==-1 && sa==0)return 0;
    return -1;
}
bool isword(){
  if(words.sz!=1)return 0;
  bool ok=0;
  string cur=words[0];
  reverse(all(cur));
  REP(i,0,2)
    REP(j,0,3)
      if(cur.find(texts[i][j])==0)
          ok=1;
  return ok;
}
bool issentence(int sex){
  int adj=0;
  int nou=0;
  int ver=0;
  int i;
  for(i=0;i<words.sz;i++){
    string cur=words[i];
    reverse(all(cur));
    if(cur.find(texts[sex][0])==0){
      adj++;
    }else
      break;
  }
  for(;i<words.sz;i++){
    string cur=words[i];
    reverse(all(cur));
    if(cur.find(texts[sex][1])==0){
      nou++;
    }else
      break;
  }
  for(;i<words.sz;i++){
    string cur=words[i];
    reverse(all(cur));
    if(cur.find(texts[sex][2])==0){
      ver++;
    }else
      break;
  }
  return (adj>=0 && nou==1 && ver>=0 && i==words.sz);  
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);  
  
    string line; 
    words.clear();   
    getline(cin,line);
    stringstream ss(line);
    while(ss>>line)words.push_back((line));
    int sx=getSex();
    if(isword() || (sx>=0 && issentence(sx))){
        cout<<"YES"<<endl;
    }else
       cout<<"NO"<<endl;
    
    //system("pause");
    return 0;
}
