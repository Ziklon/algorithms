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
      sort(line.begin(),line.end());
      do{
         st.insert(line);
      }while(next_permutation(line.begin(),line.end()));
      for(it=st.begin();it!=st.end();++it)
         cout << *it<<endl;
      N--;
   }
}
