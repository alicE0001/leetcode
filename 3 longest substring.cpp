#include<iostream>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> My_map;
		int begin = 0;
		int end = 0;
		int l = 0;
		for(int i=0;i<s.length();i++){
			if(!My_map.count(s[i])){
				My_map.insert(pair<int,int>(s[i],i));
			}
			else if(My_map.count(s[i]) && My_map.find(s[i])->second < begin){
				My_map.find(s[i])->second = i;
			}
			else{
				begin = My_map.find(s[i])->second + 1;
				My_map.find(s[i])->second = i;
			}
			end = i;
			l = l>(end-begin+1)?l : (end-begin+1);
		}

		return l;
    }
};

int main(){
	Solution t;
	string s = "aaaaa";
	int l = t.lengthOfLongestSubstring(s);
	cout << l;

	system("pause");
	return 0;
}