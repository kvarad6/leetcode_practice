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
//----------- Appraoch 1 -----------//
//Using in-built __gcd function
//TC: O(n*log(m)) | n-> linkedlist size, m-> max value among all the elements in the linkedlist
//SC: O(1)
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //base cases
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* curr = head;
        while(curr->next!=NULL){
            ListNode* GCD = new ListNode(__gcd(curr->val, curr->next->val));
            GCD->next = curr->next;
            curr->next = GCD;
            curr = GCD->next;
        }
        return head;
    }
};

//----------Appraoch 2 -------------//
//Calculating gcd manually
//TC: O(n*m) | n-> linkedlist size, m-> min of two values
//SC: O(1)
class Solution {
public:
    int findGCD(int num1, int num2){
        int result = min(num1, num2);
        while(result>0){
            if(num1%result==0 && num2%result==0){
                break;
            }
            result--;
        } 
        return result;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //base cases
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* curr = head;
        while(curr->next!=NULL){
            int gcdValue = findGCD(curr->val, curr->next->val);
            ListNode* GCD = new ListNode(gcdValue);
            GCD->next = curr->next;
            curr->next = GCD;
            curr = GCD->next;
        }
        return head;
    }
};
