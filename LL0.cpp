#include <iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

void insertAtTail(Node* &head, int val){
    
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(Node* &head, int val){

    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void display(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

void deletion(Node* &head, int val){

    Node* temp = head;

    if(head == NULL){
        return;
    }
    while(temp->next->data != val){
        temp = temp->next;
    }
    Node* toDelete = temp -> next;
    temp->next = temp->next->next;
    delete toDelete;
}

void deletionAtHead(Node* &head){
    Node* toDelete = head;
    head = head -> next;
    delete toDelete;
}

bool isCircular(Node* head){

    Node* temp = head->next;

    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    if(temp=head) return true;

    return false;
}

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev; //new head
}

Node* kReverese(Node* head, int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    int count = 0;
    while(curr != NULL && count < k){
        next = curr -> next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }

    if(next!=NULL){
        head->next = kReverese(next,k);
    }

    return prev;

}

int main(){
    Node *head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    display(head);
    cout << endl;

    // deletion(head, 20);

    display(head);

    cout << endl;

    // if(detectLoop(head)){
    //     cout << "Yes" << endl;
    // }
    // else{
    //     cout << "No" << endl;
    // }

    Node* newHead = kReverese(head,3);
    display(newHead);
}
