#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node *p;
    struct Node *n;
}Node;

typedef struct ListStruct{
    Node *head;
    Node *tail;
}ListStruct;

ListStruct *create(){
    ListStruct *newl = (ListStruct*)malloc(sizeof(ListStruct));
    newl->head = NULL;
    newl->tail = NULL;
    return newl;
}

Node* init (int data){
    Node *nNode = (Node*) malloc(sizeof(Node));
    nNode->data = data;
    nNode->p = NULL;
    nNode->n = NULL;

    return nNode;
}

void insert (ListStruct *list, int data){
    Node *newNode = init(data);
    if(list->head == NULL){
        list->head = newNode;
        list->tail = list->head;
    }
    else{
        newNode->n = list->head;
        list->head->p = newNode;
        list->head = newNode;
    }
}


void deleteKey(ListStruct *list,int data){
    Node *aux = list->head;
    while(aux != NULL){
        if(aux->data == data){
            if(aux == list->head && list->head == list->tail){
                list->head = list->tail = NULL;
            }
            else if(aux == list->head){
                list->head = list->head->n;
                list->head->p = NULL;
            }
            else if(aux == list->tail){
                list->tail = list->tail->p;
                list->tail->n = NULL;
            }
            else{
                aux->p->n = aux->n;
                aux->n->p = aux->p;
            }

            delete aux;

            return;
        }
        aux = aux->n;
    }
}

void deleteH(ListStruct *list){
    if(list->head == NULL) return;
    Node *nodeDel = list->head;

    if(list->tail == list->head){
        list->tail = list->head = NULL;
    }
    else{
        list->head = list->head->n;
        list->head->p = NULL;
    }

    delete nodeDel;
}

void deleteT(ListStruct *list){
    if(list->tail == NULL) return;
    Node *nodeDel = list->tail;

    if(list->tail == list->head){
        list->tail = list->head = NULL;
    }
    else{
        list->tail = list->tail->p;
        list->tail->n = NULL;
    }
    delete nodeDel;
}

void print(ListStruct *list){
    Node *curr = list->head;
    while(curr != NULL){
        cout << curr->data;
        if(curr->n != NULL) cout <<  " ";
        Node *aux = curr;
        curr = curr->n;
        delete aux;
    }

    cout << "\n";
    list->head = list->tail = NULL;
}

int main(){

    int n;
    cin >> n;

    string s;
    int x;

    ListStruct *list = create();

    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "delete" || s == "insert"){
            cin >> x;
            if(s == "insert"){
                insert(list, x);
            }
            else{
                deleteKey(list, x);
            }
        }
        else if(s == "deleteFirst"){
            deleteH(list);
        }
        else if(s == "deleteLast"){
            deleteT(list);
        }
    }

    print(list);

    return 0;
}
