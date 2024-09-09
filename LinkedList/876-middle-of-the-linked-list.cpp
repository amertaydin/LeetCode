// https://leetcode.com/problems/middle-of-the-linked-list/description/

// Time Complexity O(n)

// Space Complexity 0(1)

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *curr = head;
        int size = 0;
        int count = 0;

        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }

        for (int i = 0; i < count / 2; i++)
        {
            head = head->next;
        }

        return head;
    }
};