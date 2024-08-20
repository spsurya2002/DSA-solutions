    void find(TreeNode* root, int k){
        if(root==nullptr)return;
        find(root->left,k);
        i++;
        if(i==k)ans = root->val;
    int ans=-1,i=0;
        find(root->right,k);
    }
[3,1,4,null,2]
1
[5,3,6,2,4,null,null,1]
3
1
3
1
3
[
