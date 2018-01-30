#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1 = head;
        if (p1 == nullptr)
            return nullptr;
        ListNode* p2 = head->next;
        if (p2 == nullptr)
            return p1;
        ListNode* res = p2;
        while (p1 != nullptr && p2 != nullptr) {
            ListNode* p3 = p2->next;
            p2->next = p1;
            if (p3 == nullptr || p3->next == nullptr) {
                p1->next = p3;
                break;
            } else {
                p1->next = p3->next;
                p1 = p3;
                p2 = p3->next;
            }
        }
        return res;
    }
};

int main() {
    ListNode* p = new ListNode(1);
    ListNode* q = p;
    q->next = new ListNode(2);
    q = q->next;
    q->next = new ListNode(3);
    q = q->next;
    q->next = new ListNode(4);
    q = q->next;
    q->next = new ListNode(5);
    Solution so;
    q = so.swapPairs(p);
    while (q != nullptr) {
        cout << q->val << endl;
        q = q->next;
    }
    return 0;
}