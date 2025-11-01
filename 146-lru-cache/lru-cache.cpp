class LRUCache {
public:
    class node
    {
        public:
            int key;
            int val;
            node *next;
            node *prev;
            node(int key, int val)
            {
                this->key=key;
                this->val=val;
            }
    };
    int cap;
    unordered_map<int , node*>mpp;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node *delNode)
    {
        node *temp1 = delNode->prev;
        node *temp2 = delNode->next;
        temp1->next=temp2;
        temp2->prev=temp1;
    }
    int get(int key) {
        if(!mpp.count(key))
            return -1;
        node *temp = mpp[key];
        int res = temp->val;
        deleteNode(temp);
        addNode(temp);
        return res;
    }
    
    void put(int key, int value) {
        if(mpp.count(key))
        {
            node *temp = mpp[key];
            temp->val=value;
            deleteNode(temp);
            addNode(temp);
        }
        else
        {
            if(mpp.size()==cap)
            {
                node *temp = tail->prev;
                mpp.erase(temp->key);
                deleteNode(temp);
            }
            node *newNode = new node(key, value);
            addNode(newNode);
            mpp[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */