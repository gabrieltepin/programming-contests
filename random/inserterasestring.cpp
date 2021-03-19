#include <iostream>
#include <string>
#define fori(x, y) for (int i = x; i< y; i++)
//#define sz(arr) (*(&arr+1) - arr)
using namespace std;
struct Node{
    char letter;
    Node* next;
};
int main() {
    //se a letra for 'a' insira dois 'd's, se for b, delete
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "sakndfkajsdpansdigasodg";
    //QUANDO NAO INICIALIZADO, ÀS VEZES O ELEMENTO PODE INICIAR COMO SENDO NULL
    //POR ISSO NAO TAVA IMPRIMINDO NADA, PORQUE, APESAR DE NAO DECLARADO, LIST INICIA COMO NULL
    //E NO WHILE(ITER) TINHAMOS ITER == NULL!!!!!
    Node list;
    Node* index = &list;
    int N = str.size();
    fori(0, N){
        if(str[i]=='a'){
            Node* tmp1 = new Node();
            Node* tmp2 = new Node();
            tmp1->letter = 'd';
            tmp2->letter = 'd';
            tmp1->next = tmp2;
            tmp2->next = NULL;
            Node* temp = index;
            temp->next = tmp1;
            index = tmp2;
        }
        else if(str[i]!='b'){
            Node* tmp1 = new Node();
            tmp1->letter = str[i];
            tmp1->next = NULL;
            Node* temp = index;
            temp->next = tmp1;
            index = tmp1;
            
        }
    }
    Node* iter = list.next;
    while (iter){
        cout << iter->letter << " ";
        iter = iter -> next;
    }
    return 0;
}

