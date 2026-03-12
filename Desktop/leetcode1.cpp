#include<iostream>
using namespace std;
const int max(int x,int y){
	return x>y?x:y;
}
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string A;
       	for(int i=0;i<max(word1.length(),word2.length());i++) {
       		if(i<word1.length()){
       			A+=word1[i];
			   }
       		if(i<word2.length()){
       			A+=word2[i];
			   }
		   }
    			return A;
	}
};

int main(){
	Solution sol;
	string x,y;
    std::cin >> x >> y;
	string ans=sol.mergeAlternately(x,y);
	std::cout<<ans;
}