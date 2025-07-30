//160. 相交链表
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
    //当两个链表没有交点的时候，其实可以看成两个链表的交点是 nullptr节点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;

        while(t1 != t2)
        {
            t1 = t1 != nullptr ? t1->next : headB;
            t2 = t2 != nullptr ? t2->next : headA;
        }
        return t1;
    }
};
