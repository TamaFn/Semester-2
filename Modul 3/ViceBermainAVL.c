#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
 
typedef struct AVLNode_t{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;
 
typedef struct AVL_t{
    AVLNode *_root;
    unsigned int _size;
}AVL;
 
AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data) root = root->left;
        else if (value > root->data) root = root->right;
        else return root;
    }
    return root;
}
 
int _getHeight(AVLNode* node){
    if(node == NULL) return 0; 
    return node->height;
}
 
int _max(int a,int b){
    return (a > b)? a : b;
}
 
AVLNode* _rightRotate(AVLNode* pivotNode) {
 
    AVLNode* newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;
 
    pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right))+1;
    newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right))+1;
 
    return newParrent;
}
 
AVLNode* _leftRotate(AVLNode* pivotNode) {
 
    AVLNode* newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;
 
    pivotNode->height = _max(_getHeight(pivotNode->left),_getHeight(pivotNode->right))+1;
    newParrent->height = _max(_getHeight(newParrent->left),_getHeight(newParrent->right))+1;
 
    return newParrent;
}
 
AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}
 
AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}
 
AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}
 
AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}
 
int _getBalanceFactor(AVLNode* node){
    if(node == NULL) return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}
 
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
 
    if(node == NULL) return _avl_createNode(value);
    if(value < node->data) node->left = _insert_AVL(avl, node->left, value);
    else if(value > node->data) node->right = _insert_AVL(avl, node->right, value);
 
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
 
    int balanceFactor=_getBalanceFactor(node);
 
    if(balanceFactor > 1 && value < node->left->data) return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data) return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data) return _rightLeftCaseRotate(node);
 
    return node;
}
 
AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL) currNode = currNode->left;
    return currNode;
}
 
void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}
 
bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}
 
bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL) return false;
 
    if (temp->data == value) return true;
    else return false;
}
 
void avl_insert(AVL *avl, int value){
    if(!avl_find(avl, value)){
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}
 
int array[1069], idx=0;
void preorder(AVLNode *root){
    if (root){
        array[idx++] += root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
 
void panjat(AVLNode *_root, int value){
    int index;
    int panjatan[100];
    while(_root->data != value){
        panjatan[index] = _root->data;
        if (_root->data > value) _root = _root->left;
        else if (_root->data < value) _root = _root->right;
        index++;
    }
    printf("%d\n", value);
    for (int i=index-1; i>=index-2; i--){
        if(panjatan[i] != 0) printf("%d\n", panjatan[i]);
    }
}
 
int main(){
 
    AVL pohon;
    avl_init(&pohon);
 
    char perintah[20];
    int bil;
    scanf("%s", perintah);
 
    while(strcmp(perintah,"finish") != 0){
        if(strcmp(perintah,"add") == 0){
            scanf("%d", &bil);
            avl_insert(&pohon, bil);
        }
        if(strcmp(perintah, "more:") == 0){
            scanf("%s", perintah);
 
            if(strcmp(perintah, "requiem") == 0){
                scanf("%d", &bil);
                printf("requiem:\n");
                panjat(pohon._root, bil);
            }
            else if (strcmp(perintah, "finish") == 0){
                preorder(pohon._root);
                printf("list:\n");
                for (int i=0; i<=idx-1; i++){
                    printf("%d", array[i]);
                    if (i != idx-1) printf(":");
                }
                break;
            }
        }
        scanf("%s", perintah);
    }
}