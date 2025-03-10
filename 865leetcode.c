struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int father, lson, rson, maxdepth;
    
    if(TreeNode->left == NULL && TreeNode->Right == NULL){ 
        return TreeNode->val; //testando pra ver se é só a raíz.
    }

 while(TreeNode->left != NULL || TreeNode->right != NULL){
    if(TreeNode->left !== NULL){
        int depth = 0;
        depth++;
        father = TreeNode->val;
        lson = TreeNode->left;
        rson = TreeNode->right;

        if (depth > maxdepth){
            maxdepth = depth;
        }

        subtreeWithAllDeepest(TreeNode *left);
    }

    if(TreeNode->right !== NULL){
        int depth = 0;
        depth++;
        father = TreeNode->value;
        rson = TreeNode->right;
        lson = TreeNode->left;

        if (depth > maxdepth){
            maxdepth = depth;
        }
        subtreeWithAllDeepest(TreeNode *right);
    }
  }

  return (father, lson, rson);
}
