#include <fstream>
#include <vector>

using namespace std;

ifstream fin("datorii.in");
ofstream fout("datorii.out");

const int maxN = 15000;

vector<int> ar;
// int ar[maxN * 4];
int n, m;

void Build(int st, int dr, int n)
{
  if (st == dr)
  {
    fin >> ar[n];
    return;
  }

  int mid = (st + dr) / 2;
  Build(st, mid, 2 * n);
  Build(mid + 1, dr, 2 * n + 1);
  ar[n] = ar[2 * n] + ar[2 * n + 1];
}

void update(int nod, int st, int dr, int a, int b)
{
  if (st == dr)
  {
    ar[nod] -= b;
    return;
  }

  int mid = (st + dr) / 2;
  if (a <= mid)
    update(nod * 2, st, mid, a, b);
  else
    update(nod * 2 + 1, mid + 1, dr, a, b);

  ar[nod] = ar[2 * nod] + ar[2 * nod + 1];
}

int query(int nod, int st, int dr, int a, int b)
{
  if (st >= a && dr <= b)
  {
    return ar[nod];
  }

  int sum = 0;
  int mid = (st + dr) / 2;
  if (a <= mid)
    sum += query(2 * nod, st, mid, a, b);
  if (b > mid)
    sum += query(2 * nod + 1, mid + 1, dr, a, b);

  return sum;
}

int main()
{
  fin >> n >> m;
  ar.resize(4 * n);
  Build(1, n, 1);

  int op, a, b;
  while (m--)
  {
    fin >> op >> a >> b;
    if (op == 0)
    {
      update(1, 1, n, a, b);
    }
    else if (op == 1)
    {
      fout << query(1, 1, n, a, b) << '\n';
    }
  }
}