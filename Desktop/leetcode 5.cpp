//法一：枚举字串的长度i 若重复则有s[j]=s[j-i]
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i) {
            if (n % i == 0) {
                bool match = true;
                for (int j = i; j < n; ++j) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};


//法二：字符串匹配（拼接两个s 若可重复必在中间存在字串s且不位于s末尾处）
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

//法三：kmp算法
class Solution {
public:
    // 构建next数组（前缀表）
    void getNext(vector<int>& next, const string& s) {
        next[0] = 0;  // 第一个字符的最长相等前后缀长度为0
        int j = 0;    // j表示前缀的末尾，也代表当前最长相等前后缀的长度
        // i从1开始，因为i=0的情况已经初始化
        for (int i = 1; i < s.size(); i++) {
            // 前后缀不相等时，回退j到上一个匹配位置
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];  // 回退到前一个位置的next值
            }
            // 前后缀相等时，j向后移动
            if (s[i] == s[j]) {
                j++;
            }
            // 记录当前位置的最长相等前后缀长度
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.empty()) {
            return false;
        }
        int len = s.size();
        
        vector<int> next(len);
        getNext(next, s);
        
        // 核心判断逻辑：
        // 1. next[len-1] != 0：说明存在非空的最长相等前后缀
        // 2. len % (len - next[len-1]) == 0：总长度能被子串长度整除
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
    }
};



