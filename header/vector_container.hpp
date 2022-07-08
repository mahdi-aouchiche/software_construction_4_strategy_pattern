#ifndef __VECTOR_CONTAINER_HPP__ 
#define __VECTOR_CONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"
#include <vector>
#include <iostream>
#include <list>
#include "functional"

using namespace std;

class VectorContainer : public Container 
{
    private:
    // Vector of expression tree pointers
    vector<Base* > vector_container; 
	
    public:
    /* Constructors */
    VectorContainer(): Container() {}	
	VectorContainer(Sort* function){ 
        this->sort_function = function; 
    }

    /* push the top pointer of the tree into container */
    virtual void add_element(Base* element) {
        this->vector_container.push_back(element);
    }
      	
	/* iterate through trees and output the expressions (use stringify()) */
	virtual void print() {
	    for(unsigned i = 0; i < vector_container.size(); ++i) {
			cout << vector_container.at(i)->stringify() << endl;
		}	
    }
	
	// calls on the previously set sorting-algorithm.
	// Checks if sort_function is not null, throw exception if otherwise
    virtual void sort() {
       	if(!this->sort_function) {
           	//throw bad_function_call("Sorting-algorithm is not set.");
            throw bad_function_call();
        }
	    sort_function->sort(this);
    }

    /* Essentially the only functions needed to sort */
	//switch tree locations
	virtual void swap(int i, int j) {
	    // save element at i
	    Base* temp = vector_container.at(i);
	    // Replace element at i with element in
        this->vector_container.at(i) = this->vector_container.at(j);
        // assign saves element in j
        this->vector_container.at(j) = temp;
    }         		

	// get top ptr of tree at index i
	virtual Base* at(int i) {
       	return this->vector_container.at(i);
    }
	
    // return container size
    virtual int size() {
      	return this->vector_container.size();
    }
};

#endif //__VECTOR_CONTAINER_HPP__