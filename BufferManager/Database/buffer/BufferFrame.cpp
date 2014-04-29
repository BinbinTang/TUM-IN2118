#include "BufferFrame.h"
#include <iostream>

BufferFrame::BufferFrame(int fd, unsigned pageId) {
    data = (char *)mmap(0, FRAME_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, pageId*FRAME_SIZE);
	if (data == MAP_FAILED) {
		cerr << "mmap failed";
		throw;
	}
	pthread_rwlock_init(&p, NULL);
	this->pageId = pageId;
}

BufferFrame::BufferFrame(){}

BufferFrame::~BufferFrame() {
	pthread_rwlock_destroy(&p);
}

void* BufferFrame::getData(){
	return reinterpret_cast<void*>(data);
}

void BufferFrame::writeDataToFile(){
	msync(data, FRAME_SIZE, MS_SYNC);
}