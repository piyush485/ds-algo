#include<bits/stdc++.h>
using namespcace std;
int main()
{
   int T;
   cin >> T;
   while(T--)
   {
      int n,X;
      cin >> n >> X;
      map<int,int> m1;
      map<int,int> m2;

      for(int i = 0 ; i < n ; i++ )
      {
         int x;
         cin >> x;
         m1[x]++;
         m2[x^X]++;
      }
      map<int,int>::iterator iter;
      int maxx = 0;
      int minn = INT_MAX;
      for(auto it = m1.begin() ; it != m1.end() ; ++it)
      {
         iter = m2.find(it->first);
         if(iter != m2.end()){
            if((it->second + m2[it->first]) > maxx)
            {
               maxx = (it->second + m2[it->first]);
               minn = it->second;
            }
            else if((it->second + m2[it->first]) == maxx){
                  minn = min(minn, m2[it->first]);
            }
         }
      }
      cout << maxx <<" "<< minn << "\n";
   }
   return 0;
}