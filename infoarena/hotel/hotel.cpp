#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("hotel.in");
ofstream fout("hotel.out");

using VI = vector<int>;

int n, m;
VI aib, st, dr;

void read();
void solve();
int query();
void SetVal(int node, int val);
void Build(int node, int lb, int rb);
void pushDown(int node, int lb, int rb);
void update(int node, int lb, int rb, int a, int b, int val);

int main() {
	read();
	solve();
	return 0;
}

void update(int node, int lb, int rb, int a, int b, int val) {
	if (a <= lb && b >= rb) {
		SetVal(node, (rb - lb + 1) * val);
		return;
		// don't update sons
	}
	
	// no more lazy
	pushDown(node, lb, rb);
	int mb = lb + (rb - lb) / 2;
	
	if (a <= mb) {
		update(2 * node, lb, mb, a, b, val);
	}
	if (b > mb) {
		update(2 * node + 1, mb + 1, rb, a, b, val);
	}
	
	st[node] = st[2 * node];
	dr[node] = dr[2 * node + 1];

	if (st[2 * node] == mb - lb + 1) {
		st[node] += st[2 * node + 1];
	}
	
	if (dr[2 * node + 1] == rb - mb) {
		dr[node] += dr[2 * node];
	}
	
	aib[node] = max(aib[2 * node], aib[2 * node + 1]);
	aib[node] = max(aib[node], dr[2 * node] + st[2 * node + 1]);
}

void pushDown(int node, int lb, int rb) {
	if (aib[node] == 0) {
		SetVal(2 * node, 0);
		SetVal(2 * node + 1, 0);
	}
	
	if (aib[node] == (rb - lb + 1)) {
		int mb = lb + (rb - lb) / 2;
		SetVal(2 * node, mb - lb + 1);
		SetVal(2 * node + 1, rb - mb);
	}
}

void SetVal(int node, int val) {
	aib[node] = st[node] = dr[node] = val;
}

void Build(int node, int lb, int rb) {
	aib[node] = st[node] = dr[node] = rb - lb + 1;
	
	if (lb >= rb) return;
	
	int mb = lb + (rb - lb) / 2;
	Build(2 * node, lb, mb);
	Build(2 * node + 1, mb + 1, rb);
}

int query() {
	return aib[1];
}

void read() {
	fin >> n >> m;
	
	aib = st = dr = VI(4 * n);
	Build(1, 1, n);
}

void solve() {
	int op, x, y;
	while (m--) {
		fin >> op;
		
		if (op == 1) {
			fin >> x >> y;
			update(1, 1, n, x, x + y - 1, 0);
		} else if (op == 2) {
			fin >> x >> y;
			update(1, 1, n, x, x + y - 1, 1);
		} else {
			fout << query() << '\n';
		}
	}
}