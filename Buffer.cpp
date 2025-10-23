#include "Buffer.hpp"
#include <cmath>
using namespace std;
// Pre: none
// Post: returns BufferIndex with offsets[0..5], failId, and totalNumberStates
// makeBufferIndex: builds offsets and fail state for buffer lengths 0..5
BufferIndex makeBufferIndex(){
    BufferIndex bufferIndex;
    int current = 0;
    for(int i = 0; i < 6; i++){
        bufferIndex.offset.at(i) = current;
        current += (int)pow(4,i); //typecast to int from double
    }
    bufferIndex.totalNumberStates= current;
    bufferIndex.failId = bufferIndex.totalNumberStates;
    return bufferIndex;
}

// Pre: all digits in {0,1,2,3}
// Post: returns base-4 integer value
// encodeBase4: digits→int (base-4)
// Example: {1,2,3}→27
int encodeBase4(vector<int>& digits){
    int value = 0;
    for(int d: digits) value = value * 4 + d;
    return value;
}

// Pre: length >= 0, 0 <= value < 4^length
// Post: returns base-4 digits of size 'length'
// decodeBase4: int→digits (base-4)
// Example: (3,27)→{1,2,3}
vector<int> decodeBase4(int length, int value){
    vector<int> out(length, 0);
    for(int i = length - 1; i > -1; i--){
        //similar if you were going to decode binary (base-2)
        //get the remainder of the value and that is your number
        //then assign into the out vector and return
        out[i] = value % 4;
        value /= 4;
    }

    return out;
}