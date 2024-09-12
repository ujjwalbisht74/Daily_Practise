/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *,Node*>map;
    Node* cloneGraph(Node* node) {
        if(!node)  return nullptr;
        if(map.find(node) == map.end()){
            map[node] = new Node(node->val);
            for(auto t : node->neighbors){
                map[node]->neighbors.emplace_back(cloneGraph(t));
            }
        }
        return map[node];
    }
};