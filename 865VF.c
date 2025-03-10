#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


int getDepth(struct TreeNode* root) {
    if (root == NULL) return 0; //caso base
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right); //percorre a árvore em pós-ordem
    if (leftDepth > rightDepth) {
        return 1 + leftDepth;
    } else {                            //retorna 1 + mais profundo
        return 1 + rightDepth;
    }
}


struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    
    if (root == NULL) return NULL; //caso base
    
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    
    if (leftDepth == rightDepth) return root; //se ambos tem a mesma profundidade, esse é o mais profundo

    
    if (leftDepth > rightDepth) {
        return subtreeWithAllDeepest(root->left);
    }
                                                                //continua a busca na mais profunda
    return subtreeWithAllDeepest(root->right);
}

int main() {
    // Teste da função com uma árvore de exemplo
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 4;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;
    
    root->left->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->left->val = 6;

    struct TreeNode* result = subtreeWithAllDeepest(root);
    printf("O nó mais profundo é: %d\n", result->val);

    return 0;
}
