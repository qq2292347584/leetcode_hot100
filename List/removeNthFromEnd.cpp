//19.删除链表的倒数第 N 个节点
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
    //空间复杂度为O(1)的做法
    //搞两个指针right left
    //right先走 n 步，然后left 和 right一起往前走
    //直到right->next == nullptr
    //由于会删除链表的头节点，所以最好设置一个dummy节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* left = dummy;
        ListNode* right = dummy;
        for(int i = 0; i < n; i++)
            right = right->next;
        while(right->next != nullptr)
        {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};
