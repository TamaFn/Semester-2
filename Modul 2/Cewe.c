#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct bstnode_t {
    int key,anak;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode-> anak = 0;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);
    if (value < root->key){
        root->left = __bst__insert(root->left, value);
    }else if (value > root->key){
        root->anak++;
        root->right = __bst__insert(root->right,value);
    }
    return root;
}

    int parent,ortu;
BSTNode* __bst__search(BSTNode *root, int value) {
    parent = 0;
    while (root != NULL) {
        if (value < root->key){
            ortu=root->key;
            parent += root-> anak+1;
            root = root->left;
        }
        else if(value > root->key){
            ortu = root->key;
            root = root->right;
        }
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

void __bst__inorder(BSTNode *root, int value, int index){
    if (root!=NULL) {
        __bst__inorder(root->left,value,index);
        index = 1;
        if(value <= root->key){
            index++;
        }else{
            printf("%d\n",index);
            index++;
        }
        index++;
        __bst__inorder(root->right,value,index);
    }
}

void _parent(BSTNode *root, int value) {
    if (root) {
        if(value<root->key&&root->left->key!=value)
            _parent(root->left, value);
        else if(value>root->key&&root->right->key!=value)
            _parent(root->right, value);
        else if (value == root->key)
        printf("ini anak siapa dah\n");
        else printf("%d\n", root->key);

    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

void bst_inorder(BST *bst, int value,int index) {
    __bst__inorder(bst->_root, value,index);
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_parentcheck(BST *bst, int value){
    _parent(bst->_root, value);
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return temp-> anak + parent + 1;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

int main()
{
    BST cewe;
    bst_init(&cewe);

    int perintah,value;
    char str[15];
    int jumlahindex = 0;


    scanf("%d", &perintah);

    for(int i=0;i<perintah;i++){

        scanf("%s", str);
        if(strcmp(str, "masukin") == 0){
            scanf("%d", &value);
            bst_insert(&cewe, value);
        }

        else if(strcmp(str, "anaksiapa") == 0){
            scanf("%d", &value);
            if(bst_find(&cewe, value)){
                bst_parentcheck(&cewe, value);
            }
            else{
                printf("ini anak siapa dah\n");
            }
        }
        else if(strcmp(str, "berapa") == 0){
        scanf("%d", &value);
        int hasil = bst_find(&cewe,value);
        if(hasil!=0){
            printf("%d\n", jumlahindex-hasil+1);
        }else{
            printf("-1\n");
            }
        }
    }
    return 0;
}