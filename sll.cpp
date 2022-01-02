#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

struct linkedlist{
    node * head;
    linkedlist(){head = NULL;}

    node* reverse(node* head, int k){
        node* current = head;
        node* prev = NULL, *next = NULL;

        int i = 0;
        while(current and i < k){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            i++;
        }
        if(next)    head->next = reverse(next, k);
        return prev;
    }

    void print(){
        node* temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data){
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }

};


int main(){
    linkedlist ll;
    ll.push(11);
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.head = ll.reverse(ll.head, 4);

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}

