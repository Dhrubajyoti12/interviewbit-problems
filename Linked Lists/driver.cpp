/*
	Used to test my solutions.
*/
#include <iostream>
#include <vector>
#include <initializer_list>
#include <climits>

// Structs must be defined before the solution file is included.
// Otherwise driver.cpp won't compile as there are no struct
// definitions in solution files.
// ----------------- Struct Definitions -----------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
// include the solution file.
#include "swap-list-nodes-in-pairs.cpp"


// ---------------- Vector Functions ----------------
template<typename T> 
void print_vector(vector<T> &data){
	for(auto d : data) 	cout<<d<<" ";
	cout<<endl;
}

// ---------------- LinkedList Functions ----------------
ListNode* build_linked_list(std::initializer_list<int> list){
	ListNode* root = new ListNode(-1270);
	ListNode* iter = root;
	for(int value : list){
		iter->next = new ListNode(value);
		iter = iter->next;
	}
	return root->next;
}

void print_linked_list(ListNode* head){
	cout<<"Printing list\n\t";
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}


int main(void){
	Solution solution;
	// Build input
	ListNode* head_1 = build_linked_list({1, 2, 3, 4, 5 ,6});
	ListNode* head_2 = build_linked_list({1, 2, 3, 4, 5});
	ListNode* head_3 = build_linked_list({1});
	ListNode* head_4 = build_linked_list({});
	// test
	ListNode* test_result_1 = solution.swapPairs(head_1);
	ListNode* test_result_2 = solution.swapPairs(head_2);
	ListNode* test_result_3 = solution.swapPairs(head_3);
	ListNode* test_result_4 = solution.swapPairs(head_4);
	// Print output
	print_linked_list(test_result_1);
	print_linked_list(test_result_2);
	print_linked_list(test_result_3);
	print_linked_list(test_result_4);
	return 0;
}
