class Stack:
    def __init__(self):
        self.item = list()

    def isempty(self):
        return len(self.item) == 0

    def push(self, x):
        self.item.append(x)

    def pop(self):
        return self.item.pop()

    def top(self):
        return self.item[-1]

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        S = Stack()
        M = {')' : '(', ']' : '[', '}' : '{'}
        for i in s:
            if i is '(' or i is '[' or i is '{':
                S.push(i)
            else:
                if S.isempty():
                    return False
                if S.top() != M[i]:
                    return False
                S.pop()
        if S.isempty():
            return True
        return False