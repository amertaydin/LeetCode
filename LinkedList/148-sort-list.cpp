//

// Time Complexity O(nlogn)

// Space Complexity O(n)

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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr; // need to break connection

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // handle the case where it has only one node
        if (prev != nullptr)
            prev->next = nullptr;

        return slow;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *mid = findMiddle(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode result(0);
        ListNode *ptr = &result;
        while (left && right)
        {
            if (left->val < right->val)
            {
                ptr->next = left;
                left = left->next;
            }
            else
            {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }

        if (left)
        {
            ptr->next = left;
        }

        if (right)
        {
            ptr->next = right;
        }

        return result.next;
    }
};