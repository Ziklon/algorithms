/*
ID: winftc2
PROG: calfflac
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
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
string get(string& s){
  string ans="";
  for(int i=0;i<s.sz;i++)
    if(isalpha(s[i]))
        ans+=tolower(s[i]);
  return ans;
}
bool ispal(string& s){
  for(int x=0,y=s.sz-1;x<y;x++,y--)
    if(s[x]!=s[y]){
      return 0;
  } 
  return 1;
}
int main(){
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string text="",st,pal,ans="",aux,tmp,sol="";
    string a,b,c;
    while(getline(cin,st))
      text+=st+"\n";
    pal=get(text);
    int cmx=0,aa,bb;
    
    for(int i=1;i<text.sz;i++){
      int right=i+1;
      int left=i-1;
      int count=0;
      if(pal[i]==pal[right]){
        count=2;
        right++;
      }else if(pal[right]==pal[left]){
          count=3;
          left--;
          right++;
      }
      while(left>=0 && right<pal.sz && pal[left]==pal[right]){
        left--;
        right++;
        count+=2;
      }
      if(count>cmx){
        aa=left;
        bb=right;
        cmx=count;
      }
    }
    ans=pal.substr(aa+1,bb-aa-1);
    int j=0;
    for(int i=0;i<text.sz && j<ans.sz ;i++){
        char cur=text[i];
        if(j==0)sol="";
        if(isalpha(cur)){
          cur=tolower(cur);          
          if(cur==ans[j]){
            j++;
          }
          else{
            sol="";
            if(cur==ans[0]){
              j=1;
            }else{
              j=0;
            }            
          }
        }
        sol+=text[i];
    }
    cout<<ans.sz<<endl;
    cout<<sol<<endl;
    
    //system("pause");
    return 0;
}
