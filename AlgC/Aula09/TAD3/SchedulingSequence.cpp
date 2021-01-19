//NMEC: ...
//NOME: ...
//
// João Manuel Rodrigues, AlgC, May 2020
//
// A SchedulingSequence based on a SORTED LIST.

//// PROCURE ... E COMPLETE ////

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SchedulingSequence.h"

// You may add auxiliary definitions and declarations here, if you need to.



// Comparison function to be used in generic SortedList.
static int cmpTI(const void* a, const void* b) {
  return TimeIntervalCompare((TimeInterval*)a, (TimeInterval*)b);
}

// Create a SchedulingSequence capable of storing intervals.
// (Argument capacity is ignored!)
SchedulingSequence* SchedulingSequenceCreate(int capacity) {
  assert(capacity >= 0);
  // You must allocate space for the struct and create an empty intervals list!
  SchedulingSequence* pss = (SchedulingSequence*)malloc(sizeof *pss);
  if(pss != NULL){
    pss->size=0;
    struct _SortedList* sl = (struct _SortedList*)malloc(sizeof sl);
    sl = ListCreate(cmpTI);
    pss->intervals = sl;
  }
  return pss;
}

// Destroy SchedulingSequence *pss
void SchedulingSequenceDestroy(SchedulingSequence **pss) {
  assert(*pss != NULL);
  ListDestroy(&(*pss)->intervals);
  free(*pss);
  *pss = NULL;
}

int SchedulingSequenceIsEmpty(SchedulingSequence *ss) {
  return ss->size == 0;
}

int SchedulingSequenceIsFull(SchedulingSequence *ss) {
  return 0;  // NEVER Full!
}

// Add interval *ti to *ss.
// Return true on success,
// return false if *ti overlaps any of the intervals in *ss.
int SchedulingSequenceAdd(SchedulingSequence *ss, TimeInterval *ti) {
  assert(!SchedulingSequenceIsFull(ss));
  struct _SortedList* sl = ss->intervals;
  ListMoveToHead(sl);
  while(ListGetCurrentPos(sl) != -1){
    if(TimeIntervalOverlaps((TimeInterval*)ListGetCurrentItem(sl),ti)==1) return 0;
    ListMoveToNext(sl);
  }
  ListInsert(sl,ti);
  ss->size++;
  return 1;
}

// Get the interval at position (idx) of *ss.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval* SchedulingSequenceGet(SchedulingSequence *ss, int idx) {
  assert (0 <= idx && idx < ss->size);
  struct _SortedList* sl = ss->intervals;
  ListMoveToHead(sl);
  //while(ListGetCurrentPos(sl) != -1){
  for(int i = 0; i < ss-> size; i++){
    if(ListGetCurrentPos(sl) == idx){
      return (TimeInterval*)ListGetCurrentItem(sl);
    }
    ListMoveToNext(sl);
  }
  return NULL;
}
// Remove the interval at position (idx) of *ss, and return it.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval* SchedulingSequencePop(SchedulingSequence *ss, int idx) {
  assert (0 <= idx && idx < ss->size);
  // This implies !SchedulingSequenceIsEmpty(ss).
  assert(!SchedulingSequenceIsEmpty(ss));
  struct _SortedList* sl = ss->intervals;
  ListMoveToHead(sl);
  while(ListGetCurrentPos(sl) != -1){
    if(ListGetCurrentPos(sl) == idx){
      ss->size--;
      return (TimeInterval*)ListRemoveCurrent(sl);

    }
    ListMoveToNext(sl);
  }
  return NULL;
}

// You may add auxiliary definitions and declarations here, if you need to.
