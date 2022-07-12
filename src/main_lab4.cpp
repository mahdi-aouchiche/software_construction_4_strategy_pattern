#include <iostream>
#include "../header/base.hpp"
#include "../header/op.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/pow.hpp"
#include "../header/rand.hpp"
#include "../header/container.hpp"
#include "../header/sort.hpp"
#include "../header/list_container.hpp"
#include "../header/vector_container.hpp"
#include "../header/bubble_sort.hpp"
#include "../header/selection_sort.hpp"
using namespace std;

int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);
    
    Container* vec_cont = new VectorContainer();
    vec_cont->add_element(three);
    vec_cont->add_element(seven);
    vec_cont->add_element(four);
    vec_cont->add_element(two);
    vec_cont->add_element(mult);
    vec_cont->add_element(add);
    vec_cont->add_element(minus);

    Sort* sort_function = new BubbleSort();
    vec_cont->set_sort_function (sort_function);
    vec_cont->sort();
    cout << "Vector container with Bubble sort: \n";
    vec_cont->print();

    Container* list_cont = new ListContainer(new SelectionSort());
    list_cont->add_element(three);
    list_cont->add_element(seven);
    list_cont->add_element(four);
    list_cont->add_element(two);
    list_cont->add_element(mult);
    list_cont->add_element(add);
    list_cont->add_element(minus);
    list_cont->sort();
    cout << "\nList container with Selection sort: \n";
    list_cont->print();

    return 0;
}
