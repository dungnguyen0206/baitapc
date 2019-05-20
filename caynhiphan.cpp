#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} node_t;
 
 
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 
int LeftOf( const int value, const node_t* root )
{
    return value < root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
 
bool Search( const node_t* root, int value )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}
 
int LeftMostValue( const node_t* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}
 
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        if ( root->left == NULL )
        {
            node_t* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node_t* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
}
 
void NLR(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        NLR(root->left);
        NLR(root->right);
    }
}
 
void LNR(node_t* root){
    if(root != NULL)
    {
        LNR(root->left);
        printf("%d ", root->data);
        LNR(root->right);
    }
}
 
void LRN(node_t* root){
    if(root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        printf("%d ", root->data);
    }
}
 
 
int main()
{
    node_t* root = NULL;

    root = Insert( root, 18 );
    root = Insert( root, 31 );
    root = Insert( root, 15 );
    root = Insert( root, 2 );
    root = Insert( root, 20 );
    root = Insert( root, 12 );
    root = Insert( root, 30 );
    root = Insert( root, 9 );
    root = Insert( root, 8 );
    root = Insert( root, 4 );
    printf("\nDuyet theo thu thu truoc : ");
    NLR(root);
    printf("\nDuyet theo thu thu giua  : ");
    LNR(root);
    printf("\nDuyet theo thu thu sau  :");
    LRN(root);
 
    printf("\n==Xoa phan tu 30 khoi cay==\n");
    Delete(root, 30);
    printf("\nDuyet theo thu thu truoc : ");
    NLR(root);
    printf("\nDuyet theo thu thu giua  : ");
    LNR(root);
    printf("\nDuyet theo thu thu sau  :");
    LRN(root);
    
        printf("\n==Xoa nut goc==\n");
    Delete(root, 18);
    printf("\nDuyet theo thu thu truoc : ");
    NLR(root);
    printf("\nDuyet theo thu thu giua  : ");
    LNR(root);
    printf("\nDuyet theo thu thu sau  :");
    LRN(root);
 
 
 
 
    Free( root );
    root = NULL;
    return 0;
}
