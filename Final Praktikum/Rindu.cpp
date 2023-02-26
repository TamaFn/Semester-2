#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}  

int max(int a, int b) {
  return (a > b) ? a : b;
}

Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),height(y->right)) +1;
  x->height = max(height(x->left),height(x->right)) +1;
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}


Node *insertNode(Node *node, int key){
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

bool getPath(Node* root, vector<int>& arr, int x)
{
    if (!root)
        return false;
 
    arr.push_back(root->key);
 
    if (root->key == x)
        return true;
 
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;
 
    arr.pop_back();
    return false;
}

stack<int> hasil;
 
void printPathBetweenNodes(Node* root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;
 
    getPath(root, path1, n1);
    getPath(root, path2, n2);
 
    int intersection = -1;
 
    long unsigned int i = 0, j = 0;
    while (i != path1.size() || j != path2.size()) {

        if (i == j && path1[i] == path2[j]) {
            i++;
            j++;
        }
        else {
            intersection = j - 1;
            break;
        }
    }

    int sum=0,tmp=0,loop,tmp1=0;

    for (int i = path1.size() - 1; i > intersection; i--)
        hasil.push(path1[i]);
 
    for (long unsigned int i = intersection; i < path2.size(); i++)
        hasil.push(path2[i]);

    loop = hasil.size();

    for (int i = 1 ; i < loop ; i++){
        tmp = hasil.top();
        hasil.pop();
        tmp1 = tmp - hasil.top();
        if (tmp1 < 0)
            tmp1 *= -1;
        sum += tmp1;
    }
    cout << sum;
}

int main()
{
	struct Node* root = NULL;
    int n,num;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> num;
        insertNode(root,num);
    }
	int a,b;
    cin >> a >> b;
	printPathBetweenNodes(root, a, b);
	return 0;
}

