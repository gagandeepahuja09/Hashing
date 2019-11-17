/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *raight;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_map<int, int> mp;
    void f(TreeNode* root, int i) {
        if(!root)
            return;
        mp[i]++;
        root -> val = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        f(root -> left, l);
        f(root -> right, r);
    }
    
    FindElements(TreeNode* root) {
        mp.clear();
        f(root, 0);
    }
    
    bool find(int target) {
        return (mp.find(target) != mp.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
