<<<<<<< HEAD
#ifndef BUFFERMANAGER_H_
#define BUFFERMANAGER_H_

using namespace std;

#include <pthread.h>
#include <string>
#include "BufferFrame.h"
#include <cstdlib>
#include <iostream>

=======
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <pthread.h>

using namespace std;
>>>>>>> 74c73c29289d8b2b0dd0b2a1035fc77535036441

class BufferManager{
    
private:
    
    map <unsigned, BufferFrame*> buffer;
    vector <BufferFrame*> array;
    
    pthread_rwlock_t buffer_p;
    pthread_rwlock_t array_p;
    
    unsigned size;
    int file;
    
    
    
public:
<<<<<<< HEAD
    ~BufferManager();
    void unfixPage(BufferFrame& frame, bool isDirty)
    BufferManager(const string& filename, unsigned size);
    BufferFrame& fixPage(unsigned pageId, bool exclusive);
};


#endif
=======
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
>>>>>>> 74c73c29289d8b2b0dd0b2a1035fc77535036441
