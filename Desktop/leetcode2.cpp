//法一 暴力循环
class Solution {
public:
    char findTheDifference(string s, string t) {
        int m = s.length();
        for(int i=0; i<m+1; i++){
            int find=0;
            for(int j=0; j<m; j++){
                if(t[i]==s[j]) {
                    find=1;
                    s[j] = '\0'; 
                    break;
                }
            }
            if(find==0) return t[i];
        }
        return '\0';
    }
};

//法二 （答案）计数
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);  //  初始化长度为26的动态数组，默认初始值是0
        for (char ch: s) {       // 每次循环时，把字符串 s 里的「当前字符」赋值给变量 ch
            cnt[ch - 'a']++;//ch - 'a' 的作用：把字母转换成 0-25 的下标
        }
        for (char ch: t) {       
            cnt[ch - 'a']--;
            if (cnt[ch - 'a'] < 0) {  // 一旦某个计数变为负数，说明该字符就是多出的字符
                return ch;
            }
        }
        return ' ';  // 兜底返回（题目保证必有一个不同字符，理论上不会走到这里）
    }
};


//法三（求和作差算asc2码）
class Solution {
public:
    char findTheDifference(string s, string t) {
        int as = 0, at = 0;
        for (char ch: s) {
            as += ch;
        }
        for (char ch: t) {
            at += ch;
        }
        return at - as;
    }
};

//方法四：位运算：拼接成一个字符串转换成求字符串中出现奇数次的字符
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch: s) {
            ret ^= ch;
        }
        for (char ch: t) {
            ret ^= ch;
        }
        return ret;
    }
};
//ret ^= ch 等价于 ret = ret ^ ch
//异或运算的核心性质：
//a ^ a = 0：相同的数异或结果为 0。
//a ^ 0 = a：任何数和 0 异或结果不变。


