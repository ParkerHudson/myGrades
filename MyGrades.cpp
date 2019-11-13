/*
By
Fall 2019 - COP 3530

*/
#include "MyGrades.h"
#include <new>
#include <iostream>
// The default constructor will initialize test scores to 0 and allocate any 
// memory necessary. The homework array size will be the size of DEFAULT_NUM_HW.
// The number of homeworks is initially 0.
MyGrades::MyGrades() : numberOfOHomeworks(0), midtermExam(0), finalExam(0)
{
	maxNumberOfOHomeworks = DEFAULT_NUM_HW;
	hw = new int[DEFAULT_NUM_HW];
}
// Provide the Copy constructor implementation only if needed
MyGrades::MyGrades(const MyGrades &org) : numberOfOHomeworks(org.numberOfOHomeworks), midtermExam(org.midtermExam), finalExam(org.finalExam), maxNumberOfOHomeworks(org.maxNumberOfOHomeworks)
{
	hw = new int[maxNumberOfOHomeworks];
	for (int i = 0; i < numberOfOHomeworks; i++)
	{
		hw[i] = org.hw[i];
	}
}
// Provide the destructor implementation only if needed
MyGrades::~MyGrades()
{
	delete [] hw;
}
// This member function sets the final grade.
void MyGrades::setFinalExam(int grade)
{
	finalExam = grade;
}
// This member function sets the midterm grade.
void MyGrades::setMidtermExam(int grade)
{
	midtermExam = grade;
}
// add a homework grade to the hw array. If the current homework grade
// overruns the array then allocate a larger array to accomodate that 
// homework grade. Be sure not to create a memory leak.
void MyGrades::setHomework(int grade)
{
	if (numberOfOHomeworks == maxNumberOfOHomeworks)
	{ // if there is not enough capacity in the array then
		int *temp = new int[maxNumberOfOHomeworks + DEFAULT_NUM_HW];
		for (int i = 0; i < numberOfOHomeworks; i++)
		{ // copy the current hw grades to the temp array
			temp[i] = hw[i];
		}
		delete[] hw; // deallocate the old array
		hw = temp; // reposition the new array
		maxNumberOfOHomeworks = maxNumberOfOHomeworks + DEFAULT_NUM_HW;
	}
	hw[numberOfOHomeworks] = grade;
	numberOfOHomeworks++;
}
// return the weighted average grade using the weights provided in the .h file.
// if a test is not taken that test is considered a 0. If there are no homework assignments
// then the homework assignment portion is considered a 0.
double MyGrades::getFinalGrade() const
{
	double ave;
	int sum = 0;
	for (int i = 0; i < numberOfOHomeworks; i++)
	{ // get the homework sum
		sum = sum + hw[i];
	}
	if (numberOfOHomeworks != 0)
	{
		ave = (midtermExamWeight * midtermExam) + (finalExamWeight * finalExam) + (HWWeight * (sum / (double)numberOfOHomeworks));
	}
	else
	{
		ave = (midtermExamWeight * midtermExam) + (finalExamWeight * finalExam);
	}
	return ave;
}
// This member function returns the grade needed on the final exam to achieve
// the desiredGrade. If no homeworks exist then the homeowrk average is 0.
// If the midterm does not exist then the midterm grade is 0.
double MyGrades::getGradeNeededOnFinal(double desiredGrade) const
{
	double rv;
	int sum = 0;
	for (int i = 0; i < numberOfOHomeworks; i++)
	{ // get the homework sum
		sum = sum + hw[i];
	}
	double hwGrade = 0;
	if (numberOfOHomeworks > 0)
	{
		hwGrade = sum / (double)numberOfOHomeworks;
	}
	rv = (desiredGrade - ((midtermExamWeight * midtermExam) + (HWWeight * hwGrade))) / finalExamWeight;
	return rv;
}
// Provide the Assignment operator overload implementation only if needed
const MyGrades & MyGrades::operator=(const MyGrades & rightSide)
{ // "this" points to the leftSide
	numberOfOHomeworks = rightSide.numberOfOHomeworks;
	midtermExam = rightSide.midtermExam;
	finalExam = rightSide.finalExam;
	maxNumberOfOHomeworks = rightSide.maxNumberOfOHomeworks;
	if (this != &rightSide)  // "this" is the address of the leftSide
	{ // if this is not a self assignment then
		delete[] hw;
		hw = new int[maxNumberOfOHomeworks];
		for (int i = 0; i < numberOfOHomeworks; i++)
		{ // copy all of the homework assignments grades
			hw[i] = rightSide.hw[i];
		}
	}
	return(*this);  // returns a reference to itself
}
// the equality operator overload is a memeber function of MyGrades.
// It will return a 1 if equal and a 0 if not equal. Two objects are considered
// equal if the midterm, final exam, and all homeworks (number of homeworks and the
// grades) are all equal.
int MyGrades::operator==(const MyGrades & g) const
{
	int rv = 1; // default to true
	if ((finalExam != g.finalExam) || (midtermExam != g.midtermExam) || (numberOfOHomeworks != g.numberOfOHomeworks))
	{ // if exams and array length the same then check the homeworks
		rv = 0;
	}
	for (int i = 0; i < numberOfOHomeworks; i++)
	{ // check all the homeworks
		if (hw[i] != g.hw[i])
		{
			rv = 0;
			break; // once a homewotk is different then end
		}
	}
	return rv;
}
