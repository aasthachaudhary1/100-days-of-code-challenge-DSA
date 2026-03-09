#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(KthLargest* obj,int i){
    while(i>0){
        int p=(i-1)/2;
        if(obj->heap[p]>obj->heap[i]){
            swap(&obj->heap[p],&obj->heap[i]);
            i=p;
        }else break;
    }
}

void heapifyDown(KthLargest* obj,int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;

        if(l<obj->size && obj->heap[l]<obj->heap[s]) s=l;
        if(r<obj->size && obj->heap[r]<obj->heap[s]) s=r;

        if(s!=i){
            swap(&obj->heap[s],&obj->heap[i]);
            i=s;
        }else break;
    }
}

void insert(KthLargest* obj,int val){
    obj->heap[obj->size]=val;
    obj->size++;
    heapifyUp(obj,obj->size-1);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize){

    KthLargest* obj=malloc(sizeof(KthLargest));
    obj->heap=malloc(sizeof(int)*k);
    obj->size=0;
    obj->k=k;

    for(int i=0;i<numsSize;i++){

        if(obj->size<k){
            insert(obj,nums[i]);
        }
        else if(nums[i]>obj->heap[0]){
            obj->heap[0]=nums[i];
            heapifyDown(obj,0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj,int val){

    if(obj->size<obj->k){
        insert(obj,val);
    }
    else if(val>obj->heap[0]){
        obj->heap[0]=val;
        heapifyDown(obj,0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj){
    free(obj->heap);
    free(obj);
}
