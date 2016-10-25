#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;
		int last_time = 0;
		int this_time = 0;
		vector<int> temp;
		vector<int> canshu;
		bool flag = nums1.size()>nums2.size()? 1:0;
		if(flag){
			temp = nums1;
			canshu = nums2;
		}
		else{
			temp = nums2;
			canshu = nums1;
		}

		for(int i=0;i<canshu.size();i++){
			this_time = findplace(temp, last_time, canshu[i]);
			temp.insert(temp.begin()+this_time, canshu[i]);
			last_time = this_time;
		}
		if((nums1.size() + nums2.size())%2 == 0)
			median = ( 1.0* temp[(nums1.size() + nums2.size())/2] + 1.0* temp[(nums1.size() + nums2.size() - 1)/2] )/2;
		else
			median = temp[(nums1.size() + nums2.size())/2];
		return median;
    }

	int findplace(vector<int>& temp, int last_time, int n){
		int ans;
		int begin = last_time;
		int end = temp.size();
		while(end-begin>1){
			if(n>temp[(begin+end)/2])
				begin = (int)(begin + end)/2;
			else
				end = (int)(begin + end)/2;
		}
		if(begin == end)
			ans = n>temp[end]? end + 1: begin;
		else{
			if (n<temp[begin])
				ans = begin;
			else if (n>temp[end<temp.size()-1? end:temp.size()-1])
				ans = end<temp.size()-1? end+1:temp.size();
			else
				ans = end<temp.size()-1? end:temp.size()-1;
		}
		return ans;
	}
};

int main(){
	Solution t;
	int a[] = {1,2};
	int b[] = {1,1};
	vector<int> tempa;
	vector<int> tempb;
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		tempa.push_back(a[i]);
	}
	for(int i=0;i<sizeof(b)/sizeof(int);i++){
		tempb.push_back(b[i]);
	}
	double ans = t.findMedianSortedArrays(tempa,tempb);

	cout<<ans<<endl;

	system("pause");

	return 0;
}