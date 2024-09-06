// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06

// Time Complexity: O(m + n)
// m from constructing the set from m sized array
// n from traversing the linked list of n size

// Space Complexity: O(n) : Insertion to set will take size of array

#include <vector>
#include <set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *modifiedList(std::vector<int> &nums, ListNode *head)
    {
        std::set<int> s(nums.begin(), nums.end());

        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = head;
        ListNode *prev = dummyHead;
        ListNode *toDelete = nullptr;
        dummyHead->next = head;

        while (curr != nullptr)
        {
            if (s.find(curr->val) != s.end())
            {
                prev->next = curr->next;
                toDelete = curr;
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;

            if (toDelete != nullptr)
            {
                delete toDelete;
                toDelete = nullptr;
            }
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};