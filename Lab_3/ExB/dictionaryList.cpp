/*
*	File Name: dictionaryList.cpp
*	Assignment Lab 2 exercise A
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Oct 1st 2021
*/

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring2.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}







void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
  Node* search = headM;

  while (search != 0) {
      if (search->keyM == keyA) {
          cursorM = search;
          return;
      }
      search = search->nextM;
  }

  cursorM = 0;
}


void DictionaryList::destroy()
{
   if (headM == 0) {
        return;
    }

    Node* destroy = headM;
    Node* next;

    while (destroy->nextM != 0) {
        next = destroy->nextM;
        delete destroy;
        destroy = next;
    }
    delete destroy;
    headM = 0;
}


void DictionaryList::copy(const DictionaryList& source)
{
    headM = 0;
    Node* Src = source.headM;

    while (Src != 0) {
        insert(Src->keyM, Src->datumM); //use insert to copy each node.
        Src = Src->nextM;
    }

    Node* search = headM;

    if (source.cursorM != NULL) {
        while (search != 0) {
            if (search->keyM == source.cursorM->keyM) {
                cursorM = search;
            }
            search = search->nextM;
        }
    }
 
}

// overloading operator of "<<" so that it is able to print out a name associated with it.
ostream& operator <<(ostream &os, const Mystring &cursorM){
	
	//Check if there is a name under datumM.
	//If there is no name then we will print out NULL.
	if(cursorM.length() == 0){
		return os << "";
	}
	int i = 0;
	//If there is a name then we will print the name out.
	//This will now point to the first character in the name.
	std::string name = "";
	
	while(cursorM.get_char(i) != '\0'){
		name = name + (cursorM.get_char(i));
		i++;
	}
	name = name + (cursorM.get_char(i));
	
	//Name is now filled up with the whatever is in charsM.
	//Now we can print it out into cout.
	
	return os << name;
		
}


//overloading operator of "<<" so that is is able to print out just the name.

ostream& operator <<(ostream &os, DictionaryList &dl){
	
	dl.go_to_first();
	
	const char * namePtr;
	std::string name = "";

	while(dl.cursorM != NULL){
		namePtr = dl.cursor_datum().c_str();
		name = name + to_string(dl.cursor_key()) + "	";
		while((*namePtr) != '\0'){
			name = name + (*namePtr);
			namePtr++;
		}
		name = name + "\n";
		dl.step_fwd();
	}
	return os << name;
}

const Mystring& DictionaryList::operator [] (int i){
	
	
	(*this).go_to_first();
	
	for(int j = 0; j < i || !cursor_ok() ; j++){
		(*this).step_fwd();
	}
	if(!cursor_ok()){
		return Mystring();
	}
	
	return (*this).cursor_datum();
}



//overloading operator of ">=" so that it is able to print so that it is able to compare the name lengths.
bool operator >= (const Datum& cursorM1 , const Datum& cursorM2){
	return (cursorM1.length() >= cursorM2.length());
}

//overloading operator of "<=" so that it is able to print so that it is able to compare the name lengths.
bool operator <= (const Datum& cursorM1 , const Datum& cursorM2){
	return cursorM1.length() <= cursorM2.length();
}

bool operator != (const Datum& cursorM1, const Datum& cursorM2){
	return cursorM1.length() != cursorM2.length();
}

bool operator > (const Datum& cursorM1, const Datum& cursorM2){
	return cursorM1.length() > cursorM2.length();
}

bool operator < (const Datum& cursorM1, const Datum& cursorM2){
	return cursorM1.length() < cursorM2.length();
}

bool operator == (const Datum& cursorM1, const Datum& cursorM2){
	return cursorM1.length() == cursorM2.length();
}
