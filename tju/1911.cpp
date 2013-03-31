#include <iostream>
#include <cstdio>

using namespace std;

string line,data;
bool isVowel(char c){
   if(c=='a'||c=='e'|| c=='i'||c=='o'||c=='u')
      return 1;
   return 0;
}
bool convowel(){
   for(int i=0;i<line.size();i++)
      if(isVowel(line[i]))
         return 1;
   return 0;
}

bool consvowel(){
   for(int i=0;i<line.size();i++)
      if(isVowel(line[i])){
         int j=i;
         while(j<line.size()&&isVowel(line[j])){
            j++;
         }
         if(j-i>=3)return 0;
         i=j;
      }
    return 1;
}

bool notvowel(){
   for(int i=0;i<line.size();i++)
      if(!isVowel(line[i])){
         int j=i;
         while(j<line.size()&&!isVowel(line[j])){
            j++;
         }
         if(j-i>=3)return 0;
         i=j;
      }
   return 1;
}
bool conse(){
   for(int i=0;i+1<line.size();i++){
      if(line[i]=='e' || line[i]=='o')
         continue;
      if(line[i]==line[i+1]) return 0;
   }
   return 1;

}
string da(){
return string(1,'<')+line+"> is";

}

int main(){
   bool ok;
   //freopen("out","w",stdout);
   while(cin>>line){
      if(line=="end")break;
      ok=convowel()&&consvowel()&&notvowel()&&conse();
      cout<<da();
      if(ok)
         printf(" acceptable.\n");
      else
         printf(" not acceptable.\n");      
   
   }

}
