#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;

vector<string> split(string str){
   int p=0;
   int q=0;
   vector<string> ans;
   str=str+";";
   for(int i=0;i<str.sz;i++){
      if(str[i]==';'){
         ans.push_back(str.substr(p,q));
         q=0;
         p=i+1;
      }else
         q++;
   }
   return ans;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string line;
    while(getline(cin,line)&&line!="#"){
      vector<string> vs=split(line);
      map<char,int>M;
      set<char>S;
      
      for(int i=0;i<vs.sz;i++)
         for(int j=0;j<vs[i].sz;j++)if(isalpha(vs[i][j]))S.insert(vs[i][j]);
      vector<char> vc(all(S));
      int ans=12;
      string res="";
      do{
         M.clear();
         int cn=1;
         string pue="";
         for(int i=0;i<vc.sz;i++){
            M[vc[i]]=i;
            pue=pue+" "+vc[i];
         }
         
         for(int i=0;i<vs.sz;i++){
            for(int j=2;j<vs[i].sz;j++){
               cn=max(cn,abs(M[vs[i][j]]-M[vs[i][0]]));
            }
         }
         if(cn<ans){
            res=pue;
            ans=cn;
         }
      }while(next_permutation(all(vc)));     
      cout<<res.substr(1)<<" -> "<<ans<<endl;
    }
    return 0;
}
