#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
        {
            cin >> i;
        }
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                cout << v[i] << ' ' << v[j] << "=> ";
                cout << v[i] | v[j];
                cout << '\n';
            }
        }
    }
    return 0;
}
