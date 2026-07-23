#include <iostream>
using namespace std;  
   
struct Node{
    public:
    int data;   
    Node* next;
    Node* back;
    public: 
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node * covert2DoublyLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size();i++){
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

Node * deleteHead(Node* head){
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    delete temp;
    return head;
}

Node * deleteTail(Node* head){
     if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr ;
    }
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node * deleteK(Node * head, int k){
     if(head == nullptr){
        delete head;
        return nullptr ;
    }
    if(k == 1){
        Node* temp = head;
        head = head->next;
        head->back = nullptr;
        delete temp;
        return head;
    }
    int cnt = 0;
     Node* temp = head;
        Node* prev = nullptr;
      while(temp!= nullptr){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            if(prev->next != nullptr)
                prev->next->back = prev;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        if(temp == nullptr){
            cout << "k is greater than the length of the list." << endl;
            break;
        }
        if(temp->next == nullptr && cnt < k){
            cout << "k is greater than the length of the list." << endl;
            break;
        }
    }
    return head;
}

Node * removeKthElement(Node *head, int k) {
    if(head == nullptr){
        return nullptr;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if(prev == nullptr && front == nullptr){
        return nullptr;
    }
    if(prev == nullptr){
        return deleteHead(head);
    }
    if(front == nullptr){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    delete temp;
    return head;
}

Node * deleteNode(Node * head, int el){
    if(head == nullptr){
        return nullptr;
    }
    if(head->data == el){
        return deleteHead(head);
    }
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == el){
            Node *prev = temp->back;
            Node *front = temp->next;

            if(prev == nullptr && front == nullptr){
                return nullptr;
            }
            if(prev == nullptr){
                return deleteHead(head);
            }
            if(front == nullptr){
                return deleteTail(head);
            }
            prev->next = front;
            front->back = prev;
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;

}

void removeNode(Node * temp2){
    Node *prev = temp2->back;
    Node *front = temp2->next;  
    
    if(front == nullptr){
        prev->next = nullptr;
        delete temp2;
        return;
    }
    prev->next = front;
    front->back = prev;
    delete temp2;   

}

Node * insertHead(Node* head,int val){
    Node *temp = new Node(val);
    if(head == nullptr){
        return temp;
    }
    temp->next = head;
    head->back = temp;
    return temp;
}

Node * insertBeforeHead2(Node* head,int val){
    Node* temp2 = new Node(val, head, nullptr);
    head->back = temp2;
    return temp2;
}

Node * insertBeforeTail(Node* head, int val){ 
    if(head->next == nullptr){
        return insertBeforeHead2(head, val);
    }

Node *tail = head; 
while(tail->next != nullptr){
    tail = tail->next;
}
Node *prev = tail->back;
Node *temp = new Node(val, tail, prev);
prev->next = temp;
tail->back = temp;
return head;    

}

Node * insertBeforeK(Node*head, int val, int k){
    if(k == 1){
        return insertBeforeHead2(head, val);
    }
    int cnt = 0;
    Node *temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k)
            break;
        temp = temp->next;
    }
     
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;    
}

void insertBeforeElement(Node *node, int val){
    Node *prev = node->back;
    Node *newNode = new Node(val, node, prev);

    prev->next = newNode;
    node->back = newNode;
}
void print(Node *head)
{
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {12, 5, 7, 8, 9};
    Node* head = covert2DoublyLL(arr);
    cout <<"head: " << head->data << endl;
    print(head);
    cout << endl;
    cout << endl;
    


        head = deleteHead (head);
        cout << "After deleting head node, new head is: " << (head ? head->data : -1) << endl;
        print(head);
        cout << endl;
        cout << endl;


        Node * tail = deleteTail(head);
        cout << "\nAfter deleting tail node, new tail is: " << (tail ? tail->data : -1) << endl;
        print(tail);
        cout << endl;
        cout << endl;


        Node *k = deleteK(head, 1);
        cout << "\nAfter deleting 1st node, new Linked list is : ";
        print(k);
        cout << endl;
        cout << endl;


        Node *k1 = removeKthElement(k, 2);
        cout << "After deleting 2nd node, new head is: " << (k1 ? k1->data : -1) << endl;
        print(k1);
        cout << endl;
        cout << endl;


        Node *el = deleteNode(k1, 8);
        cout << "After deleting element 8, new head is: " << (el ? el->data : -1) << endl;
        print(el);
        cout << endl;
        cout << endl;

        Node *newhead = insertBeforeHead2(el, 100);
        cout << "After inserting 100 at head, new head is: " << (newhead ? newhead->data : -1) << endl;
        print(newhead);
        cout << endl;
        cout << endl;


        Node *newtail = insertBeforeTail(newhead, 200);
        cout << "After inserting 200 before tail, new head is: " << (newtail ? newtail->data : -1) << endl;
        print(newtail); 

        Node *newk = insertBeforeK(newtail, 300, 1);
        cout << "After inserting 300 before 3rd node, new head is: " << (newk ? newk->data : -1) << endl;
        print(newk);

        insertBeforeElement(newk->next, 400);
        print(newk); 
        return 0;
}