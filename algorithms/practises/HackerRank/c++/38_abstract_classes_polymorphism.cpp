// https://www.hackerrank.com/challenges/abstract-classes-polymorphism/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

// Enter your code here.
// --------------------------------------------------------- // 
class LRUCache : public Cache {
public:
    LRUCache(int capasity) 
        : m_capasity(capasity){
        
    }
    void set(int key, int value) override {
        Node* node;
        if (key >= 1 && key <= 20 && value >= 1 && value <= 2000) {
            if (mp.empty()) {
                node = new Node(key, value);
                tail = head = node;
                mp[key] = node;
            }
            else {
                auto it = mp.find(key);
                if (it != mp.end()) {   // already exist
                    it->second->value = value;
                    if (head != it->second) {
                        it->second->prev->next = it->second->next;
                        if (tail == it->second) {
                            tail = tail->prev;
                        }
                        else {
                            it->second->next->prev = it->second->prev;
                        }
                        
                        it->second->next = head;
                        it->second->prev = nullptr;
                        head->prev = it->second;
                        head = it->second;
                    }
                }
                else { // is not empty but there is no same key
                    node = new Node(head->prev, head, key, value);
                    
                    head->prev = node;
                    head = node;
                    mp[key] = node;
                }
                
                // if exceeds the capasity
                if (mp.size() > m_capasity) {
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete tail->next;
                    tail->next = nullptr;
                }
            }
        }
    }
    int get(int key) override {
        auto it = mp.find(key);
        if (it != mp.end()) {
            return it->second->value;
        }
        return -1;
    }
private:
    int m_capasity;
};
// --------------------------------------------------------- // 

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
