#define MAX_SIZE_QUEUE 10

typedef enum
{
    QUEUE_TRUE = 0,
    QUEUE_FALSE = 1
} status_t;

/**
 * Design a queue that supports enqueue and dequeue operations at a given index 
 * Implement the queue using regular array (not circular) 
 * You can choose the allocation of the array to be on stack or heap
 * You cannot used linked list
 * 
 * Check example below:
 * * Enqueing 56 at index 3 of array [32, 4, 7, 89, 50, 40] results in [32, 4, 7, 56, 89, 50, 40].
 * * Dequeing from index 2 of array [32, 4, 7, 56, 89, 50, 40] results in 7 
 * * and the updated queue is [32, 4, 56, 89, 50, 40]. 
 * 
 * The enqueuing operation shift elements right and dequeing operation shifts elements left
 * Of course, the size of the array cannot change, but the front and back of the queue must be updated after enqueue and dequeue operations.
 **/

/**
 * This methods creates or intialized the queue 
 * */
int queue[MAX_SIZE_QUEUE];
unsigned int size = 0;
unsigned int back = MAX_SIZE_QUEUE - 1; // Initally assumed that back is at end
unsigned int front = 0;

int isFull();
int isEmpty();

// void create();

/**
 * Enqueue operation at a given index. 
 * If the queue is full or index is out of bound, return QUEUE_FALSE
 * If the operation is successful, return QUEUE_TRUE
 * 
 * value: the value to the enqueued
 * index: index to be enqueued at
 * */
status_t enqueueAtIndex(int value, int index)
{
    if (isFull())
    {
        return QUEUE_FALSE;
    }

    back = (back + 1) % MAX_SIZE_QUEUE;

    size++;

    queue[back] = value;

    return QUEUE_TRUE;
};

/**
 * Dequeue operation at a given index. 
 * If the queue is empty or index is out of bound, return QUEUE_FALSE
 * If the operation is successful, return QUEUE_TRUE
 * index: index to be dequeued from
 * out_value: address of variable that will be updated with the value dequeued
 * */
status_t dequeueFromIndex(int index, int *out_value)
{
    int index = QUEUE_FALSE;

    if (isEmpty())
    {
        return QUEUE_FALSE;
    }

    index = queue[front];

    front = (front + 1) % MAX_SIZE_QUEUE;

    size--;

    return index;
};

/**
 * Access the front element of the queue without dequeing
 * If the operation is successful, return QUEUE_TRUE else QUEUE_FALSE
 * out_value: address of variable that will be updated with the value accessed
 * */
status_t getfront(int *out_value)
{
    return (isEmpty())
               ? QUEUE_FALSE
               : queue[front];
};

/**
 * Access the back element of the queue without dequeing
 * If the operation is successful, return QUEUE_TRUE else QUEUE_FALSE 
 * out_value: address of variable that will be updated with the value accessed
 * */
status_t getback(int *out_value)
{
    return (isEmpty())
               ? QUEUE_FALSE
               : queue[back];
};

/**
 * Return the starting address of the array
 * */
int *getQueue()
{
    return (size == MAX_SIZE_QUEUE);
};