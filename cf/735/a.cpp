#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        for (auto &i : v)
        {
            cin >> i;
        }
        long long ans = 0;
        for (int i = 1; i < n; ++i)
        {
            ans = max(ans,1LL *  v[i] * v[i - 1]);
        }
        cout << ans << endl;
    }
}
