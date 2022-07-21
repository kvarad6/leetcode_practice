/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
        //Recursive Approach..
        ListNode* result;
        
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        
        if(l1->val<=l2->val){
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            result = l2;
			result->next = mergeTwoLists(l1, l2 -> next);
		}
        return result;
    }
    
    /*
    //Iterative Approach...
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
    
        ListNode* list1 = l1;
        ListNode* list2 = l2;
    
        ListNode* dummyNode = new ListNode(-1);
        ListNode* list3 = dummyNode;
    
        while(list1!=NULL && list2!=NULL){
            
            if(list1->val<=list2->val){
                list3->next = list1;
                list1 = list1->next;
            }
            else{
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }
    
        //For remaining nodes..
    
        while(list1!=NULL){
            list3->next = list1;
            list1 = list1->next;
            list3 = list3->next;   
        }
    
        while(list2!=NULL){
            list3->next = list2;
            list2 = list2->next;
            list3 = list3->next;   
        }
        return dummyNode->next;
    }
    */
};
