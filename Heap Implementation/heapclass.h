#include "location_stats_struct.h"

class MaxHeap{
    vector<pair<int, location_stats>> heap; // Key is line number, value is location_stats

public:
    MaxHeap() = default;

    void insert(int key, location_stats value){
        heap.push_back({key, move(value)});
        heapifyUp(heap.size() - 1);
    }

    void heapifyUp(int index){     //https://www.geeksforgeeks.org/building-heap-from-array/
        while (index > 0){
            int parentIndex = (index - 1) / 2;    //Reverse finds parent
            if (heap[index].first > heap[parentIndex].first){    //Compares new element with parenet
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void extractMax(){      //I use this to verify that
        auto maxElement = heap.front();

        heap.front() = heap.back();         // Replace root of the heap last
        heap.pop_back();

        heapifyDown(0);                //Use this to bring it back down
        cout << "Town number: " << maxElement.second.town_number << endl  //Prints last town in col
             << "County: " << maxElement.second.county << endl
             << "State: " << maxElement.second.state << endl
             << "Population: " << maxElement.second.population << endl
             << "Poverty rate: " << maxElement.second.poverty_rate << "%" << endl
             << "Income: $" << maxElement.second.income << endl
             << "Low access: " << maxElement.second.low_access << endl;
    }

    void heapifyDown(int index){            //Used code from my lab 6!!
        int size = heap.size();             //Compares with children
        while(true) {
            int maxIndex = index;
            int leftChild = 2*index+1;
            int rightChild =2*index+2;

            if (leftChild < size && heap[leftChild].first > heap[maxIndex].first){ //Checks bounds and compared with left
                maxIndex = leftChild;
            }
            if (rightChild < size && heap[rightChild].first > heap[maxIndex].first){ //Checks bounds and compares with right
                maxIndex = rightChild;
            }

            if (maxIndex == index) {
                break;
            }
            swap(heap[index], heap[maxIndex]);
            index = maxIndex;
        }
    }
};
#ifndef DSAPROJECT3_HEAPCLASS_H
#define DSAPROJECT3_HEAPCLASS_H

#endif //DSAPROJECT3_HEAPCLASS_H
