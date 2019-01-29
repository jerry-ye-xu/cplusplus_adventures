
#include "node_implement.h"

#ifndef QUEUE_IMPLEMENT_H
#define QUEUE_IMPLEMENT_H

class Queue{
	public:
		Queue();
		// Queue(int value);

		void enqueue(int value);
		int dequeue();
		int check_front();
		int check_size();

		void destroy_queue();

	private:
		int size; 
		Node* head; // to be dequeued
		Node* tail; // to be enqueued
};

#endif