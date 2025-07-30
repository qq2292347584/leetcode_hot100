//234. 回文链表
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
    bool isPalindrome(ListNode* head) {
        vector<int> array;
        while(head != nullptr)
        {
            array.push_back(head->val);
            head = head->next;
        }

        int n = array.size();
        for(int l = 0, r = n - 1; l <= r; l++, r--)
        {
            if(array[l] != array[r]) return false;
        }
        return true;
    }
};