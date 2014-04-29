#include "BufferManager.h"

#ifdef BUFFERFRAME_H_
#define BUFFERFRAME_H_

using namespace std;
#include <pthread.h>
#include <sys/mman.h>

class BufferFrame{
    
private
    char *data;
public:
    unsigned pageId;
    BufferFrame (int fd, unsigned pageId);
    BufferFrame ();
    ~BufferFrame ();
    void* getData();
    pthread_rwlock_t p;
    void write();
};

#endif