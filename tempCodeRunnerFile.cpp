
/* 
    Sandyatama Fransisna Nugraha (5025211196)
      --- Decision Tree - Final Project ---
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    char key[1001];
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(char *value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(char *value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void insertTree(){
        char text1[] = "Ingin mulai permainan? (yes/no)";
        char text2[] = "Ingin senjata jarak dekat? (yes/no/exit)";
        char text3[] = "Game Selesai";

        _root = __insert(_root, text1);
        _root->left = __insert(_root->left, text2);
        _root->right = __insert(_root->right, text3);

        char text4[] = "Ingin senjata dengan serangan cepat namun berdamage kecil? (yes/no/exit)";
        char text5[] = "Pilihan senjata anda ada 2 Jenis (Bow/Catalyst), Pilih salah satu dari kedua senjata tersebut : (Bow/Catalyst/exit)";

        _root->left->left = __insert(_root->left->left, text4);
        _root->left->right = __insert(_root->left->right, text5);

        char text6[] = "Pilihan senjata anda ada 2 Jenis (Sword/Spear), Pilih salah satu dari kedua senjata tersebut : (Sword/Spear/exit)";
        char text7[] = "Pilihan anda hanya senjata Claymore. Klik yes apabila ingin meneruskan";
        char text8[] = "Senjata anda adalah Bow (exit)";
        char text9[] = "Senjata anda adalah Catalyst (exit)";


        _root->left->left->left = __insert(_root->left->left->left, text6);
        _root->left->left->right = __insert(_root->left->left->right, text7);

        _root->left->right->left = __insert(_root->left->right->left, text8);
        _root->left->right->right = __insert(_root->left->right->right, text9);

        char text10[] = "Senjata anda adalah Sword. Klik exit untuk keluar (exit)";
        char text11[] = "Senjata anda adalah Spear. Klik exit untuk keluar(exit)";
        char text12[] = "Senjata anda adalah Claymore. Klik exit untuk keluar(exit)";

        _root->left->left->left->left = __insert(_root->left->left->left->left, text10);
        _root->left->left->left->right = __insert(_root->left->left->left->right, text11);
        _root->left->left->right->left = __insert( _root->left->left->right->left, text12);
    }

    void traversePreorder() {
        __preorder(_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(char *value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        //newNode->key = value;
        strcpy(newNode->key, value);
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __insert(BSTNode *root, char *value) {
        if (root == NULL)
            return __createNode(value);
        
        // if (value < root->key)
        //     root->left = __insert(root->left, value);
        // else if (value > root->key)
        //     root->right = __insert(root->right, value);
        return root;
    }

    BSTNode* __search(BSTNode *root, char *value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }


    void __preorder(BSTNode *root) {
        if (root) {
            printf("%s\n", root->key);

            char cmd[10];
            scanf("%s", cmd);

            if (strcmp(cmd, "yes") == 0)
            {
                __preorder(root->left);
            }else if(strcmp(cmd, "no") == 0){
                __preorder(root->right);
            }else if(strcmp(cmd, "Sword") == 0){
                __preorder(root->left);
            }else if(strcmp(cmd, "Spear") == 0){
                __preorder(root->right);
            }else if(strcmp(cmd, "Catalyst") == 0){
                __preorder(root->left);
            }else if(strcmp(cmd, "Bow") == 0){
                __preorder(root->right);
            }else if(strcmp(cmd, "exit") == 0){
                cout << "Selamat Bermain :)\n" << endl;
            }else{
                cout << "Program Berakhir" << endl;
            }
        }else{
            printf("Program sudah selesai, Terima Kasih\n");
        }
    }

};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();
    cout << "--- Selamat Datang Di Permainan Genshin Impact ---" << endl;
    set.insertTree();
    set.traversePreorder();

    return 0;
}