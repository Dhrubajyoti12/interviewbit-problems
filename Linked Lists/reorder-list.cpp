/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
using ld = ListNode;
// ListNode* rvrs(ListNode* head){
//     if(head==NULL or head->next==NULL or head->next->next==NULL) 
//         return head;
    
//     ListNode *last, *dummy=head, *next=head->next;
//     while(dummy->next->next)     dummy=dummy->next;
//     last = dummy->next;     dummy->next=NULL;
    
//     head->next = last;
//     last->next = rvrs(next);
//     return head;    
    
// }

ld* rvrsK(ListNode* head, const int K){
    ld *sol, *sag, *tsg;
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

void write(ld* head){
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}


ListNode* Solution::reorderList(ListNode* head) {
    // bossa veya 1 elemenaliysa, sarmiyo.
    if(head==NULL or head->next==NULL)  return head;
    ld* left=head, *rite, *res, *dummy;
    
    // get size;
    int size=0, cevir_boyu, itere;
    while(left){
        left = left->next;
        ++size;
    }
    // set second ptr to second half.
    left=head, rite=head;
    cevir_boyu = (size+1)/2;
    itere = size - cevir_boyu;
    
    for(int i=1 ; i<itere ; ++i)   rite=rite->next;
    dummy = rite;   rite=rite->next;
    dummy ->next = NULL;//disconnect 2 halves.
    
    //printf("itere:%d boy:%d rite:%d\n",itere, cevir_boyu, rite->val );
    
    //reverse second half and start building up the result;
    rite = rvrsK(rite, cevir_boyu);
    
    
    //write(left);
    //write(rite);
    
    res  = new ld(-1270);
    dummy = res;
    while(left and rite){
        //soldan al solu kurtar.
        dummy->next=left;   left = left->next;
        dummy = dummy->next;
        //sagdan al sagi kurtar.
        dummy->next=rite;   rite = rite->next;
        dummy = dummy->next;
    }//1 2 3 4 5 6 7 8 
    if(rite)    dummy->next=rite;
    return res->next;   
}