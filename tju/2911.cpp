#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;
int L,N;
string a,b,k;
//char[60] ca,cb;

bool isc(char a){
   if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
      return 0;
   return 1;
}

int main(){
   scanf("%d %d\n",&L,&N);
   map<string,string>M;
   vector<string> V;
   for(int i=0;i<L;i++){
     cin>>a>>b;
     M[a]=b; 
   }
   for(int i=0;i<N;i++){
      cin>>a;
      V.push_back(a);
   }
   for(int i=0;i<V.size();i++){
      a=V[i];
      b=a.substr(a.size()-1,1);
      k=a.substr(a.size()-2,2);
      //cout<<k<<endl;
      if(M[a]!=M["-----"])
         printf("%s\n",M[V[i]].c_str());
      else if(isc(k[0]) && k[1]=='y'){
         printf("%sies\n",a.substr(0,a.size()-1).c_str());
      }else if(b=="o"|| b=="s" || b=="x" || k=="ch" || k=="sh")
         printf("%ses\n",a.c_str());
       else
         printf("%ss\n",a.c_str());
   }
   return 0;
}
