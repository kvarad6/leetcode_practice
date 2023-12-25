#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    bool flag = false;

    //ch-'a' give the corresponding ascii value
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

};

class Trie{
    private: Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string word){
            //creating a dummy variable pointing to the root
            Node* node = root;
            //insert every char..
            for(int i=0;i<word.size();i++){
                 //if node does not contain the char
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                //get the reference trie of the char
                node = node->get(word[i]);
            }
            //at last reference trie, at the end of the word, set flag as true.
            node->setEnd();
        }

        bool checkIfPrefixExists(string word){
            //as word exists
            bool flag = true;

            Node* node = root;

            for(int i=0;i<word.size();i++){
                //if node contains the char/ prefix
                if(node->containsKey(word[i])){
                    //go to the reference trie of the same
                    node = node->get(word[i]);
                    // if(node->isEnd() == false){
                    //     return false;
                    // }
                    flag = flag & node->isEnd();
                }
                else{
                    return false;
                }
            }
            return flag;
        }
};

string completeString(int n, vector<string> &a){
    //creating an object of the Trie class
    Trie* trie = new Trie();
    //insert words given in a into trie
    for(auto word: a){
        trie->insert(word);
    }

    string longest = "";

    for(auto word: a){
        if(trie->checkIfPrefixExists(word)){
            //if length of the current word/prefix is greater than longest prefix, then make current one the longest.
            if(word.size() > longest.size()){
                longest = word;
            }
            //else if both have same length and current one is lexicographically samller than the longer one, then make current one the longest.
            else if(word.size() == longest.size() && word<longest){
                longest = word;
            }
            else{
                return "None";
            }
        }
    }
    
    if(longest==""){
        return "None";
    }
    return longest;
}
