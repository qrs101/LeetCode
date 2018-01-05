#include <iostream>

using namespace std;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* p = res;
        int carry = 0;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int num1 = 0;
            int num2 = 0;
            if (p1 != nullptr) {
                num1 = p1->val;
                p1 = p1->next;
            }

            if (p2 != nullptr) {
                num2 = p2->val;
                p2 = p2->next;
            }

            int num = num1 + num2 + carry;
            carry = num / 10;
            p->next = new ListNode(num % 10);
            p = p->next;
        }

        return res->next;
    }
};