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
    Node *insertNode = Node(ndata);
    Node *temp = head_->next; 

    head_->next = insertNode;
    insertNode->prev = head_;

    insertNode->next = temp;
    temp->prev = insertNode;

    length_ += 1;
}

/**
 * Inserts a new node at the back of the Chain,
 * but before the tail sentinel node.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
   Node *insertNode = Node(ndata);
   Node *temp = tail_->prev;

   temp->next = insertNode;
   insertNode->prev = temp;

   insertNode->next = tail_;
   tail->prev = insertNode;

   length_+=1;
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
    Node *curr = head->next;
    // int endPos = startPos + len - 1;
    for(int index = 0; index < startPos; index++){
        curr = curr->next;
    }
    if(len <= 0){
        return;
    }
    else if(len == 1){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        
        Node *temp = tail_->prev;
        temp->next = curr;
        curr->prev = temp;

        curr->next = tail_;
        tail_->prev = curr;
    }
    else{
        Node *moveEnd = curr;
        for(int i = 0; i < len - 1; i++){
            moveEnd = moveEnd->next;
        }
        curr->prev->next = moveEnd->next;
        moveEnd->next->prev = curr->prev;

        Node tailPrev = tail_->prev;

        tailPrev->next = curr;
        curr->prev = tailPrev;

        tail_->prev = moveEnd;
        moveEnd->next = tail_;
    }
}

/**
 * Rotates the current Chain by k nodes: removes the first
 * k nodes from the Chain and attaches them, in order, at
 * the end of the chain (maintaining the sentinel at the end).
 */
void Chain::rotate(int k){
    moveToBack(0, k);
}

/**
 * Modifies the current chain by swapping the Node at pos1
 * with the Node at pos2. the positions are 1-based.
 */
void Chain::swap(int pos1, int pos2){
    Node *position1 = head_->next;
    Node *position2 = head_->next;

    for(int index1 = 0; index1 < pos1; index1++){
        position1 = position1->next;
    }
    for(int index2 = 0; index2 < pos2; index2++){
        position2 = position2->next;
    }

    Node *pos1Prev = position1->prev;
    Node *pos2Prev = position2->prev;

    Node *pos1Next = position1->next;
    Node *pos2Next = position2->next;

    // removing the nodes from the chain
    position1->prev->next = position1->next;
    position1->next->prev = position1->prev;

    position2->prev->next = position2->next;
    position2->next->prev = position2->prev;

    // re-inserting node 2 
    pos1Prev->next = position2;
    position2->prev = pos1Prev;

    position2->next = pos1Next;
    pos1Next->prev = position2;

    // re-inserting node 1 
    pos2Prev->next = position1;
    position1->prev = pos2Prev;

    position1->next = pos2Next;
    pos2Next->prev = position1;
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
