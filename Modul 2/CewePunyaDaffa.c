#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t {
    int key;
    int index;
    struct bstnode_t \
    *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;


BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->index = 0;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
    {
      root->left = __bst__insert(root->left, value);
    }
    else if (value > root->key)
    {
      root->right = __bst__insert(root->right, value);
         root->index++;
    }

    return root;
}

int indexnomor,indexawal;

BSTNode* __bst__search(BSTNode *root, int value) {

  indexnomor = 0;
  while (root != NULL) {
        if (value < root->key)
        {
          indexawal =root->key;
          indexnomor += root->index + 1;
          root = root->left;
    }
        else if (value > root->key)
        {
          indexawal=root->key;
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

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

int bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return 0;

    if (temp->key == value)
    {
      return temp->index + indexnomor + 1;
  }
    else
        return 0;
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

    int perintah,a,b,c;
    char str[15];
    scanf("%d", &perintah);

    int data=0;
    for(int i=0; i<perintah; i++)
    {
        scanf("%s", str);

        if(strcmp(str,"masukin")==0)
        {
            data++;
            scanf("%d", &a);
            bst_insert(&cewe, a);
        }
        else if (strcmp(str, "berapa")==0)
        {
            scanf("%d", &b);
            int hasil = bst_find(&cewe, b);

            if(hasil != 0)
            {
              printf("%d\n",data-hasil+1);
            }
            else
            {
              printf("-1\n");
            }
        }
        else if(strcmp(str, "anaksiapa")==0)
        {
            scanf("%d", &c);
            indexawal=-1;
            int cek = bst_find(&cewe, c);

            if(cek != 0 && indexawal != -1)
            {
              printf("%d\n", indexawal);
            }
            else
            {
                printf("ini anak siapa dah\n");
            }
        }
    }

    return 0;
}