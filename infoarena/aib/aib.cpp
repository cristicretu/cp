#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

static const int maxn = 1e5;

int n, m;
int a[maxn + 1];

void read();
void solve();
void update(int x, int val);
int query(int x);
int cb(int x);

int main() {
	read();
	solve();
}


void update(int x, int val) {
	for (int i = x; i <= n; i += (i & -i)) {
		a[i] += val;
	}
}

int query(int x) {
	int s = 0;
	for (int i = x; i; i -= (i & -i)) {
		s += a[i];
	}
	return s;
}

int cb(int x) {
	int lb = 1, rb = n;
	int ans = -1;
	
	while (lb <= rb) {
		int mb = lb + (rb - lb) / 2;
		int Q = query(mb);
		
		if (Q == x) {
			rb = mb - 1;
			ans = mb;
		} else if (Q < x) {
			lb = mb + 1;
		} else {
			rb = mb - 1;
		}
	}
	
	return ans;
}

void read() {
	fin >> n >> m;
	int x;
	for (int i = 1; i <= n; ++i) {
		fin >> x;
		update(i, x);
	}
}

void solve() {
	int op, a, b;
	while (m--) {
		fin >> op >> a;
		
		if (op == 0) {
			fin >> b;
			update(a, b);
		} else if (op == 1) {
			fin >> b;
			fout << query(b) - query(a - 1) << '\n';
		} else {
			fout << cb(a) << '\n';	
		}
	}
}