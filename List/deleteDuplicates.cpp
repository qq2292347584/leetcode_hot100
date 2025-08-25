//82.删除排序链表中的重复元素
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1000, head);
        ListNode* cur = dummy;
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            int x = cur->next->val;
            if(cur->next->next->val == x)
            {
                while(cur->next && cur->next->val == x)
                    cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
