#ifdef ARRAY_BASED_QUEUE

#define queue_elements int
#define queue_size 1000

queue_elements QUEUE[queue_size];
int Front=-1,Rear=-1;

bool EmptyQueue();
bool FullQueue();
void Enqueue(int val);
void Dequeue();
queue_elements Queue_peak();
void Queue_Display();
void Queue_Clear();


#else


#define elements_type int

struct QUEUE{
elements_type data;
QUEUE* next;
};

QUEUE* Front=NULL;
QUEUE* Rear=NULL;

void enqueue(int value);
elements_type dequeue();
elements_type queuePeak();
void displayQueue();
bool QisEmpty();


#endif
