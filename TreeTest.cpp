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
	mytree.insert(25);
	mytree.insert(15);
	mytree.insert(35);
	mytree.insert(11);
	mytree.insert(40);
	mytree.insert(17);
	mytree.insert(33);

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

		.CHECK_EQUAL(threetree.size(), 3)
		.CHECK_EQUAL(threetree.root(), 5)
		.CHECK_EQUAL(threetree.parent(3), 5)
		.CHECK_EQUAL(threetree.parent(7), 5)
		.CHECK_EQUAL(threetree.left(5), 3)
		.CHECK_EQUAL(threetree.right(5), 7)
		.CHECK_THROWS(threetree.insert(3))
		.CHECK_THROWS(threetree.left(6))
		.CHECK_OK(threetree.print())
		.print()

		.CHECK_EQUAL(mytree.size(), 7)
		.CHECK_EQUAL(mytree.root(), 25)
		.CHECK_EQUAL(mytree.left(25), 15)
		.CHECK_EQUAL(mytree.right(15), 17)
		.CHECK_THROWS(mytree.insert(25))
		.CHECK_THROWS(mytree.remove(3))
		.CHECK_OK(mytree.remove(15))
		.CHECK_OK(mytree.remove(17))
		.CHECK_EQUAL(mytree.size(), 5)
		.CHECK_EQUAL(mytree.contains(35), true)
		.CHECK_EQUAL(mytree.contains(5), false)
		.CHECK_OK(mytree.print())
		.CHECK_EQUAL(mytree.parent(33), 35)
		.print();



	cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}