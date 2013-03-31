#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int N;
   cin >> N;
   while(N){
      string line="";
      set<string> st;
      set<string>::iterator it;
      cin >> line;
      for(int i=0;i<line.size();i++){
         for(int j=i+1;j<line.size();j++){
            char p=line[i];
            line[i]=line[j];
            line[j]=p;
            st.insert(line);
         }
      }
      for(it=st.begin();it!=st.end();++it)
         cout << *it<<endl;
      N--;
   }
}
