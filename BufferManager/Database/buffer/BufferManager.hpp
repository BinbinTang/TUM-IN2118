#ifndef BUFFERMANAGER_H_
#define BUFFERMANAGER_H_

using namespace std;

#include <pthread.h>
#include <string>
#include "BufferFrame.h"
#include <cstdlib>
#include <iostream>


class BufferManager{
    
private:
    
    map <unsigned, BufferFrame*> buffer;
    vector <BufferFrame*> array;
    
    pthread_rwlock_t buffer_p;
    pthread_rwlock_t array_p;
    
    unsigned size;
    int file;
    
    
    
public:
    ~BufferManager();
    void unfixPage(BufferFrame& frame, bool isDirty)
    BufferManager(const string& filename, unsigned size);
    BufferFrame& fixPage(unsigned pageId, bool exclusive);
};


#endif