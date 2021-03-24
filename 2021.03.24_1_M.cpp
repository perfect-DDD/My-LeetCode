//给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。
//设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
//
//注意：n 的值小于15000。
//
//示例 3 :
//输入 : [-1, 3, 2, 0]
//输出 : True
//解释 : 序列中有 3 个132模式的的子序列 : [-1, 3, 2] , [-1, 3, 0] 和[-1, 2, 0].
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/132-pattern
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class mySolution {
public:
    bool find132pattern(vector<int>& nums) {
        int index;
        for (int i = 0; i < nums.size(); i++) {
            index = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    if (nums[j] < index)
                        return true;
                    else index = nums[j];
                }
            }
        }
        return false;
    }
};

class bestSolution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        stack <int> st;
        vector <int> mins(n);
        mins[0] = nums[0];
        for (int i = 1; i < n; i++)
            mins[i] = min(mins[i - 1], nums[i]);
        for (int j = n - 1; j >= 0; j--)
        {
            if (nums[j] > mins[j])
            {
                while (!st.empty() && st.top() <= mins[j])
                    st.pop();
                if (!st.empty() && st.top() < nums[j])
                    return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};

void main() {
    vector<int> nums = { -1, 3, 2, 0 };
    mySolution mytest;
    cout << mytest.find132pattern(nums) << endl;
}
