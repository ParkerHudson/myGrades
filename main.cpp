/*
By Gregory Hudson
Fall semester 2019 - COP 3530
Program that implements the requirements of homework 
*/

#include "MyGrades.h"
#include <iostream>
bool isSame(double x, double y);
int main(void)
{
	// Put your name in the statement below
	std::cout << "Homework 1 test case results by Gregory Hudson" << std::endl;

	// test cases for default constructor
	int testCount = 1;  // used to track test numbers
	MyGrades a;
	bool result;
	result = isSame(0, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test cases for setMidtermExam()
	a.setMidtermExam(80);
	result = isSame(24, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test cases for setFinalExam()
	a.setFinalExam(81);
	result = isSame(56.4, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test cases for setHomework()
	a.setHomework(80);
	result = isSame(80.4, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	a.setHomework(90);
	result = isSame(81.9, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	a.setHomework(100);
	result = isSame(83.4, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	a.setHomework(100);
	result = isSame(84.15, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test copy constructor
	MyGrades b(a);
	result = isSame(84.15, b.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test copy constructor for shallow copy
	MyGrades h(a);
	h.setHomework(82);
	b.setHomework(100);
	result = isSame(83.52, h.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test assignment operator
	MyGrades c;
	c = h;
	result = isSame(83.52, c.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test assignment operator for shallow copy
	c.setHomework(70);
	h.setHomework(100);
	result = isSame(82.5, c.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test assignment operator for self-assignment
	a = a;
	result = isSame(84.15, a.getFinalGrade());
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test the equality operator
	if ((a == a) == 1)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	if ((b == a) == 0)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	if ((c == a) == 0)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	MyGrades d(a);
	d.setHomework(84);
	if ((d == a) == false)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// test getGradeNeededOnFinal(double desiredGrade)
	MyGrades e;
	e.setMidtermExam(80);
	e.setHomework(85);
	result = isSame(96.25, e.getGradeNeededOnFinal(88));
	if (result == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	return 0;
}

bool isSame(double x, double y)
{
	double error = .00001;
	bool rv = false;
	if (((x + error) >= y) && ((x - error) <= y))
	{
		rv = true;
	}
	return rv;
}





