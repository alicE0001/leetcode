#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
		for(int i=0;i<nums.size();i++){
			for(int j=i+1;j<nums.size();j++){
				if (target - nums[i] == nums[j]){
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
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