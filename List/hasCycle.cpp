//141. 环形链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* quick = head;

        while(slow && quick && quick->next)
        {
            slow = slow->next;
            quick = quick->next->next;
            if(slow == quick) return true;
        }
        return false;
    }
};
