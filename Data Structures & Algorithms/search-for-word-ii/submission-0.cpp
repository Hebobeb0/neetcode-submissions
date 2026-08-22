class Node{
public:
    unordered_map<char, Node*> children;
    int index = -1;
    
    bool check(char c){
        return children.find(c) != children.end();
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node;
    }
    void addWord(string s, int index){
        Node* node = root;
        for(char c: s){
            if(node->children.find(c) == node->children.end()){
                node->children[c] = new Node;
            }
            node = node->children[c];
        }
        node->index = index;
    }

};


class Solution {
public:
int m,n;
vector<string> res;

    void dfs(int x, int y, Node* node, vector<vector<bool>>& traversed, vector<vector<char>>& board, vector<string>&words ){
        if(node->index>=0) {res.push_back(words[node->index]); node->index = -1;}
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [a,b]:dir){
            int nx = x+a, ny = y+b;
            if(nx<m && nx>=0 && ny<n && ny>=0 && !traversed[nx][ny] && node->check(board[nx][ny])){
                traversed[nx][ny] = true;
                dfs(nx,ny,node->children[board[nx][ny]], traversed, board, words);
                traversed[nx][ny] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();n = board[0].size();
        Trie myTrie;
        for(int i =0;i<words.size();++i){
            string s = words[i];
            myTrie.addWord(s,i);
        }
        vector<vector<bool>> traversed(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j = 0;j<n;++j){
                char c = board[i][j];
                if(myTrie.root->check(c)){
                    traversed[i][j] = true;
                    dfs(i,j,myTrie.root->children[c],traversed, board, words);
                    traversed[i][j]=false;
                }
            }
        }
        return res;

    }
};
