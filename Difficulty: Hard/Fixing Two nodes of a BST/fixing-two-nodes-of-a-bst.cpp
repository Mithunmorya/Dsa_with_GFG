/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void correctBST(Node* root) {
        
        Node* curr = NULL;
        Node* first = NULL;
        Node* second = NULL;
        Node* last = NULL;
        Node* present =NULL;
        while(root){
            if(!root->left){
                last = present;
                present = root;
                if(last && last->data>present->data){
                    if(!first){
                        first = last;
                        second = present;
                    }
                    else{
                        second = root;
                    }
                }
                last = root;
                root = root->right;
            }
            else{
                curr = root->left;
                
                while(curr->right && curr->right != root)
                curr = curr->right;
                
                if(!curr->right){
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if(last && last->data>present->data){
                        if(!first){
                            first = last;
                            second = present;
                        }
                        else{
                            second = root;
                        }
                    }
                    last = root;
                    root = root->right;
                }
            }
        }
        int num = first->data;
        first->data = second->data;
        second->data = num;
  
        
    }
};