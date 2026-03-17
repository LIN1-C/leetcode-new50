//法一：将nums当作栈
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int stack_size = 0;
        for (int x : nums) {
            if (x) {
                nums[stack_size++] = x; // 把 x 入栈
            }
        }
        fill(nums.begin() + stack_size, nums.end(), 0);
    }
};

//法二：双指针 只要不是零就往前放 慢指针总是指向非零元素位置
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i0 = 0;
        for (int& x : nums) { // 注意 x 是引用否则 swap 只会修改循环变量副本，无法修改原数组
            if (x) {
                swap(x, nums[i0]);
                i0++;
            }
        }
    }
};

