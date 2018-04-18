#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        auto n = int(ratings.size());
        if (n == 0)
            return 0;
        vector<int> ans (n + 1, 0);
        int m = ratings[0];
        for (int i = 1; i < n; i++)
            if (ratings[i] < m)
                m = ratings[i];
        /*
        for (auto& i : ratings) {
            i = i - m + 1;
            cout << i << " ";
        }
        cout << endl;
         */
        ratings.insert(ratings.begin(), 0);
        helper(ratings, ans, n, 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            //cout << ans[i] << " ";
            sum += ans[i];
        }
        return sum;
    }
    /* 如果相邻同学分数相同必须保证分配相同数量糖果，则调用该函数
    int helper(vector<int>& rateings, vector<int>& ans, int n, int k) {
        if (k == n) {
            if (rateings[k - 1] < rateings[k])
                ans[k] = ans[k - 1] + 1;
            else if (rateings[k - 1] == rateings[k])
                ans[k] = ans[k - 1];
            else
                ans[k] = 1;
            return ans[k];
        }

        if (rateings[k - 1] < rateings[k]) {
            if (rateings[k] <= rateings[k + 1]) {
                ans[k] = ans[k - 1] + 1;
                helper(rateings, ans, n, k + 1);
            } else {
                int tmp = helper(rateings, ans, n, k + 1);
                ans[k] = max(ans[k - 1], tmp) + 1;
            }
        } else if (rateings[k - 1] == rateings[k]) {
            if (rateings[k] <= rateings[k + 1]) {
                ans[k] = ans[k - 1];
                helper(rateings, ans, n, k + 1);
            } else {
                ans[k] = ans[k - 1];
                int tmp = helper(rateings, ans, n, k + 1);
                if (tmp >= ans[k - 1]) {
                    for (int j = k; j > 0; j--) {
                        if (rateings[k] > rateings[k + 1])
                            ans[k] = ans[k + 1] + 1;
                        else if (rateings[k] == rateings[k + 1])
                            ans[k] = ans[k + 1];
                        else
                            break;
                    }
                }
            }
        } else {
            if (rateings[k] <= rateings[k + 1]) {
                ans[k] = 1;
                helper(rateings, ans, n, k + 1);
            }
            else
                ans[k] =  helper(rateings, ans, n, k + 1) + 1;
        }
        return ans[k];
    }
    */

    //如果相邻同学分数相同不必保证分配相同数量通过，也就是分配数量可以不太，则调用该函数
    int helper(vector<int>& rateings, vector<int>& ans, int n, int k) {
        if (k == n) {
            if (rateings[k - 1] < rateings[k])
                ans[k] = ans[k - 1] + 1;
            else
                ans[k] = 1;
            return ans[k];
        }

        if (rateings[k - 1] < rateings[k]) {
            if (rateings[k] <= rateings[k + 1]) {
                ans[k] = ans[k - 1] + 1;
                helper(rateings, ans, n, k + 1);
            } else {
                int tmp = helper(rateings, ans, n, k + 1);
                ans[k] = max(ans[k - 1], tmp) + 1;
            }
        } else if (rateings[k - 1] == rateings[k]) {
            if (rateings[k] <= rateings[k + 1]) {
                ans[k] = 1;
                helper(rateings, ans, n, k + 1);
            } else {
                ans[k] = helper(rateings, ans, n, k + 1) + 1;
            }
        } else {
            if (rateings[k] <= rateings[k + 1]) {
                ans[k] = 1;
                helper(rateings, ans, n, k + 1);
            }
            else
                ans[k] =  helper(rateings, ans, n, k + 1) + 1;
                if (ans[k - 1] <= ans[k]) {
                    for (int j = k; rateings[j - 1] > rateings[j]; j--) {
                        ans[j - 1] = ans[j] + 1;
                    }
                }
        }
        return ans[k];
    }
};

int main() {
    Solution so;
    vector<int> a {1,2,2,3,10,9};
    int ans = so.candy(a);
    cout << endl << ans << endl;
}