## Parallel Processing


```cpp

ll n;
ll a[200001], s[200001], t[200001];

int main(void) {
    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 1; i < n-1; i++) cin >> s[i] >> t[i];

    for(int i = 1; i < n-1; i++) a[i+1] += (a[i] / s[i]) * t[i];
    cout << a[n] << endl;

    return 0;
}
```


## Memorized Recursion Optimize 

```cpp
map<long long, long long> m;
long long f(long long N) {
  if (N == 1) return 0;
  if (m.count(N)) return m[N];
  return m[N] = f(N / 2) + f((N + 1) / 2) + N;
}
int main() {
  long long N;
  cin >> N;
  cout << f(N) << endl;
}

```
## Fixing one side
```cpp

INF = 10**18

ans = 0
for x in range(max(Q) + 1):
    y = INF
    for i in range(N):
        if Q[i] < A[i] * x:
            y = -INF
        elif B[i] > 0:
            y = min(y, (Q[i] - A[i] * x) // B[i])
    ans = max(ans, x + y)
print(ans)

```

## Using regular expressions
```cpp
int main() {
    string S;
    cin >> S;
    if (regex_match(S, regex("A*B*C*"))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
```

## Using lower_bound(), upper_bound() the array should be sorted first
```cpp
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	sort(a, a+n);
	ll maxA=0;
	for(ll i=0; i<n;i++) {
		ll cnl=lower_bound(a,a+n,a[i]+m)-a-i;
		maxA = max(maxA,cnl);
	}
	cout<<maxA;

//in an array
sort(a, a+n);
int ans = upper_bound(a, a + n, q) - a;

```

## Ceiling of int div
```cpp
ll div_up(ll x, ll y)
{
    return  x/y + (x % y != 0);
}
```

## Prefix sum processing to get the max sum of consecutive 
```cpp
	vector<int> p(n+1);
	vector<int> diff(n+1);
	
	for(int i=1;i<=n;i++) { 
		cin>>a[i];
		p[i] = p[i-1] + a[i];
	}
	int ans = inf;
	int index = -1;
	for(int i=0;i<=n-k;i++) { 
		diff[i] = p[i+k]-p[i];
		if ( diff[i] < ans ) {
			ans = diff[i];	
			index = i+1;
		}
	}
```

## Using stack to delete/detect the consecutive same elements in a string
```cpp
	stack<char> stk;
	
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (!stk.empty() && stk.top() == s[i]) {
			cnt++;
			stk.pop();
		}	
		else {
			stk.push(s[i]);
		}
    }
	cout<< ((cnt % 2 == 1) ? "Yes" : "No") <<endl;

```
