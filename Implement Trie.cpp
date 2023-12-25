/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node { 
    Node* links[26];
    bool flag = false;

    //to check if char is present in trie or not
    bool containsKey(char ch){
        return (links[ch - 'a']!=NULL);
    }

    //to insert the char at node
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    //to access the trie node
    Node* get(char ch){
        return links[ch - 'a'];
    }

    bool setEnd(){
        return flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private: Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    //TC: O(N)
    void insert(string word) {
        //creating a dummy variable pointing to the root
        Node* node = root;

        //insert every char..
        for(int i=0;i<word.size();i++){
            //if node does not contain the char
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            //move to the reference trie of the char
            node = node->get(word[i]);
        }

        //at last reference trie, at the end of the word, set flag as true.
        node->setEnd();

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        //starts with the root node..
        Node* node = root;
        for(int i=0;i<word.size();i++){
            //check if it contains char (word[i]), if not -> return false
            if(!node->containsKey(word[i])){
                return false;
            }
            //if word contains char, return.
            node = node->get(word[i]);
        }
        //to check if you have found the entire word,
        //flag = true -> end reference trie of word
        //flag = false -> not the end reference trie of that word.
        return node->isEnd();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //starts with the root node..
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            //check if it contains char (word[i]), if not -> return false
            if(!node->containsKey(prefix[i])){
                return false;
            }
            //if word contains char, return.
            node = node->get(prefix[i]);
        }
        //no need to check for end as we just need to check the prefix
        return true;
    }
};
