//NMEC: Lúcia Maria Bessa de Sousa
//NOME: 93086

// Complete the functions (marked by ...)
// so that it passes all tests in DateTimeTest.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TimeInterval.h"
#include "SchedulingSequence.h"


// Create a SchedulingSequence capable of storing up to (capacity) intervals.
SchedulingSequence* SchedulingSequenceCreate(int capacity) {
  assert(capacity >= 0);
  // You must allocate space for the struct and for the intervals array!
  SchedulingSequence* ss = (SchedulingSequence*)malloc(sizeof *ss);
  if(ss != NULL){
    ss->capacity = capacity;
    ss->size = 0;
    TimeInterval** ti = (TimeInterval**)malloc(capacity * sizeof(**ti));
    ss->intervals = ti;
  }
  return ss;
}

// Destroy SchedulingSequence *pss
void SchedulingSequenceDestroy(SchedulingSequence **pss) {
  assert(*pss != NULL);
  free((*pss)->intervals);
  free(*pss);
  *pss = NULL;
}

inline int SchedulingSequenceIsEmpty(SchedulingSequence *ss) {
  return ss->size == 0;
}

inline int SchedulingSequenceIsFull(SchedulingSequence *ss) {
  return ss->size == ss->capacity;
}

// Add interval *ti to *ss.
// Return true on success,
// return false if *ti olverlaps any of the intervals in *ss.
int SchedulingSequenceAdd(SchedulingSequence *ss, TimeInterval *ti) {
  assert(!SchedulingSequenceIsFull(ss));
  int i = 0;
  while( (i < ss->size) && TimeIntervalCompare(ss->intervals[i], ti) <= 0){
    if(TimeIntervalOverlaps(ss->intervals[i], ti) > 0) return 0;
    i++;
  }

  if(i == ss->size){
    ss->intervals[i] = ti;
  }
  else {
    for (int j = ss->size ; j > i; j--){
      ss->intervals[j] = ss->intervals[j-1];
    }
    ss->intervals[i] = ti;
  }
  ss->size++;
  return 1;
}

// Get the interval at position (idx) of *ss.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval *SchedulingSequenceGet(SchedulingSequence *ss, int idx) {
  assert (0 <= idx && idx < ss->size);
  return *(ss->intervals + idx);
}

// Remove the interval at position (idx) of *ss, and return it.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval *SchedulingSequencePop(SchedulingSequence *ss, int idx) {
  assert (0 <= idx && idx < ss->size);
  // This implies !SchedulingSequenceIsEmpty(ss).
  TimeInterval* ti = (TimeInterval*) malloc(sizeof(*ti));
  ti = ss->intervals[idx];
  int i;
  for(i = idx; i < (ss->size - 1); i++){
    ss->intervals[i] = ss->intervals[i+1];
  }
  ss->size--;
  return ti;
}
