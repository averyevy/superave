#include <bits/stdc++.h>
using namespace std;
#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 

#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss);  cout<< "LOG - line:" << __LINE__<< "      "; err(_it, args); cout <<endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a <<"; ";
	err(++it, args...);
}


int main() {
    IO("gymnastics");
	int K,N;
	cin >> K>> N;
    int sessions[K][N+1];
    int scores[N+1][N+1];
    for(int i=1;i<N+1;i++)
    for(int j=1;j<N+1;j++) 
        scores[i][j] = 0;

    for(int i=0;i<K;i++) {
        for(int j=0;j<N;j++) {
            cin >> sessions[i][j];
            //log(sessions[i][j]);
        }
        for(int x=0; x<N;x++) {
            for(int y=x+1; y<N;y++) {
                scores[sessions[i][x]][sessions[i][y]]++;
            }
        }
    }
    int count = 0;
    for(int i=1;i<N+1;i++)
    for(int j=1;j<N+1;j++) {
        if (scores[i][j] == K) {
            count++;
        }
    }
    cout<<count;
        
  
}
