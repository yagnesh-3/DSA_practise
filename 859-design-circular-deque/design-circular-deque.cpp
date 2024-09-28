    class Node{
        public:
        int data;
        Node* next;
        Node(int k){
            data = k;
            next  = NULL;
        }
    };
class MyCircularDeque {
public:
        Node* head;
        Node* tail;
        int maxCount;
        int count;
    MyCircularDeque(int k) {
        head = NULL;
        tail = NULL;
        maxCount = k;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(count>=maxCount) return false;
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            tail = newNode;
            tail->next = newNode;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count>=maxCount) return false;
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            tail = newNode;
            tail->next = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        count++;
        return true;
        
    }
    
    bool deleteFront() {
        if(head==NULL) return false;
        if(head == tail){
            head = NULL;
            tail = NULL;
           
        }else{
            head = head->next;
            tail->next = head;
        }
        count--;
        return true;
    }
    
    bool deleteLast() {
        
        if(tail == NULL) return false;
        
        if(head == tail){
            head = NULL;
            tail = NULL;
           
        }else{
           Node*curr = head;
           while(curr->next!=tail){
            curr = curr->next;
           }
           tail = curr;
           tail->next = head;
        }
        count--;
        return true;
    }
    
    int getFront() {
        if(count==0) return -1;
        return head->data;
        
    }
    
    int getRear() {
        if(count==0) return -1;
        return tail->data;
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==maxCount;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */