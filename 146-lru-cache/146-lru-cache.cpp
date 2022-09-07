class LRUCache {
public:
    unordered_map<int,int>mp;
    unordered_map<int,list<int>::iterator>addr;
    list<int>l;
    int cap;
    int size;
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
       if(mp.find(key)==mp.end()) 
           return -1;
        list<int> ::iterator it=addr[key];
        l.erase(it);
        addr.erase(key);
        l.push_front(key);
        addr[key]=l.begin();
        return mp[key];
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end() )
      {
        l.erase(addr[key]) ;

        addr.erase(key) ;

        mp.erase(key) ;

        size-- ;
     }
        
        if(size == cap)
    {
        // Store the Last Node's Value in variable K

        int k = l.back() ;

        // Delete the Node from Doubly LinkedList

        l.pop_back() ;

        // Remove K from Address Map & M Map as well

        addr.erase(k) ;
        mp.erase(k) ;

        // Decrement Siz by 1

        size-- ;
    }

    // Now, we can insert the Key-Value Pair into our Map M as well as our List L

    size++ ;

    // Make the Key as the First Node of our Doubly LinkedList L

    l.push_front(key) ;

    // Store the iterator / pointer of Key into Address Map

    addr[key] = l.begin() ;

    // Store the Key Value pair in Map M

    mp[key] = value ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */