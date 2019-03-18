/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.insert(8))
  .CHECK_OK    (threetree.insert(-3))
  .CHECK_OK    (threetree.insert(7.5))
  .CHECK_OK    (threetree.insert(0))
  .CHECK_EQUAL (threetree.size(), 7)
  .CHECK_EQUAL (threetree.parent(7.5), 8)
  .CHECK_EQUAL (threetree.parent(0), -3)
  //.CHECK_OK    (threetree.print())


  .CHECK_OK(threetree.remove(0)) // leaf
  .CHECK_EQUAL(threetree.contains(0),false) // leaf

  .CHECK_OK(threetree.remove(3)) // one child
  .CHECK_EQUAL(threetree.contains(3),false) // one child

  .CHECK_OK(threetree.remove(5)) // two child
  .CHECK_EQUAL(threetree.contains(5),false) // two child

  .CHECK_THROWS(threetree.insert(8))
  .CHECK_OK    (threetree.print())

  
  
  
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

