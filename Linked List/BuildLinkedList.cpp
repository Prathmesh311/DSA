#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};


void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int data){
    Node* temp = head;
    Node* node = new Node(data);

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
}

void insertAtIndex(Node* &head, int data, int index){
    Node* temp = head;
    Node* node = new Node(data);

    int i = 0;
    while(temp->next != NULL){
        if(index-1 == i){
            Node* nextNode = temp->next;
            temp->next = node;
            node->next = nextNode;
            break;
        }
        temp = temp->next;
        i++;
    }
    
}

void deleteAtIndex(Node* &head, int index){
    Node* temp = head;

    int i=0;
    while(i < index-1){
        temp = temp->next;
        i++;
    }

    temp->next = temp->next->next;
}

void printLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    printLL(head);
    
    insertAtHead(head, 12);
    printLL(head);

    insertAtTail(head, 15);
    printLL(head);

    insertAtIndex(head, 20, 2);
    printLL(head);

    deleteAtIndex(head, 2);
    printLL(head);
    return 0;
}