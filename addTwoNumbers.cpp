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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        ListNode* cur = new ListNode((l1->val + l2->val) % 10);
        ans = cur;
        int car = (l1->val + l2->val) / 10;
        while(l1->next != nullptr && l2->next != nullptr) {
            l1 = l1->next;
            l2 = l2->next;
            cur->next = new ListNode((l1->val + l2->val + car) % 10);
            car = (l1->val + l2->val + car) / 10;
            cur = cur->next;
        }
        while(l1->next != nullptr) {
            l1 = l1->next;
            cur->next = new ListNode((l1->val + car) % 10);
            car = (l1->val + car) / 10;
            cur = cur->next;
        }
        
        while(l2->next != nullptr) {
            l2 = l2->next;
            cur->next = new ListNode((l2->val + car) % 10);
            car = (l2->val + car) / 10;
            cur = cur->next;
        }
        if(car != 0) {
            cur->next = new ListNode(car);
            car = 0;
        }
        return ans;
        
    }
};