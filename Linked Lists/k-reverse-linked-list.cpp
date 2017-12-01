/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
inline ListNode* rvrsK(ListNode* head, const int K){
    ListNode *sol, *sag, *tsg;
    sol = head;
    sag = head->next;
    sol->next = NULL;
    for(int i=0 ; i<K-1 ; ++i){
        tsg = sag->next;
        sag->next = sol;
        sol = sag;
        sag = tsg;
    }
    
    return sol;
}
//1 <-- 2 <-- 3 <-- 4 <-- 5 NULL
// void write(ListNode *head){
//     while(head!=NULL){
//         cout<<head->val<<" ";
//         head = head->next;
//     }
//     cout<<endl;
// }
ListNode* cvr(ListNode* head, const int k){
    ListNode *tsg=head, *cur;
    
    for(int i=0 ; i<k ; ++i)    tsg = tsg->next;
    ListNode *res=rvrsK(head, k);
    
    if(tsg == NULL)    return res;
 
    cur = res;
    for(int i=1 ; i<k ; ++i)    cur = cur->next;
    cur->next = cvr(tsg,k);
    return res;
}

ListNode* Solution::reverseList(ListNode* head, const int k){
    return cvr(head, k);
}
