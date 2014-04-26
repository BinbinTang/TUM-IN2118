#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <pthread.h>

using namespace std;

class BufferManager{
    
public:
    BufferManager(unsigned size);
    BufferFrame& fixPage(uint64_t pageId, bool exclusive);
    void unfixPage(BufferFrame& frame, bool isDirty);
    
    ~BufferManager();
};

class BufferFrame{
private:
    uint64_t pageId;
    bool exclusive;
    bool isDirty;
    
public:
    void* getData();
}
