//方法一：找出最长的后缀 9
只需要对数组 digits 一次逆序遍历，找出第一个不为 9 的元素，将其加一并将后续所有元素置零即可。
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};

//法二：模拟过程
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int m = digits.size();
        digits[m-1]++;
        for (int i = m - 1; i > 0; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i-1]++;
            }
        }
        
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
    
};

