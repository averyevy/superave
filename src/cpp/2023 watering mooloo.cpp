
void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+1,0ll);
    vector<ll> C(N+1,0ll);
    for(ll i=1;i<=N;i++) {
        cin>>A[i];
    } 
    ll s = A[1];
    C[1] =  1ll + K;
    log(C[1]);
    for(ll i=2;i<=N;i++) {
        ll cost = C[i-1] + 1 + K;
      //The key is A[i]-A[i-1] 
       //or we always update the s when the new window start.s\ 
        //ll addon = C[i-1] + (A[i]-A[i-1]);
         ll addon = C[i-1] + (A[i]-s);
        if ( addon < cost ) {
            C[i] = addon;
           
        }
        else {
            C[i] = cost;
        }
        s = A[i];
        log(C[i]);
    }
    cout<<C[N];
 }

int main() {
    // int t;
    // cin >> t;
    // for(int i=0;i<t;i++)
        solve();
}
