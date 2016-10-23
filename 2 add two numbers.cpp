#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a = 0;
		if(l1 == NULL)
			return l2;

		else if(l2 == NULL)
			return l1;

		else{
			ListNode* head = new ListNode((l1->val + l2->val)%10);
			a = (l1->val + l2->val)/10;
			ListNode* temp = head;
			l1 = l1->next;
			l2 = l2->next;
			while(l1!=NULL && l2!=NULL){
				ListNode* list = new ListNode((l1->val + l2->val + a)%10);
				a = (l1->val + l2->val + a)/10;
				temp->next = list;
				temp = list;
				l1 = l1->next;
				l2 = l2->next;
			}
			if(l1 == NULL){
				while(l2!=NULL){
					ListNode* list1 = new ListNode((l2->val + a)%10);
					a = (l2->val + a)/10;
					temp->next = list1;
					temp = list1;
					l2 = l2->next;
				}
			}
			else{
				while(l1!=NULL){
					ListNode* list2 = new ListNode((l1->val + a)%10);
					a = (l1->val + a)/10;
					temp->next = list2;
					temp = list2;
					l1 = l1->next;
				}
			}
			if(a!=0){
				temp->next = new ListNode(a);
			}
			return head;
		}

    }
};

int main(){
	int nums1[] = {9,9,9,9,9,9};
	int nums2[] = {8};
	ListNode* l1 = new ListNode(nums1[0]);
	ListNode* l2 = new ListNode(nums2[0]);
	ListNode* temp1 = l1;
	ListNode* temp2 = l2;
	for (int i=1;i<sizeof(nums1)/sizeof(int);i++){
		ListNode* list3 = new ListNode(nums1[i]);
		temp1->next = list3;
		temp1 = list3;
	}
	for (int i=1;i<sizeof(nums2)/sizeof(int);i++){
		ListNode* list4 = new ListNode(nums2[i]);
		temp2->next = list4;
		temp2 = list4;
	}

	temp1 = l1;
	temp2 = l2;
	cout<<"l1: "<<temp1->val;
	temp1 = temp1->next;
	while(temp1 !=NULL){
		cout<<" "<<temp1->val;
		temp1 = temp1->next;
	}
	cout<<endl<<"l2: "<<temp2->val;
	temp2 = temp2->next;
	while(temp2!=NULL){
		cout<<" "<<temp2->val;
		temp2 = temp2->next;
	}

	Solution t;
	ListNode* result = t.addTwoNumbers(l1,l2);
	cout <<endl<<"result: "<< result->val;
	result = result->next;
	while(result!=NULL){
		cout<<" "<<result->val;
		result = result->next;
	}
	system("pause");
	return 0;
}