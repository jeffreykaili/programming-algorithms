#include <bits/stdc++.h>
using namespace std;
#define finp cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);
#define ll long long
#define FOR(i, a) for (int i=1; i<=(a); ++i)
#define FORz(i, a) for (int i=0; i<(a); ++i)
#define FORr(i, a, b) for (int i=a; i<(b); ++i)
const int mx=1e5+5; 
int link[mx], size[mx]; 
/*
add later im too lazy
*/ 
int find(int x) { // finds root 
	int rt = x; 
	while(rt != link[rt]) rt = link[rt]; 
	while(x != rt) {
		int next = link[x];
		link[x] = rt; 
		x = next; 
	}
	return rt; 
}
bool connected(int a, int b) { // check is same component
	return find(a) == find(b); 
}
void unite(int x, int y) { // unites two components 
	int a = find(x);
	int b = find(y); 
	if(a == b) return; 
	if(size[a] < size[b]) swap(a, b);
	size[a] += size[b]; 
	link[b] = a; 
}
int main() {
	; 
}