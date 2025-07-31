//25. K个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* cnt = head;
        int n = 0;
        while(cnt != nullptr)
        {
            n++;
            cnt = cnt->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* p0 = dummy;
        while(n >= k)
        {
            n -= k;
            for(int i = 0; i < k; i++)
            {
                ListNode* t = cur->next;
                cur->next = pre;
                pre = cur;
                cur = t;
            }

            ListNode* t = p0->next;
            p0->next = pre;
            t->next = cur;
            p0 = t;
        }

        return dummy->next;
    }
};