//PROVIDED BY: Jonathan Luzincourt
//Email: jnthnluzincourt40@gmail.com
//FUNCTION PROVIDED: Given a search tree and a set range, //function counts the amount of keys that fall in the leaves of //the tree.

int count_keys( tree_node_t *t, int a, int b){
    if(t == NULL){
        return 0;
    }//Base case if tree is empty
    if(t->left != NULL && t->right != NULL){
//Case when left and right subtrees are non empty
        if(t->key < a){//Case when key is less than the minimum 
            return(count_keys(t->right, a, b));
//Recursively calls right subtree
        }else if(t->key >= a && t->key <= b){
//When key falls between the given range it recursively calls //both left and right subtrees and uses addition to determine //the count
            return(count_keys(t->left, a, b) + count_keys(t->right, a, b));
        }else{//Case when key is larger than the maximum range
            return(count_keys(t->left, a, b));
//Recursively calls left subtree 
        }
    }else{
        if(t->key >= a && t->key <= b){
//When key falls in the range and its just a leaf in the tree
            return 1;
        }else{
            return 0;
        }
    }
}