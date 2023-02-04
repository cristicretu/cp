#include <fstream>
#include <vector>

using namespace std;

ifstream fin("distincte.in");
ofstream fout("distincte.out");

const int maxN = 1e5, MOD = 666013;

// vector<int> ar;
int aib[maxN + 1], a[maxN + 1];
int n, k, m;

// void Build(int st, int dr, int n)
// {
//   if (st == dr)
//   {
//     fin >> ar[n];
//     return;
//   }

//   int mid = (st + dr) / 2;
//   Build(st, mid, 2 * n);
//   Build(mid + 1, dr, 2 * n + 1);
//   ar[n] = ar[2 * n] + ar[2 * n + 1];
// }

// void update(int nod, int st, int dr, int a, int b)
// {
//   if (st == dr)
//   {
//     ar[nod] -= b;
//     return;
//   }

//   int mid = (st + dr) / 2;
//   if (a <= mid)
//     update(nod * 2, st, mid, a, b);
//   else
//     update(nod * 2 + 1, mid + 1, dr, a, b);

//   ar[nod] = ar[2 * nod] + ar[2 * nod + 1];
// }

// int query(int nod, int st, int dr, int a, int b)
// {
//   if (st >= a && dr <= b)
//   {
//     return ar[nod];
//   }

//   int sum = 0;
//   int mid = (st + dr) / 2;
//   if (a <= mid)
//     sum += query(2 * nod, st, mid, a, b);
//   if (b > mid)
//     sum += query(2 * nod + 1, mid + 1, dr, a, b);

//   return sum;
// }

void update(int poz, int val)
{
  for (int i = poz; i <= n; i += (i & (-i)))
  {
    aib[i] = (aib[i] + val) % MOD;
  }
}

int query(int poz)
{
  int sum = 0;
  for (int i = poz; i; i -= (i & (-i)))
  {
    sum = (sum + aib[i]) % MOD;
  }
  return sum;
}

int main()
{
  fin >> n >> k >> m;

  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i];
    update(i, a[i]);
  }

  int a, b;
  while (m--)
  {
    fin >> a >> b;
  }
  // ar.resize(4 * n);
  // Build(1, n, 1);

  // int a, b;
  // while (m--)
  // {
  //   fin >> a >> b;
  //   fout << query(1, 1, n, a, b) << '\n';
  // }
}