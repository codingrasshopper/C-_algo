struct List
{
   int key;
   int val;
   List* next;
   List* prev;

   List(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
};

class LRUCache{
    List* cacheList;
    List* cacheListLast;
    typedef unordered_map<int, List*> CacheMap; 
    CacheMap cacheMap;

    int currentCapacity;
    int maxCapacity;

public:
    LRUCache(int capacity) : currentCapacity(0), maxCapacity(capacity), cacheList(NULL), cacheListLast(NULL) {

    }

    int get(int key) {
        CacheMap::const_iterator found;
        if((found = cacheMap.find(key)) != cacheMap.end())
        {
            if(found->second == cacheList)
            {
                return found->second->val;
            }

            putAtFront(found->second);
            return found->second->val;
        }
        return -1;
    }

    void putAtFront(List* used)
    {
        List* foundNext = used->next;
        used->next = cacheList;
        cacheList->prev = used;
        cacheList = used;
        used->prev->next = foundNext;
        if(foundNext)
        {
            foundNext->prev = used->prev;
        }
        else // update the tail
        {
            cacheListLast = used->prev;
        }
        cacheList->prev = NULL;            
    }

    void set(int key, int value) {
        // first check if the key exists
        {
            CacheMap::const_iterator found;
            if((found = cacheMap.find(key)) != cacheMap.end())
            {
                found->second->val = value;
                putAtFront(found->second);
                return;
            }
        }

        if(maxCapacity > 0) // now add the new element to the front of the list and update the map
        {
            if(currentCapacity == maxCapacity) // first ensure we don't exceed capacity
            {
                cacheMap.erase(cacheListLast->key);
                if(cacheList == cacheListLast)
                {
                    delete cacheList;
                    cacheList = cacheListLast = NULL;
                }
                else
                {
                    cacheListLast->prev->next = NULL;
                    List* prev = cacheListLast->prev;
                    delete cacheListLast;
                    cacheListLast = prev;
                }
                --currentCapacity;
            }

            List* fresh = new List(key, value);
            fresh->next = cacheList;
            if(cacheList != NULL)
            {
                cacheList->prev = fresh;
            }
            else
            {
                cacheListLast = fresh;
            }
            cacheList = fresh;

            cacheMap[key] = fresh;
            ++currentCapacity;
        }
    }
};