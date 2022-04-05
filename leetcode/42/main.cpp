#include <iostream>

using namespace std;

class Solution 
{
public:
	int trap(vector<int>& height)
	{
		stack<int> st;

		int answer = 0;

		for (int i = 0, n = height.size(); i < n; ++i) {
			while (!st.empty() && height[i] > height[st.top()])
			{
				int idx = st.top();
				st.pop();

				if (st.empty()) break;

				int h = min(height[i], height[st.top()]) - height[idx];
				int width = i - st.top() - 1;

				answer += h * width;
			}
			st.push(i);
		}

		return answer;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> height(n);

	for (auto &i: v) 
	{
		cin >> i;
	}

	trap(height);
}