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

	ariel::Tree mytree;

	badkan::TestCase tc("Binary tree");
	tc
		.CHECK_EQUAL(emptytree.size(), 0)
		.CHECK_OK(emptytree.insert(5))
		.CHECK_EQUAL(emptytree.size(), 1)
		.CHECK_EQUAL(emptytree.contains(5), true)
		.CHECK_OK(emptytree.remove(5))
		.CHECK_EQUAL(emptytree.contains(5), false)
		.CHECK_THROWS(emptytree.remove(5))
		.CHECK_EQUAL(emptytree.size(), 0)
		.CHECK_OK(emptytree.insert(5))
		.CHECK_OK(emptytree.insert(10))
		.CHECK_OK(emptytree.insert(2))
		.CHECK_EQUAL(emptytree.root(), 5)
		.CHECK_OK(emptytree.insert(15))
		.CHECK_EQUAL(emptytree.right(10), 15)
		.CHECK_OK(emptytree.remove(10))
		.CHECK_EQUAL(emptytree.right(5), 15)
		.CHECK_EQUAL(emptytree.size(), 3)
		.CHECK_THROWS(emptyree.parent(5))

		.CHECK_EQUAL(threetree.size(), 3)
		.CHECK_EQUAL(threetree.root(), 5)
		.CHECK_EQUAL(threetree.parent(3), 5)
		.CHECK_EQUAL(threetree.parent(7), 5)
		.CHECK_EQUAL(threetree.left(5), 3)
		.CHECK_EQUAL(threetree.right(5), 7)
		.CHECK_THROWS(threetree.insert(3))
		.CHECK_THROWS(threetree.left(6))
		.CHECK_OK(threetree.print())
		.CHECK_OK(threetree.insert(9))
		.CHECK_EQUAL(threetree.right(7), 9)
		.CHECK_OK(threetree.remove(7))
		.CHECK_EQUAL(threetree.right(5), 9)
		.CHECK_THROWS(threetree.left(9))
		.CHECK_OK(threetree.remove(5))
		.CHECK_EQUAL(threetree.root(9))
		.CHECK_OK(threetree.remove(9))
		.CHECK_OK(threetree.remove(3))
		.CHECK_EQUAL(threetree.size(), 0)
		.CHECK_THROWS(threetree.root())
		.CHECK_THROWS(threetree.contains(5))

		.print();

	cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;