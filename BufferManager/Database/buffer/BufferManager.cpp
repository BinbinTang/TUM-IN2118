<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include "BufferManager.h"

BufferManager::BufferManager(unsigned size){
    this->size = size;
    pthread_rwlock_init(buffer_p, NULL);
    pthread_rwlock_init(array_p,NULL);
    
    // file related
    
    
}

BufferFrame& BufferManager::fixPage(uint64_t pageId, bool exclusive){
    
    pthread_rwlock_rdlock(&buffer_p);
    
    if (buffer.find(pageId) == buffer.end()){
        pthread_rwlock_unlock(buffer_p);
        fench(pageId);
        pthread_rwlock_rdlock(array_)
    }else{
        assert(buffer[pageId]!= NULL);
        if (exclusive == true){
            pthread_rwlock_wrlock(&(buffer[pageId]->p));
        }else{
            pthread_rwlock_rdlock(&(buffer[pageId]->p));
        }
        pthread_rwlock_unlock(&buffer_p);
        assert(buffer[pageId]!= NULL);
        return *buffer[pageId];
    }
    
    pthread_rwlock_unlock(&buffer_p);
    
}


void BufferManager::unfixPage(BufferFrame& frame, bool isDirty){
    pthread_rwlock_wrlock(&array_p);
    bool flag = false;
    
    BufferFrame *
}

void BufferManager::fench(unsigned pageId)
{
    pthread_rwlock_wrlock(&buffer_p);
    pthread_rwlock_wrlock(&array_p);
    
    if (array_p.size()>= size){
        
		BufferFrame *toBeFreed = NULL;
		for(vector<BufferFrame*>::iterator i = lruBuffer.begin(); i != lruBuffer.end(); ++i){
			int lockResult = pthread_rwlock_trywrlock(&((*i)->latch));
			if(lockResult == 0) {
				pthread_rwlock_unlock(&((*i)->latch));
				toBeFreed = *i;
				int cnt = buffer.erase(toBeFreed->pageId);
				assert(cnt == 1);
				toBeFreed->writeDataToFile();
				lruBuffer.erase(i);
				}
				delete toBeFreed;
                
				break;
			}
		}
        
		if(toBeFreed==NULL){
			cerr<<"no candidate was found => release locks and return!!!";
			pthread_rwlock_unlock(&lruBuffer_latch);
			pthread_rwlock_unlock(&buffer_latch);
			return;
		}
    }
}

BufferManager::~BufferManager(){
    pthread_rwlock_destroy(&buffer_p);
    pthread_rwlock_destroy(&array_p);
    close(file);
}
=======
#include "BufferManager.hpp"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

BufferManager::~BufferManager(){
  pthread_rwlock_destroy(&buffer_latch);
  pthread_
  
  close(file);
}
>>>>>>> 74c73c29289d8b2b0dd0b2a1035fc77535036441
