Node* merge(Node* a, Node* b){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    
    while( a!=NULL && b!=NULL){
        if( a->data < b-> data){
            temp -> bottom = a;
            temp = temp -> bottom;
            a = a -> bottom;
        }else{
            temp -> bottom = b;
            temp = temp->bottom;
            b = b -> bottom;
        }
    }
    if(a) temp -> bottom = a;
    else temp -> bottom = b;
    
    return dummy->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if( root == NULL || root->next ==NULL){
       return root;
   }
   
   root -> next = flatten(root->next);
   root = merge(root,root->next);
   
   return root;
}

TC - O(N)
SC - O(1)  
