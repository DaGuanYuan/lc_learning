#include<iostream>
#include<vector>
#include<string>
#include<ctime>

class Person {
public:
    Person();
    explicit Person(int name, int age) 
        :m_name(name)
        ,m_age(age)
        {}

    explicit Person(int age)
        :m_age(age)
        {}
    int m_age;  
    int m_name;
};

std::ostream& operator<<(std::ostream& cout,Person& p) {
    cout << p.m_age << p.m_name << std::endl;
    return cout;
}

int main() {
    Person p1(1.5324, 2);
    Person p2('a');
    std::cout << p1 << std::endl;
    return 0;
}
