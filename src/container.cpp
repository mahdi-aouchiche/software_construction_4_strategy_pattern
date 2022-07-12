#include "../header/container.hpp"

/* Implementation of the set sort function to set the type of sorting algorithm */
void Container::set_sort_function(Sort* sort_function) { 
	/* set the type of sorting algorithm */
	this->sort_function = sort_function;
}
