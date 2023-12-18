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

    bool isPalindrome(ListNode* head) {

        //---------------- Approach 1 -----------------------//
        // using stack
        //TC: O(2N)
        //SC: O(N) | stack

        stack<int> st;
        ListNode* temp = head;

        //inserting all the list elements in stack

        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        //comparing ll elements with stack.
        //if both same -> palidrome
        //if not -> not a palidrome

        temp = head;
        while(temp!=NULL){
            if(temp->val!=st.top()){
                return false;
            }
            temp = temp->next;
            st.pop();
        }
        return true;

        //----------------------- Approach 2 -------------------------//
        // Middle of LL -> Reverse Second Half -> Compare both the halves..
        // if (element)first half == (element)second half -> palidrome

        //Finding middle of ll | slow-fast
        //TC: O(2N)
        //SC: O(1)

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* newHead = reverseLL(slow->next);

        //comparing both the halves
        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=NULL){
            if(first->val != second->val){
                //returning back to the original config of LL
                    reverseLL(newHead);
                    return false;
                }
                first = first->next;
                second = second->next;
            }
            //returning back to the original config of LL
            reverseLL(newHead);
            return true;
        }

    
    ListNode* reverseLL(ListNode* head) {
        
        ListNode* nextPtr;
        ListNode* currPtr = head;
        ListNode* prevPtr = NULL;

        //base case..
        if(head == NULL || head->next == NULL){
            return head;
        }

        while(currPtr!=NULL){
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        return prevPtr;
    }

};
        
