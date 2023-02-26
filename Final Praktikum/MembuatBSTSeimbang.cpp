#include<bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class TNode
{
    public:
    int data;
    TNode* left;
    TNode* right;
};

TNode* newNode(int data);

TNode* FungsiSortBST(int arr[],int mulai, int akhir)
{
    if (mulai > akhir)
    return NULL;
    int mid = (mulai + akhir)/2;
    TNode *root = newNode(arr[mid]);
    root->left = FungsiSortBST(arr, mulai,mid - 1);
    root->right = FungsiSortBST(arr, mid + 1, akhir);
    return root;
}

TNode* newNode(int data)
{
    TNode* node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printpreorder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printpreorder(node->left);
    printpreorder(node->right);
}

int main()
{
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    /* Convert List to BST */
    TNode *root = FungsiSortBST(arr, 0, n-1);
    printpreorder(root);

    return 0;
}