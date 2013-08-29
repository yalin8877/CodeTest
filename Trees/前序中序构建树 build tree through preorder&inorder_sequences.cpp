#include<iostream>
#include<string.h>
//#include<stddef.h>
using namespace std;

struct Node
{
    char key;
    Node* left;
    Node* right;
};

char* find(char* arr,int n,char c)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==c)
            return arr+i;
    }
    return NULL;
}

void BuildTree(char* preOrder,char* inOrder,int n,Node*& root)
{
    if(n==0)
    {
        root=NULL;
        return;
    }
    root=new Node();
    root->key=preOrder[0];
    char* inPos=find(inOrder,n,root->key);
    if(!inPos)
    {
        cout<<"Error Input Arrays!"<<endl;
    }
    else
    {
        int nleft=inPos-inOrder;
        int nright=n-nleft-1;
        BuildTree(preOrder+1,inOrder,nleft,root->left);
        BuildTree(preOrder+nleft+1,inPos+1,nright,root->right);
    }
}

void PreTraverse(Node* root)
{
    if(!root)
        return;
    cout<<root->key<<" ";
    PreTraverse(root->left);
    PreTraverse(root->right);
}

void InTraverse(Node* root)
{
    if(!root)
        return;
    InTraverse(root->left);
    cout<<root->key<<" ";
    InTraverse(root->right);
}

int main()
{
    Node* root=NULL;
    char* s1="abdcef";
    char* s2="dbaecf";
    BuildTree(s1,s2,strlen(s1),root);
    PreTraverse(root);
    cout<<endl;
    InTraverse(root);

}
