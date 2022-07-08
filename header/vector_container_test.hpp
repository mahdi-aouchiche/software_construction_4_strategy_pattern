#ifndef __VECTOR_CONTAINER_TEST_HPP__
#define __VECTOR_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "sort.hpp"
#include "container.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "vector_container.hpp"
#include "selection_sort.hpp"
using namespace std;


TEST(VectorContainerTestSet, SizeTest) {
   // Setup the elements under test
   Op* seven = new Op(7);
   Op* one = new Op(1);
   Op* two = new Op(2);
        
   // Create a VectorContainer object and ptr with test-container
   VectorContainer* test_container = new VectorContainer();
        
   // Add the elements 7, 1, 2 to the vector
   test_container->add_element(seven);
   test_container->add_element(one);
   test_container->add_element(two);
      
   // Assert that the container has 3 element
   // otherwise we are likely to cause a segfault when accessing
   ASSERT_EQ(test_container->size(), 3);
        
   // Check the add_element function if working properly
   EXPECT_EQ(test_container->at(0)->evaluate(), 7);
   EXPECT_EQ(test_container->at(1)->evaluate(), 1);
   EXPECT_EQ(test_container->at(2)->evaluate(), 2);
}

TEST(VectorContainerTestSet, SwapTest) {
   // Create 2 elements to add to the vector container
   Op* one = new Op(1);
   Op* two = new Op(2);

   // create an object of type VectorContainer
   VectorContainer* test_container = new VectorContainer();

   // Add the elements 1, 2 to the vector
   test_container->add_element(one);
   test_container->add_element(two);

   // Check correct elements order 
   EXPECT_EQ(test_container->at(0)->evaluate(), 1);
   EXPECT_EQ(test_container->at(1)->evaluate(), 2);

   // Call the swap function (swap elements at 0 and 1)
   test_container->swap(0,1);

   // swap function should swap test_container from {1,2} to {2,1}
   ASSERT_EQ(test_container->size(), 2);
   EXPECT_EQ(test_container->at(0)->evaluate(), 2);
   EXPECT_EQ(test_container->at(1)->evaluate(), 1);
}

TEST(VectorContainerTestSet, AtFunctionTest) {
   // Create 3 elements to add to the vector container
   Op* one = new Op(1);
   Op* two = new Op(2);
   Op* seven = new Op(7);
   Add* additionTest = new Add(one, two);
        
   // create an object of type VectorContainer
   VectorContainer* test_container = new VectorContainer();

   // Add the elements 1, 2, 7, 3 to the vector
   test_container->add_element(one);
   test_container->add_element(two);
   test_container->add_element(seven);
   test_container->add_element(additionTest);	

   // At function test
   ASSERT_EQ(test_container->size(), 4);
   EXPECT_EQ(test_container->at(0)->evaluate(), 1);
   EXPECT_EQ(test_container->at(1)->evaluate(), 2);
   EXPECT_EQ(test_container->at(2)->evaluate(), 7);
   EXPECT_EQ(test_container->at(3)->evaluate(), 3);
}

TEST(VectorContainerTestSet, PrintTest) {
   // Create 3 elements to add to the vector container
   Op* one = new Op(1);
   Op* two = new Op(2);
   Op* seven = new Op(7);
   Add* additionTest = new Add(one, two);	

   // create an object of type VectorContainer
   VectorContainer* test_container = new VectorContainer();

   // Add the elements 1, 2, 7, 3 to the vector
   test_container->add_element(one);
   test_container->add_element(two);
   test_container->add_element(seven);
   test_container->add_element(additionTest);

   // Using cout to test the Print function
   test_container->print();

   // container size should be 4
   ASSERT_EQ(test_container->size(), 4);
   cout << "Expect element at(0) = 1, print() test is: " << test_container->at(0)->stringify()
        << "(" << test_container->at(0)->evaluate() << ")" << endl
        << "Expect element at(1) = 2, print() test is: " << test_container->at(1)->stringify()
        << "(" << test_container->at(1)->evaluate() << ")" << endl
        << "Expect element at(2) = 7, print() test is: " << test_container->at(2)->stringify()
        << "(" << test_container->at(2)->evaluate() << ")" << endl
        << "Expect element at(3) = 3, print() test is: " << test_container->at(3)->stringify()
        << "(" << test_container->at(3)->evaluate() << ")" << endl;
}

TEST(VectorContainerTestSet, SortTestWithNoSortFunction) {
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

    ASSERT_EQ(test_container->size(), 4);

    // call the sort function without sort algotithm 
    // sort() function test
    EXPECT_THROW(test_container->sort(), bad_function_call);
}

#endif // __VECTOR_CONTAINER_TEST_HPP__

