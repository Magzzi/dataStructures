#include <iostream>

using namespace std;

class linkedList {
  private:
    struct Node {
        int data;
        struct Node* next;
    };
    
    Node* head;
  public:
    linkedList(){
        head = NULL;
    }
    void appendNode(int x);
    void removeNode();
    void traverseList();
    
};

void linkedList::appendNode(int x){
    Node *newNode = new Node;
    
    newNode->data = x;
    newNode->next = NULL;
    
    if (!head){
        head = newNode;
    } else {
        Node* nodePtr = head;
        
        while (nodePtr->next){
            nodePtr = nodePtr->next;
        }
        
        nodePtr->next = newNode;
    }
    
    cout << "Succesfuly added a Node with a value " << x << ".\n";
}

void linkedList::traverseList(){
    if (!head){
        cout << "The list is empty!\n";
    } else {
        Node *nodePtr = head;
        
        while (nodePtr){
            cout << nodePtr->data << " ";
            nodePtr = nodePtr->next;
        }
        
        cout << endl;
    }
}

void linkedList::removeNode(){
    int pos;
    
    if (!head) {
        cout << "The list is empty!\n";
        return;
    } 
    
    cout << "Enter the position of the element you would like to remove: ";
    cin >> pos;
    
    Node* nodePtr = head;
    Node* prevNode = NULL;
    
    if (pos == 1) {
        head = nodePtr->next;
        delete nodePtr;
        return;
    }
    
    for (int i = 0; nodePtr != NULL && i < pos - 1; i++){
        prevNode = nodePtr;
        nodePtr = nodePtr->next;
    }
    
    if (nodePtr == NULL){
        cout << "Invalid position.\n";
        return;
    }
    
    prevNode->next = nodePtr->next;
    delete nodePtr;
    
    cout << "Element at position " << pos << " was removed.\n";
    
    
}

int main()
{
    linkedList list;
    
    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);
    list.appendNode(40);
    list.appendNode(50);
    list.appendNode(60);
    
    list.traverseList();
    
    list.removeNode();
    
    list.traverseList();
    return 0;
}