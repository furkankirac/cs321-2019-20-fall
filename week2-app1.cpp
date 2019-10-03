//#include <stdio.h>
#include <iostream>

//TYPE varname;
int i;

//typedef struct {
//    float salary;
//    unsigned char age;
//    char name[20];
//} Employee;

struct Employee
{
    float salary;
    unsigned char age;
    char name[20];
};

void printEmployee(Employee* ptr)
{
//    ptr->salary,   ptr[0].salary,   (*ptr).salary
    std::cout << "Salary=" << ptr->salary << std::endl;
    std::cout << "Age=" << (int)ptr->age << std::endl;
}

int main(int argc, char* argv[])
{
    Employee e1, e2, e3;

    e1.age = 42;
    e1.salary = 10300.2f;
//    employee.name = "Furkan";
    e2.age = 30;
    e2.salary = 5000.0f;

    printEmployee(&e1);

//    printf("Hello World\n");
    std::cout << "Hello World in C++" << std::endl;
    return 0;
}
