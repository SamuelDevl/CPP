#include <iostream>
using std::string;

class AbstractEmployee{
    virtual void AskForPromotion() = 0;

};

// constructor

class Employee:AbstractEmployee {
private:
    
    string Company;
    int Age;
protected:
    string Name;

public: // private / protected

    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age>=18)
        Age = age;
    }
    int getAge(){
        return Age;
    }



    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
        
    }

    Employee(string name, string company, int age){ //constructor pouziti 
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion(){
        if(Age<30)
            std::cout<<Name<<" got promoted"<<std::endl;
        else
            std::cout<<Name<<"sorry but no"<<std::endl;
    }
    
};

class Developer:public Employee {   // inheritance
public:
    string favoriteProLang;
    Developer(string name, string company, int age, string favoriteProLang)
    :Employee(name,company,age)
    {
        favoriteProLang = favoriteProLang;
    }
    void fixBug(){
        std::cout << Name<< " fixed bug using" << favoriteProLang << std::endl;
    }
};

class Teacher:public Employee{
    public:
    string Subject;
    void prepareLesson(){
        std::cout << Name << " is prparing " << Subject << " lesson" << std::endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name,company,age)
    {
        Subject = subject;
    }
};

int main() {
    Developer d=Developer("Sam", "Global",25,"C++");
    d.fixBug();
    d.AskForPromotion();
    Teacher t = Teacher("jack ","cool school",35, "History");
    t.prepareLesson();
    t.AskForPromotion();
    
}