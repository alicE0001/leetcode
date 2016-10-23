#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> My_map;
		vector<int> ans;
		for(int i=0;i<nums.size();i++){
			My_map.insert(pair<int,int>(nums[i],i));
		}
		for(int i=0;i<nums.size();i++){
			if(My_map.count(target-nums[i]) && My_map.find(target-nums[i])->second != i){
				ans.push_back(My_map.find(target-nums[i])->second < i ? My_map.find(target-nums[i])->second : i);
				ans.push_back(My_map.find(target-nums[i])->second > i ? My_map.find(target-nums[i])->second : i);
				return ans;
			}
		}
		return ans;
    }
};

int main(){
	Solution t;
	vector<int> test;
	int target = 0;
	test.push_back(0); test.push_back(7);
	test.push_back(11); test.push_back(0);
	cout << t.twoSum(test, target)[0] << " " << t.twoSum(test, target)[1] << endl;

	system("pause");
}