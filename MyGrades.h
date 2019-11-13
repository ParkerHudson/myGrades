
#ifndef MYGRADES_H
#define MYGRADES_H

class MyGrades
{
public:
	// Constructors
	MyGrades();
	MyGrades(const MyGrades &org); // copy constructor

	// Destructor
	~MyGrades();

	// mutators
	void setFinalExam(int grade);
	void setMidtermExam(int grade);
	void setHomework(int grade);

	// accessors
	double getFinalGrade() const;
	double getGradeNeededOnFinal(double desiredGrade) const;

	// overloaded operators
	const MyGrades & operator=(const MyGrades & rightSide);
	int operator==(const MyGrades & g) const;

private:
	// member variables
	const int DEFAULT_NUM_HW = 3;
	int *hw;
	int finalExam;
	int midtermExam;
	int numberOfOHomeworks;
	int maxNumberOfOHomeworks;
	const double finalExamWeight = .4;
	const double midtermExamWeight = .3;
	const double HWWeight = .3;
};

#endif
