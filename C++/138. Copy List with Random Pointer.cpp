#include <iostream>
#include <map>
using namespace std;

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return nullptr;
        map<RandomListNode*, RandomListNode*> M;
        RandomListNode* p;
        for (p = head; p != nullptr; p = p->next) {
            M[p] = new RandomListNode(p->label);
            //M.insert(map<RandomListNode*, RandomListNode*>::value_type(p, new RandomListNode(p->label)));
        }
        for (p = head; p != nullptr; p = p->next) {
            M[p]->next = M[p->next];
            M[p]->random = M[p->random];
        }
        return M[head];
    }
};