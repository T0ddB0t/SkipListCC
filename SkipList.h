#ifndef SKIPLIST 
#define SKIPLIST 

#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxStudent = 41;
const int maxClass = 80; //is also the max lvl
map<string, string> grades;

template <class T>
class SkipListNode{
public:
    SkipListNode(){}
    T key;
    SkipListNode **next;
};

template <class T>
class SkipList{
public:
    SkipList();
    void choosePowers();
    int chooseLevel();
    T* skipListSearch(const T&);
    void skipListInsert(const T&);
private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[maxClass];
    int powers[maxClass];
};

template <class T>
SkipList<T>::SkipList(){
    for(int i = 0; i < maxClass; i++)
        root[i] = 0;
}

template <class T>
void SkipList<T>::choosePowers(){
    powers[maxClass-1] = (2 << (maxClass-1)) - 1; //2^maxClass - 1
    for(int i = maxClass - 2, j = 0; i >= 0; i--, j++)
        powers[i] = powers[i+1] - (2 << j); //2 ^ (j+1)
}

template<class T>
int SkipList<T>::chooseLevel(){
    int i, r = rand() % powers[maxClass-1] + 1;
    for(i = 1; i < maxClass; i++)
        if(r < powers[i])
            return i-1;
    return i-1;
}

template<class T>
T* SkipList<T>::skipListSearch(const T& key){
    nodePtr prev, curr;
    int lvl;
    for(lvl = maxClass-1; lvl >= 0 && !root[lvl]; lvl--);
    if(lvl == 0){
        return nullptr;
    }
    prev = curr = root[lvl];
    while(true){
        if(key == curr->key)
            return &curr->key;
        else if(key < curr->key){
            if(lvl == 0)
                return nullptr;
            else if(curr == root[lvl])
                curr = root[--lvl];
            else curr = *(prev->next + --lvl);
        }
        else{
            prev = curr;
            if(*(curr->next + lvl) != nullptr)
                curr = *(curr->next + lvl);
            else{
                for(lvl--; lvl >= 0 && *(curr->next + lvl) == nullptr; lvl--);
                if(lvl >= 0)
                    curr = *(curr->next + lvl);
                else return nullptr;
            }
        }
    }
}

template <class T>
void SkipList<T>::skipListInsert(const T& key){
    nodePtr curr[maxClass], prev[maxClass], newNode;
    int lvl, i;
    curr[maxClass-1] = root[maxClass-1];
    prev[maxClass-1] = nullptr;
    for(lvl = maxClass - 1; lvl >= 0; lvl--){
        while(curr[lvl] && curr[lvl]->key < key){
            prev[lvl] = curr[lvl];
            curr[lvl] = *(curr[lvl]->next + lvl);
        }
        if(curr[lvl] && curr[lvl]->key == key)
            return;
        if(lvl > 0)
            if(prev[lvl] == nullptr){
                curr[lvl-1] = root[lvl-1];
                prev[lvl-1] = 0;
            }
            else{
                curr[lvl-1] = *(prev[lvl]->next + lvl-1);
                prev[lvl-1] = prev[lvl];
            }
    }

    lvl = chooseLevel();

    newNode = new SkipListNode<T>;
    newNode->next = new nodePtr[lvl + 1];
    newNode->key = key;

    for(i = 0; i <= lvl; i++){
        *(newNode->next + i) = curr[i];
        if(prev[i] == nullptr)
            root[i] = newNode;
        else *(prev[i]->next + i) = newNode;
    }
}
//SkipList;
#endif