#include <fstream>

unsigned long long makeSwaps(int q, int  a[], int b[]);
void init(int n, int nrTestCase);

int main()
{
    std::ifstream fin("ghemotoace.in");
    std::ofstream fout("ghemotoace.out");

    int n, t, nrTestCase;
    fin >> n >> t >> nrTestCase;

    init(n, nrTestCase);

    for(int i = 1; i <= t; ++i)
    {
        int q;
        fin >> q;

        int *a = new int[q];
        int *b = new int[q];

        for(int j = 0; j < q; ++j)
        {
            fin >> a[j] >> b[j];
        }

        fout << makeSwaps(q, a, b) << '\n';

        delete[] a;
        delete[] b;
    }

    fin.close();
    fout.close();
    return 0;
}
