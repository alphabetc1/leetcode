146. LRU缓存机制.cpp
struct DualLink{
    int key, value;
    DualLink *prev;
    DualLink *next;
    DualLink():  key(0), value(0), prev(nullptr), next(nullptr){ }
    DualLink(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){ }
};

class LRUCache {
private:
    int size, cap;
    DualLink *head, *tail;
    unordered_map<int, DualLink*> cache;
public:
    LRUCache(int capacity): size(0), cap(capacity) {
        head = new DualLink();
        tail = new DualLink();
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(!cache.count(key))   {
            return -1;
        }else{
            DualLink *tmp = cache[key];
            removeToHead(tmp);
            return tmp->value;
        }
    }
    
    void put(int key, int value) {
        if(!cache.count(key))   {
            DualLink *tmp = new DualLink(key, value);
            cache[key] = tmp;
            addToHead(tmp);
            ++size;
            if(size > cap) {
                DualLink *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }else{
            DualLink *tmp = cache[key];
            tmp->value = value;
            removeToHead(tmp);
        }
    }

    void removeNode(DualLink *tmp)  {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }

    void addToHead(DualLink *tmp)  {
        head->next->prev = tmp;
        tmp->next = head->next;
        head->next = tmp;
        tmp->prev = head;
    }

    void removeToHead(DualLink *tmp)    {
        removeNode(tmp);
        addToHead(tmp);
    }

    DualLink* removeTail( )    {
        DualLink *node = tail->prev;
        removeNode(node);
        return node;
    }
};