#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *parent,*right,*left;
};
node* root;
void createBinaryTree()
{
    root = NULL;
}
node *createNode(int data)
{
    node* newNode= new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}
void preOrder(node *node)
{
    if(node==NULL) return ;
    cout<<node->data<<endl;
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder(node *node)
{
    if(node==NULL) return ;

    inOrder(node->left);
    cout<<node->data<<endl;
    inOrder(node->right);
}
void postOrder(node *node)
{
    if(node==NULL) return ;

    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<endl;
}
void insertNode(node* parentNode,node *newNode)
{
        if(parentNode->data < newNode->data)
        {
            if(parentNode->right==NULL)
            {
                parentNode->right = newNode;
                newNode->parent = parentNode;
            }
            else
                insertNode(parentNode->right,newNode);
        }

        else
        {

            if(parentNode->left==NULL)
            {
                parentNode->left = newNode;
                newNode->parent = parentNode;
            }
            else
                insertNode(parentNode->left,newNode);

        }

}
void insertRoot(node *myRoot)
{
    root = myRoot;
}

node* searchBTreeRecur(node* parentNode,int data)
{
    if(parentNode->data == data)
        return parentNode;
    else
    {
        if(parentNode->data < data)
        {
            if(parentNode->right==NULL)
                return NULL;
            parentNode = parentNode->right;
            searchBTreeRecur(parentNode,data);
        }
        else
        {
            if(parentNode->left==NULL)
                return NULL;
            parentNode = parentNode->left;
            searchBTreeRecur(parentNode,data);
        }
    }
}

node* searchBTree(int data)
{
    int c=0;
    for(node* tempNode=root;;)
    {
        if(tempNode->data < data)
        {
            if(tempNode->right!=NULL)
                tempNode= tempNode->right;
            else
                break;
        }
        else if(tempNode->data > data)
        {
            if(tempNode->left!=NULL)
                tempNode= tempNode->left;
            else
                break;
        }
        else if(tempNode->data == data)
        {
           // cout<<c<<endl;
            return tempNode;
        }
        c++;

    }
    return NULL;

}
void swapData(node *a,node *b)
{
    int data1 = a->data;
    int data2 = b->data;
    int temp =data1;
    data1 = data2;
    data2 =temp;
    a->data = data1;
    b->data = data2;
}
void deleteNode(int data)
{
    node* NodeToDelete;
    NodeToDelete = searchBTree(data);
    if(NodeToDelete->left == NULL && NodeToDelete->right == NULL)
    {

        if(NodeToDelete->parent->left == NodeToDelete)
            NodeToDelete->parent->left =NULL;
        else
            NodeToDelete->parent->right = NULL;

    }
    else if(NodeToDelete->left == NULL || NodeToDelete->right == NULL)
    {
        if(NodeToDelete->left == NULL)
        {
            NodeToDelete->data = NodeToDelete->right->data;
            NodeToDelete->right = NULL;
            NodeToDelete=NodeToDelete->right;
        }
        else
        {

            NodeToDelete->data = NodeToDelete->left->data;
            NodeToDelete->left = NULL;
            NodeToDelete=NodeToDelete->left;
        }
    }
    else
    {
        node *temp = NodeToDelete->right;
        while(temp->left != NULL )
            temp=temp->left;


        if(temp == NodeToDelete->right)
            temp->parent->right= NULL;

        temp->parent->left= NULL;
        NodeToDelete->data = temp->data;
        NodeToDelete =temp;

    }
    delete NodeToDelete;
    //NodeToDelete = searchBTree(data);

}
int main()
{
    createBinaryTree();
    int data;
    /*int sizeOfTree;
    cout<<"Enter Size of your Binary Search Tree :";
    cin>>sizeOfTree;
    cout<<"Insert the elements :";*/
    //int arr[] = {15 , 10, 16,12,11,14,17,9,13};
    int arr[] = {50,40,60,30,45,55,70,20,35,43,47,52,57,65,80};
    for(int i=0;i<15;i++)
    {
//        cin>>data;
        data = arr[i];
        if(root==NULL)
        {
            insertRoot(createNode(data));
        }
        else
        {
            insertNode(root,createNode(data));
        }
    }
    cout<<endl<<"PreOrder:"<<endl;
    preOrder(root);

    cout<<"\nPostOrder:"<<endl;
    postOrder(root);

    cout<<"\nInOrder:"<<endl;
    inOrder(root);

//    cout<<"Depth is :";
//    searchBTree(data);
    int c=4;
    while(c!=1){
    cout<<"Enter the data to be deleted :";
    cin>>data;
    deleteNode(data);
    cout<<"\nInOrder:"<<endl;
    inOrder(root);
    cout<<"\n press 1 to exit:";
    cin>>c;
    }
    return 0;
}

