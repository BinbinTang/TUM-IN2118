#include "BufferManager.hpp"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

BufferManager::~BufferManager(){
  pthread_rwlock_destroy(&buffer_latch);
  pthread_
  
  close(file);
}
