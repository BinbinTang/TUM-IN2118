#include <iostream>
#include <string>
using namespace std;

class BufferManager{
    
public:
    BufferManager(unsigned size);
    BufferFrame& fixPage(uint64_t pageId, bool exclusive);
    void unfixPage(BufferFrame& frame, bool isDirty);
    void* getData();
    ~BufferManager();
};
