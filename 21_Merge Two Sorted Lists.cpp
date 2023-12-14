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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        //------------------ Approach 1 | Iterative Solution --------//

        //base cases..
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        //temp variables pointing to current LLs..
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        //creating a new node and assigning it to new LL..

        ListNode* dummyNode = new ListNode(-1);
        ListNode* list3 = dummyNode;

        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                list3->next = l1;
                l1 = l1->next;
            }
            else{
                list3->next = l2;
                l2 = l2->next;
            }
            list3 = list3->next;
        }

        //Fill out the remaining nodes in new LL..

        while(l1!=NULL){
            list3->next = l1;
            list3 = list3->next;
            l1 = l1->next;
        }

        while(l2!=NULL){
            list3->next = l2;
            list3 = list3->next;
            l2 = l2->next;
        }
        
    return dummyNode->next;


    //------------------- Approach 2 | Recursive Solution ----------------//

    //base cases..
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }

    ListNode* result;

    if(list1->val <= list2->val){
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else{
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }
    return result;
    }
};
