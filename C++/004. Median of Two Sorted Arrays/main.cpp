#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i, j, s;
        bool odd;
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if (m > n) {
            A.swap(B);
            int tmp = m;
            m = n;
            n = tmp;
        }

        if ((m + n) % 2 == 1) {
            odd = true;
            s = (m + n) / 2 + 1;
        } else {
            odd = false;
            s = (m + n) / 2;
        }

        int start = 0, end = m;
        while (start <= end) {
            i = (start + end) / 2;
            j = s - i;
            if ((i == 0 || j == n || A[i-1] <= B[j]) && (j == 0 || i == m || B[j-1] <= A[i]))
                break;
            else if (i > 0 && j < n && A[i-1] > B[j])
                end = i - 1;
            else if (j > 0 && i < m && B[j-1] > A[i])
                start = i + 1;
        }

        double x, y;
        if (i == 0)
            x = B[j-1];
        else if (j == 0)
            x = A[i-1];
        else
            x = max(A[i-1], B[j-1]);

        if (i == m)
            y = B[j];
        else if (j == n)
            y = A[i];
        else
            y = min(A[i], B[j]);

        if (odd)
            return x;
        else
            return (x + y) / 2;
    }
};

int main() {
    vector<int> a = {1,3};
    vector<int> b = {2};
    Solution so;
    double d = so.findMedianSortedArrays(a, b);
    cout << d << endl;

    return 0;
}