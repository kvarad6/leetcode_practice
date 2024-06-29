/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        //--------- Approach 1 ------------------//

        // Using Fast-Slow pointer | Two pointer | Floyd's Cycle-Finding Algorithm

        if(head==NULL || head->next==NULL){
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                return true;
            }
        }
        return false;

        //------------------ Approach 2 ----------------------//

        // Using hashmap..

         //Initially map is empty, so all the nodes are having count as 0.
        //As we visit nodes, mark them as 1
        //check if any node is already marked (>0) 
        //true -> cycle
        //false-> no cycle

        //Slower than fast-slow alg..
        
        if(head==NULL){
            return false;
        }
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;

        while(temp!=NULL){
            if(mpp.count(temp)>0){
                return true;
            }
            else{
                mpp[temp]=1;
            }
            temp = temp->next;
        }
        return false;

    }
};


//------------- Approach 3 -------------//
//using unordered_set

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;

        ListNode* temp = head;
        while(temp!=NULL){
            if(st.find(temp)!=st.end()){
                return true;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
