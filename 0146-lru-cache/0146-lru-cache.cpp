class Node{
public:
    int key;
    int value;

    Node* next;
    Node* prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head-> next = tail;
        tail->prev = head;
    }
    void remove(Node* elem){
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
    }

    void add(Node* elem){
        elem->next = head->next;
        elem->prev = head;
        head->next->prev = elem;
        head->next = elem;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            remove(temp);
            add(temp);
            return temp->value;        
        }else{
            return  -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* elem = mp[key];
            elem->value = value;
            remove(elem);
            add(elem);
            return;
        }

        if(mp.size() == cap){
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        add(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */