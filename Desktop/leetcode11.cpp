法一：class Solution {
public:
    bool judgeCircle(string moves) {
      int x = 0, y = 0;
        for (char c : moves) {
            switch (c) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'R': x++; break;
                case 'L': x--; break;
            }
        }
        return x == 0 && y == 0;}
};
法二：class Solution {
public:
    bool judgeCircle(string moves) {
        return ranges::count(moves, 'R') == ranges::count(moves, 'L') &&
               ranges::count(moves, 'U') == ranges::count(moves, 'D');
    }
};
ranges::count 是 C++20 范围库 提供的新算法，直接统计容器 / 字符串中某个字符的出现次数
