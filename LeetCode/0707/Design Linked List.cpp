struct Node {
    int val;
    Node* next;
};

class MyLinkedList {
private:
    Node* head;
    int length;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= length) {
            return -1;
        }
        
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (i == this->length - 1) break;
            temp = temp->next;
        }
        
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp = (length != 0) ? head : NULL;
        this->head = new Node;
        this->head->val = val;
        this->head->next = temp;
        
        this->length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = new Node;
        temp->next->val = val;
        temp->next->next = NULL;
        
        this->length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length) {
            return;
        } else if (index == 0) {
            addAtHead(val);
            return;
        } else if (index == length) {
            addAtTail(val);
            return;
        }
        
        Node* temp = this->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        
        Node* temp2 = new Node;
        temp2->val = val;
        temp2->next = temp->next;
        temp->next = temp2;
        
        length++;
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {        
        if (index < 0 || index >= length) {
            return;
        }
        
        Node* temp = head;
        if (index == 0) {
            this->head = this->head->next;
            delete temp;
            return;
        }
        
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        
        Node* del = temp->next;
        
        if (index == this->length - 1) {
            temp->next = NULL;
        } else {
            temp->next = temp->next->next;
        }
        
        delete del;
        
        this->length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */