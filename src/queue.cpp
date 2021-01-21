#ifdef ARRAY_BASED_QUEUE

#include "../include/queue.h"

bool EmptyQueue()
{
    if(Front==Rear&&Front==-1)
        return 1;
    return 0;
}

bool FullQueue()
{
    if((Front-Rear==1) ||(Front==0 && Rear==queue_size-1))
        return 1;
    return 0;
}

void Enqueue(int val)
{
    if(!FullQueue())
    {
        if(EmptyQueue())
            Front++;

        Rear++;
        Rear%=queue_size;
        QUEUE[Rear]=val;
    }
}

void Dequeue()
{
    if(!EmptyQueue())
    {
        if(Front==Rear)
        {
            Front=-1;
            Rear=-1;
        }
        else
        {
            Front++;
            Front%=queue_size;
        }
    }
}

queue_elements Queue_peak()
{
    if(!EmptyQueue())
        return QUEUE[Front];
        return -1;
}

void Queue_Display()
{
    if(!EmptyQueue())
    {
        if(Front<=Rear)
        {
            for(int Display_ptr=Front; Display_ptr<=Rear; Display_ptr++)
            {
                cout<<QUEUE[Display_ptr]<<" ";
            }
        }
        else
        {
            for(int Display_ptr=Front; Display_ptr<queue_size; Display_ptr++)
            {
                cout<<QUEUE[Display_ptr]<<" ";
            }
            for(int Display_ptr=0; Display_ptr<=Rear; Display_ptr++)
            {
                cout<<QUEUE[Display_ptr]<<" ";
            }
        }
    }
    cout<<"\n";
}

void Queue_Clear()
{
    if(!EmptyQueue())
    {
        Front=-1;
        Rear=-1;
    }
}


#else

#include "../include/queue.h"

void enqueue(int value)
{
    QUEUE* newElement = new QUEUE;
    newElement->data=value;
    newElement->next=NULL;

    if(QisEmpty())
    {
        Front=Rear=newElement;
    }
    else
    {
        Rear->next=newElement;
        Rear=newElement;
    }
}

elements_type dequeue()
{

    if(!QisEmpty())
    {
        elements_type value;
        if(Front==Rear)
        {
            QUEUE* delElement=Front;
            value=delElement->data;
            Front=Rear=NULL;
            delete (delElement);
        }
        else
        {
            QUEUE* delElement=Front;
            value=delElement->data;
            Front=Front->next;
            delete (delElement);
        }
        return value;
    }
}

elements_type queuePeak()
{
    if(!QisEmpty())
    {
        return Front->data;
    }
}

void displayQueue()
{
    if(!QisEmpty())
    {
        QUEUE* displayPtr=Front;
        while(displayPtr)
        {
            cout<<displayPtr->data<<" ";
            displayPtr=displayPtr->next;
        }
        cout<<"\n";
    }
}

bool QisEmpty()
{
    if(!Front)
        return 1;
    return 0;
}


#endif
