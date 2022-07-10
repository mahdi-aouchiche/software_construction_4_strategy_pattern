#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "sort.hpp"
#include "container.hpp"

class BubbleSort : public Sort {
     
    public:
	/* Constructors */
    BubbleSort(): Sort() { }

    /* Pure Virtual Functions */
    virtual void sort(Container* container) {
		// set flag to true to start first pass
		bool flag = true;   
     	
		// go through the container
     	for(int i = 1; (i <= container->size()) && flag; i++){
       		flag = false;

			// go through the container
         	for (int j=0; j < (container->size() -1); j++){

				// for descending order simply changes to >
            	if (container->at(j+1)->evaluate() < container->at(j)->evaluate()) {    
            		
					// do a swap 
					container->swap(j,j+1);

					// indicates that a swap occurred.
            		flag = true;               
            	}
			}
        } 
	} 
};

#endif //__BUBBLE_SORT_HPP__

