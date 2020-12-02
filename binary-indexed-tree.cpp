#include <bits/stdc++.h>
using namespace std;
#define finp cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);
#define ll long long
#define FOR(i, a) for (int i=1; i<=(a); ++i)
#define FORz(i, a) for (int i=0; i<(a); ++i)
#define FORr(i, a, b) for (int i=a; i<(b); ++i)
const int mx=1e6+5; 
/*
Use: can calculate prefix sums in O(logn) and update in O(logn)

Important:
- array is assumed to be 1 indexed
- doesn't work for negatives, so use an offset if negative numbers are possible
*/ 
int bit[mx]; 
void update(int idx, int add) { 
	// note that this only adds/decreases the element at idx
	// to update to a new value, store an input array or just query the current element at idx and 
	// add/subtract the difference
	while(idx < mx) {
		bit[idx] += add;
		idx += idx & (-idx); 
	}
}
int query(int idx) {
	int res = 0; 
	while(idx) {
		res += bit[idx]; 
		idx -= idx & (-idx); 
	}
	return res; 
}
int main() {
	int n; cin >> n;
	FOR(i,n) {
		int x; cin >> x;
		update(i, x); 
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		cout << query(r) - query(l-1) << "\n"; 
	}
}