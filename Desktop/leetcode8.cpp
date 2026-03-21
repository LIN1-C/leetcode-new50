// 法一：一次遍历看是否同时存在两种
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = false;
            }
            if (nums[i] < nums[i + 1]) {
                dec = false;
            }
        }
        return inc || dec;
    }
};

//法二：二次遍历
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
    }
};//rbegin() 是 C++ 容器的反向迭代器成员函数，全称是 reverse begin。
它返回一个反向迭代器，指向容器的最后一个元素（即逆序遍历的起点）。
配合 rend()（指向容器首元素的前一个位置，逆序遍历的终点），可以实现对容器的从后往前遍历。


