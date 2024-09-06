// https://leetcode.com/problems/reverse-linked-list/description/

// Time Complexity: O(n)

// Space Complexity O

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
    ListNode *reverseList(ListNode *head)
    {

        // This is for using currentNode, head will be NULL at the end
        ListNode *current = nullptr;
        ListNode *prev = nullptr;

        while (head != nullptr)
        {
            current = head;
            head = head->next;
            current->next = prev;
            prev = current;
        }
        return current;
    }

    /* This is for using nextNode, nextNode will be NULL at the end

    ListNode *prevNode = NULL, *nextNode = NULL;

    while (head) {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }

    return prevNode;

    */
};