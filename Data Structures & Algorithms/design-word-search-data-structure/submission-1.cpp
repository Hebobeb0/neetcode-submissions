class Node {
public:
    unordered_map<char, Node*> children;
    bool isWord = false;
};

class WordDictionary {
    Node * root;
public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node * cur = root;
        for (char c : word){
            if(cur->children.find(c) == cur->children.end()) cur->children[c]=new Node;
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    bool search(string word){
        return searchH(word,root);
    }
    bool searchH(string word, Node * cur) {
        int n = word.length();
        for(int i =0;i<n;++i){
            char c = word[i];
            if (c == '.'){
                bool res=false;
                if(cur->children.empty()) return false;
                else{
                    for(auto& a:cur->children){
                        res = res||searchH(word.substr(i+1), a.second);
                        if (res) return true;
                    }
                }
                return res; 
            }
            else{
                if(cur->children.find(c) == cur->children.end()){
                    return false;
                }
                cur = cur->children[c];
            }
        }
        return cur->isWord;
    }
};