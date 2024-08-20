
class Solution {
public:
right(right) {}
 * };
 */
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), 
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    int ans=0;
    void find(TreeNode* root,int maxSoFar) {
        if(root==nullptr)return;
        if(root->val>=maxSoFar){ans++;maxSoFar=root->val;}
        find(root->left,maxSoFar);
        find(root->right,maxSoFar);
    }
    int goodNodes(TreeNode* root) {
[3,1,4,3,null,1,5]
[3,3,null,4,2]
[1]
4
3
1
4
3
1
[
