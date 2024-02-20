#include <iostream>
#include <string>
using namespace std;

class Human
{
public: // модификатор доступа

	int age; // поля класса
	int weight;
	string name; // свойства/поля класса

    void Print()
    {
        cout << "Name " << name << "\nWeight " << weight << "\nAge " << age << endl;
    }
};

class Point
{
public:
    int x;
    int y;
    void Print()
    {
       cout << "y= " <<  y << "\nx = " << x << "\n" << "z = " << z << endl;
       PrintY();
    }
private:
    int z;

    void PrintY()
    {
     cout << y << endl;
    }
};

void Print()
{


}
int main()
 {
    setlocale(LC_ALL, "ru");
    /*Human firstHuman;
    firstHuman.age = 30;
    firstHuman.name = "Ivanov Ivan";
    firstHuman.weight = 100;
    firstHuman.Print();*/

    Point a;
    a.Print();
	return 0;
}
