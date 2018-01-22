#include <iostream>
#include <string>
#include <utility>

struct Student
{
    std::string name;
    int grade;
};

void getStudent(Student &student)
{
    std::cout << "Enter name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter grade: ";
    std::cin >> student.grade;
    std::cin.ignore(1,'\n');
}

void sort(Student *students, int number)
{

    for (int count = 0; count < number - 1; ++count)
    {
        int maxGradeElement = count;

        for (int element = count + 1; element < number; ++element)
        {
            if (students[element].grade > students[maxGradeElement].grade)
                maxGradeElement = element;
        }

        std::swap(students[count], students[maxGradeElement]);
    }

}

int main()
{
    std::cout << "How many students do you want to enter? ";
    int number;
    std::cin >> number;
    std::cin.ignore(1,'\n');

    Student *students = new Student[number];

    for (int i = 0; i < number; ++i)
        getStudent(students[i]);

    sort(students, number);

    for (int i = 0; i < number; ++i)
    {
        std::cout << students[i].name << " got a grade of " << students[i].grade << '\n';
    }

    delete[] students;
    students = nullptr;

    return 0;
}
