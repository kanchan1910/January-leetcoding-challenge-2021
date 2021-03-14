/*
Let's traverse both trees in parallel, and once the target node is identified in the first tree, return the corresponding node from the second tree.
*/
//bfs traversal
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
     if(original==NULL||cloned==NULL){
         
         return NULL;
         
     }
        
     queue<TreeNode*>qo;
        
     queue<TreeNode*>qc;
        
     qo.push(original);
        
     qc.push(cloned);
        
     while(!qo.empty()&&!qc.empty()){
         
        TreeNode* fronto=qo.front();
         
        qo.pop();
         
        TreeNode* frontc=qc.front();
         
        qc.pop();
         
        if(fronto==target){
            
            return frontc;
            
        }
         
        if(fronto->left!=NULL){
            
            qo.push(fronto->left);
            
            qc.push(frontc->left);
            
        }
         
        if(fronto->right!=NULL){
            
            qo.push(fronto->right);
            
            qc.push(frontc->right);
            
        }
     }
        
        return NULL;
    }
};

/*
Let's traverse both trees in parallel, and once the target node is identified in the first tree, return the corresponding node from the second tree.
*/
//inorder traversal
class Solution {
public:
    TreeNode* ans;
    
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target){
        
        if(original==NULL||cloned==NULL){
         
         return;
         
        }
        
        inorder(original->left,cloned->left,target);
        
        if(original==target){
            
            ans = cloned;
            
        }
        
        inorder(original->right,cloned->right,target);

    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
     if(original==NULL||cloned==NULL){
         
         return NULL;
         
     }
     
    inorder(original,cloned,target);
        
    return ans;
        
    }
};

/*
Let's traverse both trees in parallel, and once the target node is identified in the first tree, return the corresponding node from the second tree.
*/
//bfs traversal
class Solution {
public:
    TreeNode* ans;
    
    void preorder(TreeNode* original, TreeNode* cloned, TreeNode* target){
        
        if(original==NULL||cloned==NULL){
         
         return;
         
        }
        
        
        if(original==target){
            
            ans = cloned;
            
        }
        
         preorder(original->left,cloned->left,target);
        
         preorder(original->right,cloned->right,target);

    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
     if(original==NULL||cloned==NULL){
         
         return NULL;
         
     }
     
    preorder(original,cloned,target);
        
    return ans;
        
    }
};

/*
Let's traverse both trees in parallel, and once the target node is identified in the first tree, return the corresponding node from the second tree.
*/
//bfs traversal
class Solution {
public:
    TreeNode* ans;
    
    void postorder(TreeNode* original, TreeNode* cloned, TreeNode* target){
        
        if(original==NULL||cloned==NULL){
         
         return;
         
        }
        
         postorder(original->left,cloned->left,target);
        
         postorder(original->right,cloned->right,target);
        
           if(original==target){
            
            ans = cloned;
            
        }

    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
     if(original==NULL||cloned==NULL){
         
         return NULL;
         
     }
     
    postorder(original,cloned,target);
        
    return ans;
        
    }
};


class Solution {
public:

         
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
     if(original==NULL||cloned==NULL){
         
         return NULL;
         
     }
     
        if(original==target){
            
            return cloned;
        }
        
        if(getTargetCopy(original->left,cloned->left,target)!=NULL){
            
            return getTargetCopy(original->left,cloned->left,target);
        }
        else{
            
            return getTargetCopy(original->right,cloned->right,target);
        }
    }
};
