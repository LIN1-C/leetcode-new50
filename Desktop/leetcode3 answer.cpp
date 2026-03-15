//方法一：暴力匹配

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        
        return -1;
    }
};


//法二：KMP算法
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组  每个位置对应最长前后缀长度
        for(int i = 2, j = 0; i <= m; i++){  //从2开始 因为next[1]=0
            while(j and p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = next[j]; //匹配串回到上次指向的最长前缀
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};
