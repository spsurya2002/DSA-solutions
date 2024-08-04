        }
        if(!isidentical(root->right, subRoot->right)){
            return false;
        }
        return true;
    }
    bool subtree(TreeNode* root, TreeNode* subRoot){
        if(root==NULL) return false;
        if(root->val==subRoot->val){
             if(isidentical(root,subRoot)){
        }
        return subtree(root->left,subRoot)||subtree(root->right,subRoot);
    }
             return true;
             }
[3,4,5,1,2]
[4,1,2]
[3,4,5,1,2,null,null,null,null,0]
[4,1,2]
[1,1]
[1]
true
false
true
true
false
true
[
