#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int left = 0, right = height.size() - 1;
		int ans = -1;

		while (left < right) {
			// calculate sum
			ans = max(ans, 
								min(height[left], height[right]) * (right - left)
				);

			if (height[left] < height[right])
			{
				left += 1;
			}
			else
			{
				right -= 1;
			}
		}

		return ans;
	}
}

int main()
{
	int n;
	cin >> n;

	std::vector<int> v(n);
	for (auto &i : v)
	{
		cin >> i;
	}

	cout << maxArea(v);
}