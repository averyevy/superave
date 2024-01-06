#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = a; i <= b; i++)

vector<int> subset;

void search(int k) { if (k == 4) {
   
   for (int i = 0; i< subset.size(); i ++) {
       cout<<subset[i]<<" ";
   }
   cout<<"--"<<endl;
   } else {
       // include k in the subset 
       subset.push_back(k); 
       search(k+1); 
       subset.pop_back();
        // don’t include k in the subset 
        search(k+1);
} 

}

int main() {
      
    // REP(i,0,2) {
    //     subset[i] = i+1;}
    
    for (int i = 0; i< subset.size(); i ++) {
       cout<<subset[i]<<' ';
    }
    cout<<"---start-----" <<endl;
      search(1);
}
