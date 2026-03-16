//法一：用哈希表存储出现次数
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>table(26,0);
        if(s.length()!=t.length())return false;
        for(char&ch:s){
            table[ch-'a']++;
        }
        for(char&ch:t){
            table[ch-'a']--;
            if(table[ch-'a']<0)return false;
        }
        return true;
    }
};

//法二：排序后比较
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

