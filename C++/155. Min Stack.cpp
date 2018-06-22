#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinStack {
private:
    int i;
    int min;
    vector<int> stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        i = -1;
        min = INT_MAX;
    }

    void push(int x) {
        i++;
        if (i < stack.size())
            stack[i] = x;
        else
            stack.push_back(x);
        if (min > x)
            min = x;
    }

    void pop() {
        if (min == stack[i]) {
            min = INT_MAX;
            for (int j = 0; j < i; j++)
                if (min > stack[j])
                    min = stack[j];
        }
        i--;
    }

    int top() {
        return stack[i];
    }

    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */