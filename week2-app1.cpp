//#include <string.h>
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
    static int num_employee;

    float salary;
    unsigned char age;
    char* name;

    Employee(float salary_, unsigned char age_, const char* name_) :
        salary(salary_), age(age_)
    {
        int sz = strlen(name_);
        name = new char[sz+1];
        strcpy(name, name_);
        num_employee++;
    }

    ~Employee()
    {
        delete[] name;
        num_employee--;
    }

    void print()
    {
    //    this->salary,   this[0].salary,   (*this).salary
//        std::cout << "Salary=" << this->salary << std::endl;
//        std::cout << "Age=" << (int)this->age << std::endl;
//        std::cout << "Name=" << this->name << std::endl;
        std::cout << "Salary=" << salary << std::endl;
        std::cout << "Age=" << (int)age << std::endl;
        std::cout << "Name=" << name << std::endl;
    }

};

int Employee::num_employee = 0;


void STRCPY(char* dest, const char* src)
{
    while(*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
}

int main(int argc, char* argv[])
{
    Employee e1(10300.2f, 42, "Furkan");
    Employee e2(5000.0f, 30, "Hasan");

//    Employee* e1_ptr = &e1;
//    e1_ptr->print();
    e1.print();
//    printEmployee(&e1);

//    printf("Hello World\n");
    std::cout << "Hello World in C++" << std::endl;
    return 0;
}
