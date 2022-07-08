#ifndef __SELECTION_SORT_TEST_HPP__
#define __SELECTION_SORT_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "sort.hpp"
#include "container.hpp"
#include "vector_container.hpp"
#include "list_container.hpp"
using namespace std; 


TEST(SelectionSortTest, Sort_A_Simple_ListContainer) {
    // Create 4 elements to add to the vector container
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* seven = new Op(7);
    Add* additionTest = new Add(one, two); 	

    // create an object of type VectorContainer
    ListContainer* test_container = new ListContainer();

    // Add the elements 7, 2, 1, 3 to the vector
    test_container->add_element(seven);
    test_container->add_element(two);
    test_container->add_element(one);
    test_container->add_element(additionTest);

    // set the sort algotithm and call the sort function
    Sort* sort_function = new SelectionSort(); 
    test_container->set_sort_function(sort_function);
    test_container->sort();
        
    // sort() function test
    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 3);
    EXPECT_EQ(test_container->at(3)->evaluate(), 7);
}

TEST(SelectionSortTest, Sort_A_ListContainer) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SelectionSortTest, Sort_A_Simple_VectorContainer) {
    // Create 4 elements to add to the vector container
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* seven = new Op(7);
    Add* additionTest = new Add(one, two); 	

    // create an object of type VectorContainer
    VectorContainer* test_container = new VectorContainer();

    // Add the elements 7, 2, 1, 3 to the vector
    test_container->add_element(seven);
    test_container->add_element(two);
    test_container->add_element(one);
    test_container->add_element(additionTest);

    // set the sort algotithm and call the sort function
    Sort* sort_function = new SelectionSort(); 
    test_container->set_sort_function(sort_function);
    test_container->sort();
        
    // sort() function test
    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 3);
    EXPECT_EQ(test_container->at(3)->evaluate(), 7);
}

TEST(SelectionSortTest, Sort_A_VectorContainer) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer(new SelectionSort());
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    // container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

#endif //__SELECTION_SORT_TEST_HPP__
