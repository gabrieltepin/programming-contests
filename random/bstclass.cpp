#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

class Bst{
    Node* root;
    Node* insert(Node* node, int n){
        if (node == NULL)
            return node = newnode(n);
        if(n < node->data) 
            node->left = insert(node->left, n);
        else 
            node->right = insert(node->right, n);
        return node;
    }
    Node* newnode(int n){
        Node* aux = new Node();
        aux -> data = n;
        aux -> right = NULL;
        aux -> left = NULL;
        return aux;
    }

    void printBst(Node* node){
        if (node ==NULL)
            return;
        cout << node->data << " ";
        printBst(node->left);
        printBst(node->right);
    }
    int height(Node* node){
        if (node == NULL) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void printOrder(Node* node){
        queue < Node* > q;
        q.push(node);
        Node* current;
        while (q.size()){
            current = q.front();
            cout << current->data << " ";
            if(current->left != NULL) q.push(current->left);
            if(current->right != NULL) q.push(current->right);
            q.pop();
        }
        cout << endl;
    }
    void empty(Node* node){
        if (node == NULL) return;
        empty(node->left);
        empty(node->right);
        delete node;
    }
    Node* minValue(Node* node){
        if(node == NULL) return node;
        if (node->left == NULL) return node;
        minValue(node->left);
        return node;
    }
    Node* remove(Node* node, int key){
        if (node == NULL) return node;
        if (key < node->data) node->left = remove(node->left, key);
        else if (key > node->data) node->right = remove(node->right, key);
        else{
            if (node->left == NULL){
                Node* tmp = node->right;
                delete node;
                return tmp;
            }
            if (node->right == NULL){
                Node* tmp = node->left;
                delete node;
                return tmp;
            }
            Node* tmp = minValue(node->right);
            node->data = tmp->data;
            node->right = remove(node->right, tmp->data);
        }
        return node;
    }
    void postorder(Node* node);

public:
    Bst(){
        root=NULL;
    }
    ~Bst(){
        empty(root);
    }
    void insert(int x){
        root = insert(root, x);
    }
    void printBst(){
        printBst(root);
        cout << endl;
    }
    void postorder(){
        postorder(root);
        cout << endl;
    }
    int height(){
        return height(root);
    }
    void printOrder(){
        printOrder(root);
    }
    void empty(){
        empty(root);
    }
    void remove(int x){
        remove(root, x);
    }

};
void Bst::postorder(Node* node){
    if (node ==NULL)
            return;
        printBst(node->left);
        printBst(node->right);
        cout << node->data << " ";
} 
int main(){
    Bst t;
    t.insert(4);
    t.insert(4);
    t.insert(7);
    t.printOrder();

    t.insert(10);
    t.insert(1);
    t.printBst();

    t.remove(4);
    t.postorder();

    cout << t.height();
    return 0;
}