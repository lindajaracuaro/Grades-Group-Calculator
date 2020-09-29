#include <iostream>
#include <cstdarg>

double average(const int numStudents, ...);

int main()
{
	std::cout << "Grades of 2 - B \n----------------\n\n"
		<< "Nancy\t100 \nDaniel\t98\nRigo\t85\nOmar\t70\nJona\t50\n\n"
		<< "Group average is\t"
		<< average(5, 100.0, 98.0, 85.0, 70.0, 50.0)
		<< "\n";

	return 0;
}

double average(const int numStudents, ...)
{
	va_list grades;
	va_start(grades, numStudents);
	double total = 0.0;

	for (int i = 0; i < numStudents; ++i)
	{
		total += va_arg(grades, double);
	}

	va_end(grades);

	auto avg = total / numStudents;

	return avg;

}