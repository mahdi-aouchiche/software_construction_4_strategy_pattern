#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include <iostream>
#include <functional>
#include "base.hpp"
#include "sort.hpp"
#include <list>
using namespace std;

class SelectionSort;
class BubbleSort;

class ListContainer : public Container 
{
    private:
    list<Base *> list_container;
		
	public:
    /* Constructors */
	ListContainer() { };
    ListContainer(Sort* function) {
	    this->sort_function = function;
	};
		
	/* implement pure virtual functions of the Container class */
	void add_element(Base* element){
		this->list_container.push_back(element);
	};
	
    Base* at(int i){
        // if element at i is out of range, then return null
        if((i < 0) || (i >= this->list_container.size())) return NULL;

        // start a list iterator at the head of the list container
        list<Base *>::iterator iterator = this->list_container.begin();

        // iterate to the i-th element in the list container
		for(int j = 0; (j < i); ++j, ++iterator);

        // retrun the i-th element in the list container
        return *iterator;
    };
        
    int size(){
		return this->list_container.size();
	};

    void sort(){
        if(!this->sort_function) {
           	//throw bad_function_call("Sorting-algorithm is not set.");
            throw bad_function_call();
        }
	    this->sort_function->sort(this);
	}
	
    void set_sort_function(Sort* function){
		this->sort_function = function;
    }
	
    void print(){

        list <Base* >::iterator it;
		for(it = this->list_container.begin(); it != this->list_container.end(); ++it){
			cout <<(*it) -> stringify() << "\n";
		}
	};
	
    void swap (int i, int j){
		// save both i-th and j-th elements from the list container to a temp variables
        Base* element_at_i = this->at(i) ;
		Base* element_at_j = this->at(j);

        list<Base *>::iterator it = this->list_container.begin();
        for(int k = 0; (k <= i) || (k <= j); ++k, ++it){
            
            if(k == i){
                *it = element_at_j;
            }
            if(k == j){
                *it = element_at_i;
            }
        }
	};
};

#endif //__LISTCONTAINER_HPP__
