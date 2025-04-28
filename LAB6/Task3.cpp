#include <iostream>
using namespace std;
//Task no 3
//Update Node Class in the above LinkList, Create a new class with Data, Next and Prev pointer, Create 
//DoublyLinkList and rewrite all the operations where required. Compare the time complexity of operations 
//in LinkList and DoublyLinkList. 

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkList();
    bool isEmpty() { return head == nullptr; }
    void insertAtHead(int x);
    void insertAtEnd(int x);
    bool deleteNode(int x);
    bool deleteFromStart();
    bool deleteFromEnd();
    void displayList();
    Node* reverseList();
    Node* sortList(Node* list);
    Node* removeDuplicates(Node* list);
    Node* mergeLists(Node* list1, Node* list2);
    Node* interestLists(Node* list1, Node* list2);
};

DoublyLinkList::~DoublyLinkList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkList::insertAtHead(int x) {
    Node* newNode = new Node(x);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkList::insertAtEnd(int x) {
    Node* newNode = new Node(x);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

bool DoublyLinkList::deleteNode(int x) {
    if (head == nullptr) return false;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == x) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool DoublyLinkList::deleteFromStart() {
    if (head == nullptr) return false;
    Node* toDelete = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete toDelete;
    return true;
}

bool DoublyLinkList::deleteFromEnd() {
    if (tail == nullptr) return false;
    Node* toDelete = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete toDelete;
    return true;
}

void DoublyLinkList::displayList() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* DoublyLinkList::reverseList() {
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) head = temp->prev;
    return head;
}

Node* DoublyLinkList::sortList(Node* list) {
    if (!list || !list->next) return list;
    Node* mid = list;
    Node* fast = list->next;
    while (fast && fast->next) {
        mid = mid->next;
        fast = fast->next->next;
    }
    Node* half = mid->next;
    mid->next = nullptr;
    return mergeLists(sortList(list), sortList(half));
}

Node* DoublyLinkList::removeDuplicates(Node* list) {
    Node* current = list;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            if (current->next) current->next->prev = current;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
    return list;
}

Node* DoublyLinkList::mergeLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    if (list1->data < list2->data) {
        list1->next = mergeLists(list1->next, list2);
        list1->next->prev = list1;
        list1->prev = nullptr;
        return list1;
    } else {
        list2->next = mergeLists(list1, list2->next);
        list2->next->prev = list2;
        list2->prev = nullptr;
        return list2;
    }
}

Node* DoublyLinkList::interestLists(Node* list1, Node* list2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (list1 && list2) {
        if (list1->data == list2->data) {
            tail->next = new Node(list1->data);
            tail->next->prev = tail;
            tail = tail->next;
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data < list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
    }
    return dummy.next;
}
int main() {
    DoublyLinkList dll;

    dll.insertAtHead(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtHead(5);

    dll.displayList();

    dll.deleteNode(20);
    dll.displayList();

    dll.reverseList();
    dll.displayList();

    return 0;
}



