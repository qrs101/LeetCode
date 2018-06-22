#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        queue<UndirectedGraphNode*> OriginGraph_Queue;
        queue<UndirectedGraphNode*> NewGraph_Queue;
        map<int, UndirectedGraphNode*> Map;
        UndirectedGraphNode* ans = new UndirectedGraphNode(node->label);
        OriginGraph_Queue.push(node);
        NewGraph_Queue.push(ans);
        Map.insert(map<int, UndirectedGraphNode*>::value_type(ans->label, ans));
        while (!OriginGraph_Queue.empty()) {
            UndirectedGraphNode* originNode = OriginGraph_Queue.front();
            UndirectedGraphNode* newNode = NewGraph_Queue.front();
            OriginGraph_Queue.pop();
            NewGraph_Queue.pop();
            for (auto i : originNode->neighbors) {
                if (Map.find(i->label) != Map.end()) {
                    newNode->neighbors.push_back(Map[i->label]);
                } else {
                    UndirectedGraphNode* tmp = new UndirectedGraphNode(i->label);
                    newNode->neighbors.push_back(tmp);
                    OriginGraph_Queue.push(i);
                    NewGraph_Queue.push(tmp);
                    Map.insert(map<int, UndirectedGraphNode*>::value_type(i->label, tmp));
                }
            }
        }
        return ans;
    }
};