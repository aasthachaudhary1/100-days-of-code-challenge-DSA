#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

typedef struct {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

/* MAX HEAP */

void maxHeapifyUp(int heap[],int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<heap[i]){
            swap(&heap[p],&heap[i]);
            i=p;
        }else break;
    }
}

void maxHeapifyDown(int heap[],int size,int i){
    while(2*i+1<size){
        int largest=2*i+1;
        int r=2*i+2;

        if(r<size && heap[r]>heap[largest])
            largest=r;

        if(heap[i]<heap[largest]){
            swap(&heap[i],&heap[largest]);
            i=largest;
        }else break;
    }
}

/* MIN HEAP */

void minHeapifyUp(int heap[],int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>heap[i]){
            swap(&heap[p],&heap[i]);
            i=p;
        }else break;
    }
}

void minHeapifyDown(int heap[],int size,int i){
    while(2*i+1<size){
        int smallest=2*i+1;
        int r=2*i+2;

        if(r<size && heap[r]<heap[smallest])
            smallest=r;

        if(heap[i]>heap[smallest]){
            swap(&heap[i],&heap[smallest]);
            i=smallest;
        }else break;
    }
}

/* CREATE */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj=malloc(sizeof(MedianFinder));
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

/* ADD NUMBER */

void medianFinderAddNum(MedianFinder* obj,int num){

    if(obj->maxSize==0 || num<=obj->maxHeap[0]){
        obj->maxHeap[obj->maxSize++]=num;
        maxHeapifyUp(obj->maxHeap,obj->maxSize-1);
    }
    else{
        obj->minHeap[obj->minSize++]=num;
        minHeapifyUp(obj->minHeap,obj->minSize-1);
    }

    if(obj->maxSize>obj->minSize+1){

        int val=obj->maxHeap[0];
        obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap,obj->maxSize,0);

        obj->minHeap[obj->minSize++]=val;
        minHeapifyUp(obj->minHeap,obj->minSize-1);
    }

    else if(obj->minSize>obj->maxSize){

        int val=obj->minHeap[0];
        obj->minHeap[0]=obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap,obj->minSize,0);

        obj->maxHeap[obj->maxSize++]=val;
        maxHeapifyUp(obj->maxHeap,obj->maxSize-1);
    }
}

/* FIND MEDIAN */

double medianFinderFindMedian(MedianFinder* obj){

    if(obj->maxSize>obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0]+obj->minHeap[0])/2.0;
}

void medianFinderFree(MedianFinder* obj){
    free(obj);
}
