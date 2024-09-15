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

/*
    The odd indices means the first, third, 5th, 7th..in the list.
    It is not related to what number it is.

    For example:
    input: 2 4 2 4 2 4 2
    expected: 2 2 2 2 4 4 4
*/
//--------- Approach 1 ---------//
// replace the data of the nodes | to make it odd-even linkedlist
// can use list to store the data in the format mentioned | odd-even
// just update the linkedlist node values as per the list
//TC: O(2N) | N/2+N/2+N
//SC: O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        if(head==NULL){
            return head;
        }
        //inserting odd ones
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp!=NULL){
            arr.push_back(temp->val);
        }
        //inserting the even ones
        temp = head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp){
            arr.push_back(temp->val);
        }
        //update the existing values of ll as per the arr
        int i=0;
        temp = head;
        while(temp!=NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};


//--------- Approach 2 ---------//
// constant space
//Step1: changing the links for odd index nodes
//Step2: changing the links for even index nodes
//TC: O(N/2)*2 ~ O(N) | While loop is running for N/2 times
//SC: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even!=NULL && even->next!=NULL){
            //establish the connections
            odd->next = odd->next->next;
            even->next = even->next->next;

            //move forward
            odd = odd->next;
            even = even->next;
       }
       odd->next = evenHead;
       return head;
    }
};
