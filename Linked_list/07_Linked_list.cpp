// # Linked List Implementation in C++ 
#include <iostream>
using namespace std;        

struct Node{
    public:
    int data;   
    Node* next;
    public: 
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArrToLL(vector<int> &arr){
     Node* head = new Node(arr[0]);
     Node *mover = head;
     for (int i = 1; i < arr.size();i++){
         Node *temp = new Node(arr[i]);
         mover->next = temp;
         mover = temp;
     }
     return head;
}

int lengthofLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
       if(temp->data == val){
           return 1;
       }
        temp = temp->next;
    }
    return 0;
}

Node * deleteHead(Node* head){
   Node* temp = head;
   head = head->next;
   delete temp;
   return head;
}

Node * removetail(Node* head){
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

Node * deleteK(Node * head,int k){
    if(head == nullptr)
        return nullptr;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while(temp!= nullptr){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node * deleteElement(Node * head,int el){
    if(head == nullptr)
        return nullptr;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node *temp = head;
    Node *prev = nullptr;
    while(temp!= nullptr){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node * insertHead(Node* head,int val){
    return new Node(val, head);
}

Node * insertTail(Node* head,int val){
    Node* temp = new Node(val);
    if(head == nullptr){
        return temp;
    }
    Node* mover = head;
    while(mover->next!=nullptr){
        mover = mover->next;
    }
    mover->next = temp;
    return head;
}

Node * insertK(Node* head,int val, int k){
    Node* temp = new Node(val);
    if(k == 1){
        temp->next = head;
        return temp;
    }
    int cnt = 0;
    Node *mover = head;
    while(mover!= nullptr){
        cnt++;
        if(cnt == k-1){
            temp->next = mover->next;
            mover->next = temp;
            break;
        }
        mover = mover->next;
    }
    return head;
}

Node * insertElement(Node* head,int val, int el){
    Node* temp = new Node(val);
    if(head == nullptr){
        return temp;
    }
    if(head->data == el){
        temp->next = head;
        return temp;
    }
    Node *mover = head;
    while(mover!= nullptr){
        if(mover->next->data == el){
            temp->next = mover->next;
            mover->next = temp;
            break;
        }
        mover = mover->next;
    }
    return head;
}

ListNode *  addTwoNumbers(ListNode * head1, ListNode* head2){
    ListNode * dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    int carry = 0;
    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if(temp1)
            sum += temp1->val;
        if(temp2)
            sum += temp->val;

        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = newNode;

        if(temp1)
            temp1 = temp1->next;
        if(temp2)
            temp2 = temp2->next;
    }
    if(carry){
        ListNode *newNode = new ListNode(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

int main(){
    vector<int> arr = {12, 5, 7, 8, 9};
    // Node* y = new Node(arr[0], nullptr);

    Node* head = ConvertArrToLL(arr);
    cout <<"old head: " << head->data << endl;

    Node* temp1 = head;
    cout << "Linked List: ";
    while(temp1){
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
  
    head = deleteHead (head);
    cout << "\nAfter deleting head node, new head is: " << (head ? head->data : -1) << endl;

    Node* temp = head;
     cout << "Linked List: ";
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    Node* tail = removetail(head);
    cout << "\nAfter removing tail node, new Linked list is : ";
    temp = tail;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    Node *k = deleteK(head, 2);
    cout << "\nAfter removing tail node, new Linked list is : ";
    temp = k;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    Node *el = deleteElement(head, 8);
    cout << "\nAfter removing element 8, new Linked list is : ";
    temp = el;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
  
    Node *newhead = insertHead(head, 100);
    cout << "\nAfter inserting 100 at head, new Linked list is : ";
    temp = newhead;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;          
    }
    
    Node *newtail = insertTail(head, 200);
    cout << "\nAfter inserting 200 at tail, new Linked list is : "; 
    temp = newtail;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }    

    Node *newk = insertK(head, 300, 3);         
    cout << "\nAfter inserting 300 at position 3, new Linked list is : ";
    temp = newk;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next; 
    }

    Node *newelement = insertElement(head, 500, 300);       
    cout << "\nAfter inserting 500 after element 3, new Linked list is : ";
    temp = newelement;
    while(temp){
        cout << temp->data << " ";  
        temp = temp->next;
    }

    cout << endl;
    cout<<"length of linked list is "<<lengthofLL(head)<<endl;
    cout<<"Element 5 present: "<<checkIfPresent(head, 5)<<endl;
    cout<<"Element 10 present: "<<checkIfPresent(head, 10)<<endl;
   
    return 0;
}