#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		string ans;
		int max = 0;
		int begin = 0;
		int j = 0;
		for(int i=0;i<s.length();i++){
			j = 0;
			while( (i-j)>=0  && (i+j)<s.length() && s[i+j] == s[i-j]){
				j ++;
			}
			if( (2*j - 1)>max){
				begin = i-j+1;
				max = 2*j - 1;
			}

			j = 0;
			while( (i-j)>=0 && (i+1+j)<s.length() && s[i+1+j] == s[i-j]){
				j ++;
			}
			if(2*j>max){
				begin = i-j+1;
				max = 2*j;
			}
		}
		ans = s.substr(begin,max);
		return ans;
    }
};

int main(){
	Solution t;
	string s = "gfdabccbacqp";
	string ans;
	ans = t.longestPalindrome(s);
	cout << ans << endl;
	system("pause");
	return 0;
}