#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "list_container.hpp"
#include "base.hpp"
#include "sort.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"

TEST(ListContainerTest, ListInputValues_op){
	Op* eight = new Op(8);
	Op* four = new Op(4);
	Op* eighteen = new Op(18);
	Op* pi = new Op(3.14);
	//add values
	Container* conta = new ListContainer();
	conta -> add_element(eight);
	conta -> add_element(four);
	conta -> add_element(eighteen);
	conta -> add_element(pi);
	
	//check print function
	//conta -> print();

	//check elements in equation
	EXPECT_EQ(conta->at(2)->stringify(), "18.000000" );
    EXPECT_EQ(conta->at(3)->evaluate(), 3.14);
}

TEST(ListContainerTest, ListInputValues_add){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
	Add* eig_four = new Add(eight, four);
	Add* pi_teen = new Add(pi, eighteen);

    //add values
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
	conta -> add_element(eig_four);
	conta -> add_element(pi_teen);

    //check print function
    //conta -> print();

    //check elements in equation
    EXPECT_EQ(conta->at(5)->stringify(), "3.140000 + 18.000000" );
}

TEST(ListContainerTest, ListPrintValues){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
	Mult* mult_adds = new Mult( eig_four, pi_teen);
    
    //add values
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
    conta -> add_element(eig_four);
    conta -> add_element(pi_teen);
	conta -> add_element(mult_adds);

    //check print function
    /* cout << "Manually check that 8, 4, 18, 3.14, 8 + 4, 3.14 + 18, 8 + 4 * 3.14 + 18 
       show up with 6 decimal places and each shows up in new line \n";
    */
	conta -> print();

    //check elements in equation
    //EXPECT_EQ(conta->at(5)->stringify(), "3.140000 + 18.000000" );
	cout << "EXPECT Element at(0) = 8.000000 \t Output is = " << conta->at(0)->stringify() << "\n";
    cout << "EXPECT Element at(1) = 4.000000 \t Output is = " << conta->at(1)->stringify() << "\n";
	cout << "EXPECT Element at(2) = 18.000000 \t Output is = " << conta->at(2)->stringify() << "\n";
	cout << "EXPECT Element at(3) = 3.140000 \t Output is = " << conta->at(3)->stringify() << "\n";
	cout << "EXPECT Element at(4) = 8.000000 + 4.000000 \t Output is = " << conta->at(4)->stringify() << "\n";
	cout << "EXPECT Element at(5) = 3.140000 + 18.000000 \t Output is = " << conta->at(5)->stringify() << "\n";
	cout << "EXPECT Element at(6) = 8.000000 + 4.000000 * 3.140000 + 18.000000 \t Output is = " << conta->at(6)->stringify() << "\n";
}

TEST(ListContainerTest, ListSwapValues){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
    Mult* mult_adds = new Mult( eig_four, pi_teen);
    //add values
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
    conta -> add_element(eig_four);
    conta -> add_element(pi_teen);
    conta -> add_element(mult_adds);
	conta -> swap (0, 1);

    //check elements in equation
    EXPECT_EQ(conta->at(0)->evaluate(), 4 );
	EXPECT_EQ(conta->at(1)->evaluate(), 8);
}

TEST(ListContainerTest, ListSwapValues_end){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
    Mult* mult_adds = new Mult( eig_four, pi_teen);
    
    //add values
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
    conta -> add_element(eig_four);
    conta -> add_element(pi_teen);
    conta -> add_element(mult_adds);
    conta -> swap (6, 5);

    //check elements in equation
    EXPECT_EQ(conta->at(6)->stringify(), "3.140000 + 18.000000" );
	EXPECT_EQ(conta->at(5)->stringify(), "(8.000000 + 4.000000) * (3.140000 + 18.000000)");
}

TEST(ListContainerTest, AtFunction){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
    Mult* mult_adds = new Mult( eig_four, pi_teen);
    
    //add values
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
    conta -> add_element(eig_four);
    conta -> add_element(pi_teen);

    //check elements in list to make sure that when addressed the vlaues are good
    EXPECT_EQ(conta->at(5)->stringify(), "3.140000 + 18.000000" );
	EXPECT_EQ(conta->at(1)->evaluate(), 4);
	EXPECT_EQ(conta->at(0)->evaluate(), 8);
}

TEST(ListContainerTest, Size){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    Add* eig_four = new Add(eight, four);
    Add* pi_teen = new Add(pi, eighteen);
    Mult* mult_adds = new Mult( eig_four, pi_teen);
    
    //add values to container
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
    conta -> add_element(eig_four);
    conta -> add_element(pi_teen);

    //check size
    EXPECT_EQ(conta->size(), 6 );
}

TEST(ListContainerTest, List_No_SortFunction ){
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Op* eighteen = new Op(18);
    Op* pi = new Op(3.14);
    //add values
    Container* conta = new ListContainer();
    conta -> add_element(eight);
    conta -> add_element(four);
    conta -> add_element(eighteen);
    conta -> add_element(pi);
    
    // Test for failure
	EXPECT_THROW(conta ->sort(), bad_function_call);
}

#endif //__LISTCONTAINER_TEST_HPP__