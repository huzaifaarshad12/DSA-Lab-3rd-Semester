#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val): data(val), next(NULL) {}

};

class LinkList{
   public:
    LinkList() { head = NULL; }
    ~LinkList();
    bool isEmpty() { return head == NULL; }
    Node* insertNode(int index, int x);
    Node* insertAtHead(int x);
    Node* insertAtEnd(int x);
    bool findNode(int x);
    bool deleteNode(int x);
    bool deleteFromStart();
    bool deleteFromEnd();
    void displayList(void);
    Node* reverseList();
    Node* sortList(Node* list);
    Node* removeDuplicates(Node* list);
    Node* mergeLists(Node* list1, Node* list2);
    Node* interestLists(Node* list1, Node* list2);

private:
    Node* head;
};
LinkList::~LinkList() 
{
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

Node* LinkList::insertNode(int index, int x) 
{
    if (index < 0) 
    return NULL;
    Node* newNode = new Node(x);
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* current = head;
    for (int i = 0; i < index - 1 && current != NULL; ++i) 
    {
        current = current->next;
    }
    if (current == NULL) 
    return NULL;
    newNode->next = current->next;
    current->next = newNode;
    return head;

}
Node* LinkList::insertAtHead(int x) 
{
    return insertNode(0, x);
}
Node* LinkList::insertAtEnd(int x) 
{
    if (head == NULL) 
    return insertAtHead(x);
    Node* current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    Node* newNode = new Node(x);
    current->next = newNode;
    return head;
}
bool LinkList::findNode(int x) 
{
    Node* current = head;
    while (current != NULL) 
    {
        if (current->data == x)
         return true;
        current = current->next;
    }
    return false;
}

bool LinkList::deleteNode(int x) {
    if (head == NULL) 
    return false;
    bool deleted = false;
    while (head != NULL && head->data == x) 
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        deleted = true;
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) 
    {
        if (current->next->data == x) 
        {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            deleted = true;
        } 
        else 
        {
            current = current->next;
        }
    }
    return deleted;
}
bool LinkList::deleteFromStart() 
{
    if (head == NULL) return false;
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    return true;
}
bool LinkList::deleteFromEnd() {
    if (head == NULL) return false;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return true;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    return true;
}
void LinkList::displayList(void) 
{
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
Node* LinkList::reverseList() 
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
Node* LinkList::sortList(Node* list) {
    if (list == NULL || list->next == NULL) return list;
    Node* mid = list;
    Node* fast = list->next;
    while (fast != NULL && fast->next != NULL) 
    {
        mid = mid->next;
        fast = fast->next->next;
    }
    Node* half = mid->next;
    mid->next = NULL;
    return mergeLists(sortList(list), sortList(half));
}
Node* LinkList::removeDuplicates(Node* list) 
{
    Node* current = list;
    while (current != NULL && current->next != NULL) 
    {
        if (current->data == current->next->data) 
        {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        } 
        else 
        {
            current = current->next;
        }
    }
    return list;
}
Node* LinkList::mergeLists(Node* list1, Node* list2) 
{
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->data < list2->data) 
    {
        list1->next = mergeLists(list1->next, list2);
        return list1;
    } 
    else 
    {
        list2->next = mergeLists(list1, list2->next);
        return list2;
    }
}
Node* LinkList::interestLists(Node* list1, Node* list2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (list1 != NULL && list2 != NULL) 
    {
        if (list1->data == list2->data) 
        {
            tail->next = new Node(list1->data);
            tail = tail->next;
            list1 = list1->next;
            list2 = list2->next;
        } 
        else if (list1->data < list2->data) 
        {
            list1 = list1->next;
        } else 
        {
            list2 = list2->next;
        }
    }
    return dummy.next;
}
int main() {
    LinkList list;
    
    list.insertAtHead(10); 
    list.insertAtEnd(20);
    list.insertNode(0, 14);  //output ; 14,10,20
    list.displayList();

    list.deleteNode(15);
    list.displayList(); 
    //it will not find any 15 , so it will 
    // Output: 14,10 20
    list.insertAtEnd(30);
    list.displayList(); // Output: 14,10 20 30
    list.reverseList();
    list.displayList(); // Output: 30 20 10, 14
    list.reverseList();
    list.displayList(); // Output: 14,10 20 30
    
    return 0;
}

