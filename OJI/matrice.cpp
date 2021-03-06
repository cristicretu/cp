#include <fstream>
#include <unordered_map>
 
 
std::ifstream fin("matrice.in");
std::ofstream fout("matrice.out");
 
const int NMAX = 402;
 
int a[NMAX][NMAX], n;
long long s[NMAX][NMAX];
 
std::unordered_map <int, int> m;
 
long long Suma(int is, int js, int ij, int jj) 
{
	return (s[ij][jj] - s[is - 1][jj] - s[ij][js - 1] + s[is - 1][js - 1]);
}
 
int main()
{
	int mx = 0;
	fin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			fin >> a[i][j];
			if (a[i][j] > mx)
				mx = a[i][j];
			if (m.find(a[i][j]) == m.end())
				m[a[i][j]] = 1;
			else ++m[a[i][j]];
		}
 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
 
	int p = 0;
 
	for (int i = 1; i <= n; ++i)
	{
		if (s[i][i] <= mx)                     
		{										 
			if (m.find(s[i][i]) != m.end())
			{
				p += m[s[i][i]];
				m[s[i][i]] = 0;
			}
		}
	}
 
	for (int i = 1; i <= n; ++i)
	{
		int ni = i, nj = n - i + 1;
		int suma = Suma(1, nj, i, n);
		if (suma <= mx)
		{
			if (m.find(suma) != m.end())
			{
				p += m[suma];
				m[suma] = 0;
			}
		}
	}
 
	for (int i = 1; i <= n; ++i)
	{
		int ni = n - i + 1, nj = i;
		int suma = Suma(ni, 1, n, nj);
		if (suma <= mx)
		{
			if (m.find(suma) != m.end())
			{
				p += m[suma];
				m[suma] = 0;
			}
		}
	}
 
	for (int i = 1; i <= n; ++i)
	{
		int ni = n - i + 1, nj = n - i + 1;
		int suma = Suma(ni, nj, n, n);
		if (suma <= mx)
		{
			if (m.find(suma) != m.end())
			{
				p += m[suma];
				m[suma] = 0;
			}
		}
	}
 
 
	fout << p << "\n";
 
	fout.close();
	return 0;
}
