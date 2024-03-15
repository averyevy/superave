void solve() {
    ll N, M;
    cin >> N >> M;
    ll a[N];
    ll e[M]={0};
    ll c[M];
    for(ll i=0;i<N;i++) cin>>a[i];
    for(ll i=0;i<M;i++) cin>>c[i];
    bool remaining = false, caneat = false;
    for(ll i=0;i<M;i++) {
       
        for(ll j=0;j<N;j++) {
            if (a[j] > e[i] && c[i] > 0 ) {
                ll eat = min( a[j] - e[i], c[i]);
                c[i] = c[i] - eat;
                e[i] += eat;
                a[j] += eat;
            }
          //the key is to break when no candy left  
            if ( c[i] <= 0) break;
        }
        
    }
     for(ll j=0;j<N;j++) {
         cout<<a[j]<<"\n";
     }
}
