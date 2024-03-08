/*
ID: avelynj1
TASK: test
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss);  cout<< "LOG - line:" << __LINE__<< "      "; err(_it, args); cout <<endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a <<"; ";
    err(++it, args...);
}

void printarr(int a[], int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
}

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 


int main() {
    int N;
    cin >> N;
    int A[N+1],B[N+1];
    bool moved[N+1];
    map<int,int> labels;
    for(int i=1;i<N+1;i++) cin >>A[i];
    for(int i=1;i<N+1;i++) {
        cin >>B[i];
        labels[B[i]] = i;
        moved[i] = 0;
    }
  
    int cnt=0, k = 1;
    for(int i=1;i<=N;i++) {
        while (moved[A[k]]) k++;
        if (B[i]==A[k]) k++;
        else {
            cnt++;
            moved[B[i]] = true;
        }
    }
    cout<<cnt;    
}
    
