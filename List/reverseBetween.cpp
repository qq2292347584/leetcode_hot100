//92.反转链表II
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* p0 = dummy;
        for(int i = 0; i < left - 1; i++)
            p0 = p0->next;

        ListNode* pre = nullptr;
        ListNode* cur = p0->next;
        for(int i = 0; i < right - left + 1; i++)
        {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }

        ListNode* t = p0->next;
        p0->next = pre;
        t->next = cur;

        return dummy->next;
    }
};