
#####The key point is to only look at the location points not all the ones. 

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<long long> G;
	vector<long long> L;
	long location[N];
	for(int i=0;i<N;i++) {
		char C;
		long long l;
		cin >> C >> l;
		
		if (C == 'G') G.push_back(l);
		else L.push_back(l);
		location[i] = l;
	}
	sort(G.begin(), G.end());
	sort(L.begin(), L.end());

	
	int liars = 10000000;
	for(int i=0;i<N;i++) {
		int Ll = 0, cntL = L.size();
		for(int j=0; j<cntL; j++) {
			if ( L[j] < location[i] ) {
				Ll++;
			}
		}

		int Gl = 0, cntG = G.size();
		for(int j=0; j<cntG; j++) {
			if ( G[j] > location[i] ) {
				Gl++;
			}
		}
		
		//log(i, Gl, Ll);
        liars = min(liars, Gl+Ll);
	}
    cout<<liars<<endl;
}

int main() {
 solve();

}
