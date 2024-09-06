  // https://leetcode.com/problems/remove-linked-list-elements/
  
  // Time Complexity: O(n) : We traverse the linked list once

  // Space Complexity O(1) : We don't use additional data structures.
  // Pointers we've created they take constant space.
  
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *prev = dummyHead;
        ListNode *curr = head;
        ListNode *toDelete = nullptr;
    
        while(curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                toDelete = curr;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        if (toDelete != nullptr) {
            delete toDelete;
            toDelete = nullptr;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};