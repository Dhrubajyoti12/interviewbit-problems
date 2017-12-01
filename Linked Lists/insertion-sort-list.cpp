/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int getSize(ListNode* head){
    int res=0;
    while(head!=NULL){
        ++res;
        head = head->next;
    }
    return res;
}
 
ListNode* insert(ListNode* head, ListNode* prev){
    ListNode* cur = head;
//  -1270 --> 2 --> 4 -> 3 -> 9 -> 60 -> 70 ]

    while(cur->next->val < prev->next->val)     cur = cur->next;
    if(cur == prev)   return head;
    
    ListNode* ins = prev->next;
    prev->next = prev->next->next;
    
    
    ins->next = cur->next;
    cur->next = ins;
    return head;
}

//1 2 3 4 5
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* head = new ListNode(-1270);
    head->next = A;
    
    ListNode *cur=A, *next;
    int size = getSize(A);
     for(int i=1 ; i<size ; ++i){
        next = cur->next;
        head = insert(head, cur);
        if(cur->val < next->val) cur = next;
    }
    return head->next;
}
