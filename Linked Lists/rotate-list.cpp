/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int sizeOf(ListNode *head){
    int res=0;
    ListNode *cur = head;
    while(cur!=NULL){
        res++;
        cur = cur->next;
    }
    return res;
}
 
ListNode* Solution::rotateRight(ListNode* head, int B) {
    int len = sizeOf(head);
    B = B%len;
    int shft = len - B;
    if(shft == len)     return head;
    ListNode* cur =head, *yenibas, *toLast;
    for(int i=1 ; i<shft ; ++i)     cur = cur->next;
    yenibas = cur->next; // o elemandan sonuna kadar aldik
    cur->next=NULL;// seyi kestik.
    
    toLast = yenibas;
    while(toLast->next != NULL)  toLast = toLast->next;
    toLast->next = head;
    
    return yenibas;
    
}