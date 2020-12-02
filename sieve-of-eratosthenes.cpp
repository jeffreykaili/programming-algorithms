#include <bits/stdc++.h>
using namespace std;
#define finp cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);
#define ll long long
#define FOR(i, a) for (int i=1; i<=(a); ++i)
#define FORz(i, a) for (int i=0; i<(a); ++i)
#define FORr(i, a, b) for (int i=a; i<(b); ++i)
const int mx=1e6+5; 
bool sieve[mx]; 
/*
- marks primes/composite numbers through precomputation 
- O(N log log N) time (almost linear)
- doesn't work if N is ridiculously large, but something known as segmeneted sieve can be used instead
*/
int main() {
	finp
	sieve[1]=1;
	FORr(i,2,sqrt(mx)+1){
		if(!sieve[i])
			for(int j=i*i;j<=mx;j+=i)
				sieve[j]=1;
	}
	// reference question: https://dmoj.ca/problem/dwite09c7p2
	FOR(i,5){
		int n; cin >> n;
		ll res=0;
		for(int i = 2; i <= n; ++i) res += (!sieve[i])?i:0;  
		cout << res << "\n"; 
	}
}