#ifndef __BUBBLESORT_TEST_HPP__
#define __BUBBLESORT_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "container.hpp"
#include "vector_container.hpp"
#include "sort.hpp"
#include "list_container.hpp"
#include "bubble_sort.hpp"
using namespace std;

TEST(BubbleSortTest, Sort_A_Simple_ListContainer) {
    // Create 4 elements to add to the vector container
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* seven = new Op(7);
    Add* additionTest = new Add(one, two); 	

    // Create an object of type VectorContainer and set the sort function 
    Container* test_container = new ListContainer(new BubbleSort());
    
    // Add the elements 7, 2, 1, 3 to the vector
    test_container->add_element(seven);
    test_container->add_element(two);
    test_container->add_element(one);
    test_container->add_element(additionTest);

    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);
    EXPECT_EQ(test_container->at(3)->evaluate(), 3);

    // Sort the container
    test_container->sort();
        
    // sort() function test
    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 3);
    EXPECT_EQ(test_container->at(3)->evaluate(), 7);
}

TEST(BubbleSortTest, Sort_A_ListContainer) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
    Mult* mult_adds = new Mult( eig_four, pi_teen);
    
    //add values
    Container* my_container = new ListContainer(new BubbleSort());
    my_container -> add_element(eight);
    my_container -> add_element(four);
    my_container -> add_element(eighteen);
    my_container -> add_element(pi);
    my_container -> add_element(eig_four);
    my_container -> add_element(pi_teen);
    my_container -> add_element(mult_adds);
    
    ASSERT_EQ(my_container->size(), 7);
    EXPECT_EQ(my_container->at(0)->evaluate(), 8);
    EXPECT_EQ(my_container->at(1)->evaluate(), 4);
    EXPECT_EQ(my_container->at(2)->evaluate(), 18);
    EXPECT_EQ(my_container->at(3)->evaluate(), 3.14);
    EXPECT_EQ(my_container->at(4)->evaluate(), 12);
    EXPECT_EQ(my_container->at(5)->evaluate(), 21.14);
    EXPECT_EQ(my_container->at(6)->evaluate(), 253.68);

    // sort the container
    my_container->sort();
    ASSERT_EQ(my_container->size(), 7);
    EXPECT_EQ(my_container->at(2)->evaluate(), 8);
    EXPECT_EQ(my_container->at(1)->evaluate(), 4);
    EXPECT_EQ(my_container->at(4)->evaluate(), 18);
    EXPECT_EQ(my_container->at(0)->evaluate(), 3.14);
    EXPECT_EQ(my_container->at(3)->evaluate(), 12);
    EXPECT_EQ(my_container->at(5)->evaluate(), 21.14);
    EXPECT_EQ(my_container->at(6)->evaluate(), 253.68);
}

TEST(BubbleSortTest, Sort_A_Simple_VectorContainer) {
    // Create 4 elements to add to the vector container
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* seven = new Op(7);
    Add* additionTest = new Add(one, two); 	

    // create an object of type VectorContainer
    VectorContainer* test_container = new VectorContainer(new BubbleSort());

    // Add the elements 7, 2, 1, 3 to the vector
    test_container->add_element(seven);
    test_container->add_element(two);
    test_container->add_element(one);
    test_container->add_element(additionTest);

    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);
    EXPECT_EQ(test_container->at(3)->evaluate(), 3);

    // sort the container
    test_container->sort();
        
    // sort() function test
    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
    EXPECT_EQ(test_container->at(2)->evaluate(), 3);
    EXPECT_EQ(test_container->at(3)->evaluate(), 7);
}

TEST(BubbleSortTest, Sort_A_VectorContainer) {
   
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
    Mult* mult_adds = new Mult( eig_four, pi_teen);
    //add values
    Container* my_container = new VectorContainer(new BubbleSort());
    my_container -> add_element(eight);
    my_container -> add_element(four);
    my_container -> add_element(eighteen);
    my_container -> add_element(pi);
    my_container -> add_element(eig_four);
    my_container -> add_element(pi_teen);
    my_container -> add_element(mult_adds);
    
    ASSERT_EQ(my_container->size(), 7);
    EXPECT_EQ(my_container->at(0)->evaluate(), 8);
    EXPECT_EQ(my_container->at(1)->evaluate(), 4);
    EXPECT_EQ(my_container->at(2)->evaluate(), 18);
    EXPECT_EQ(my_container->at(3)->evaluate(), 3.14);
    EXPECT_EQ(my_container->at(4)->evaluate(), 12);
    EXPECT_EQ(my_container->at(5)->evaluate(), 21.14);
    EXPECT_EQ(my_container->at(6)->evaluate(), 253.68);

    // sort the container
    my_container->sort();
    ASSERT_EQ(my_container->size(), 7);
    EXPECT_EQ(my_container->at(0)->evaluate(), 3.14);
    EXPECT_EQ(my_container->at(1)->evaluate(), 4);
    EXPECT_EQ(my_container->at(2)->evaluate(), 8);
    EXPECT_EQ(my_container->at(3)->evaluate(), 12);
    EXPECT_EQ(my_container->at(4)->evaluate(), 18);
    EXPECT_EQ(my_container->at(5)->evaluate(), 21.14);
    EXPECT_EQ(my_container->at(6)->evaluate(), 253.68);
}

TEST(BubbleSortTest, ListContainer_BadCallFunctionCall) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    Container* list_container = new ListContainer();
    
    list_container->add_element(TreeA);
    list_container->add_element(TreeB);
    list_container->add_element(TreeC);

    ASSERT_EQ(list_container->size(), 3);
    EXPECT_EQ(list_container->at(0)->evaluate(), 28);
    EXPECT_EQ(list_container->at(1)->evaluate(), 5);
    EXPECT_EQ(list_container->at(2)->evaluate(), 4);
        
    EXPECT_THROW(list_container->sort(), bad_function_call);
}

TEST(BubbleSortTest, VectorContainer_BadCallFunctionCall) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    Container* vector_container = new VectorContainer();

    vector_container->add_element(TreeA);
    vector_container->add_element(TreeB);
    vector_container->add_element(TreeC);
   
    ASSERT_EQ(vector_container->size(), 3);
    EXPECT_EQ(vector_container->at(0)->evaluate(), 28);
    EXPECT_EQ(vector_container->at(1)->evaluate(), 5);
    EXPECT_EQ(vector_container->at(2)->evaluate(), 4);
    
    EXPECT_THROW(vector_container->sort(), bad_function_call);
}

#endif //__BUBBLESORT_TEST_HPP__
                                                           

