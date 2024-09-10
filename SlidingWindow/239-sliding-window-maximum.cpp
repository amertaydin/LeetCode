// https://leetcode.com/problems/sliding-window-maximum/description/?envType=company&envId=bookingcom&favoriteSlug=bookingcom-all
// Time Complexity O (n)
// Space Complexity O (k)

#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        if (nums.empty() || k == 0)
            return result;

        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};