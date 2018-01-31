#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){ /*your code here*/

}

/**
 * Inserts a new node in position one of the Chain,
 * after the sentinel node.
 * This function **SHOULD** create a new Node.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertFront(const Block & ndata){
/* your code here! */
}

/**
 * Inserts a new node at the back of the Chain,
 * but before the tail sentinel node.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
   /* your code here! */
}

/**
 * Modifies the Chain by moving a contiguous subset of Nodes to
 * the end of the chain. The subset of len nodes from (and
 * including) startPos are moved so that they
 * occupy the last len positions of the
 * chain (maintaining the sentinel at the end). Their order is
 * not changed in the move.
 */
void Chain::moveToBack(int startPos, int len){
   /* your code here! */
}

/**
 * Rotates the current Chain by k nodes: removes the first
 * k nodes from the Chain and attaches them, in order, at
 * the end of the chain (maintaining the sentinel at the end).
 */
void Chain::rotate(int k){
   /* your code here! */
}

/**
 * Modifies the current chain by swapping the Node at pos1
 * with the Node at pos2. the positions are 1-based.
 */
void Chain::swap(int pos1, int pos2){
   /*your code here */
}

/*
 *  Modifies both the current and input chains by trading
 * nodes in even positions between the chains. Length
 * of each chain should stay the same. If the block dimensions
 * are NOT the same, the funtion has no effect and a simple
 * error message is output: cout << "Block sizes differ." << endl;
 */

void Chain::twist(Chain & other){
   /* Your code here. */
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() {
   /*your code here*/
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {
   /* your code here! */
}
