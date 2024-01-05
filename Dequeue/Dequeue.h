#include <iostream>

using namespace std;

template <typename type>
class Node{
    public:
        type data;
        Node* next;
        Node* prev;

    Node(const type& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename type>
class Dequeue{
    private:
        Node<type>* head;
        Node<type>* tail;
        size_t siz = 0;

    public:
        Dequeue() : head(nullptr), tail(nullptr) {}
        Dequeue(int n, const type& value) : head(nullptr), tail(nullptr) {
            while(n--){
                push_back(value);
            }
        }

        void push_back(const type& value){
            Node<type>* temp = new Node<type>(value);
            if(empty()){
                head = tail = temp;
                siz++;
            }
            else{
                Node<type>* previous = tail;
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                siz++;
            }
        }

        void push_front(const type& value){
            Node<type>* temp = new Node<type>(value);
            if(empty()){
                head = tail = temp;
                siz++;
            }
            else{
                head->prev = temp;
                temp->next = head;
                head = temp;
                siz++;
            }
        }

        void pop_front(){
            if(empty()){
                return;
            }else{
                Node<type>* temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
                siz--;
            }
        }

        void pop_back(){
            if(empty()){
                return;
            }
            else if(size() == 1){
                pop_clear();
                siz = 0;
            }
            else{
                Node<type>* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
                siz--;
            }

        }

        type& front(){
            return head->data;
        }

        type& back(){
            return tail->data;
        }


        bool empty() const{
            return head == nullptr;
        }

        size_t size() const{
            return siz;
        }

        void resize(size_t newsiz, const type& d){
            if(newsiz > siz){
                size_t t = newsiz - siz;
                siz = newsiz;
                while(t--){
                    push_back(d);
                    siz--;
                }
            }else{
                size_t deletefrom = siz - newsiz;
                size_t currind = 0;
                while(deletefrom--){
                    pop_back();
                }
                siz = newsiz;
            }
        }

        void clear(){
            while(head != nullptr){
                Node<type>* temp = head;
                head = head->next;
                delete temp;
            }
            cout<<"Dequeue has been cleared"<<endl;
            siz = 0;
        }

        type& operator[](size_t index){
            Node<type>* curr = head;
            size_t currind = 0;
            while(curr != nullptr){
                if(currind == index){
                    return curr->data;
                }
                curr = curr->next;
                currind+=1;
            }
            //throw out_of_range("Index out of range");
            return head->data;
        }

        void display(){
            if(empty()){
                cout<<"Dequeue is empty"<<endl;
                return;
            }else{
                Node<type>* current = head;
                while(current != nullptr){
                    cout<<current->data<<" ";
                    current = current->next;
                }
                cout<<"\n";
            }
            
        }

        void display_reverse(){
            Node<type>* current = tail;
            while(current != nullptr){
                cout<<current->data<<" ";
                current = current->prev;
            }
            cout<<"\n";
        }
        void pop_clear(){
            while(head != nullptr){
                Node<type>* temp = head;
                head = head->next;
                delete temp;
            }
        }
};
