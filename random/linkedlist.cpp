#include "bits/stdc++.h"
using namespace std;
#define M 5

struct Node{
    int data;
    Node* next;
};

class LinkedList {
    Node* list;
    Node* insert (int data, Node* node){
        if (node == NULL){
            Node* tmp = new Node();
            tmp->data = data;
            tmp->next = NULL;
            return tmp;
        }
        node->next = insert(data, node->next);
        return node;
    }

    bool find(Node* node, int data){
        if (node==NULL) return false;
        if (node->data == data) return true;
        return find(node->next, data);
    }

    Node* remove(Node* node, int x){
        if(node==NULL) return node;
        if(node->data == x){
            Node* tmp = node->next;
            delete node;
            return tmp;
        }
        node-> next = remove(node->next, x);
        return node;
    }

public:
    LinkedList(){
        list = NULL;
    }
    ~LinkedList(){
        delete[] list;
    }

    void insert (int val){
        list = insert(val, list);
    }
    /*
    insertion in O(1)

    Node* tmp = new Node();
        tmp->data = data;
        tmp->next = NULL;
        if (node == NULL){
            return tmp;
        }
        Node* tmp2 = node;
        tmp->next = tmp2;
        return tmp;
    
    */
    void find(int data){
        if(find (list, data)) cout << "Found!" << endl;
        else cout << "Not found" << endl;
    }

    void print(){
        Node* current = list;
        while (current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void remove(int x){
        list = remove(list, x);
    }
};

int main(){
    LinkedList L;
    L.insert(10);
    L.insert(3);
    L.insert(4);
    L.insert(87);
    L.insert(123);
    L.print();

    L.find(87);
    L.remove(87);
    L.print();
    return 0;
}