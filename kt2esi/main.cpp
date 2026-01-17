#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


#ifndef MYCLASS_H

#define MYCLASS_H

class myClass

{

public:

    myClass();

    ~myClass();

    string publicTextToPrint;

    void publicFunction(string text);

private:

    string privateTextToPrint;

    void privateFunction();

protected:
    string protectedTextToPrint;
    void protectedFunction();
};

#endif // MYCLASS_H

#ifndef MYCLASS_H

#define MYCLASS_H

class myClass

{

public:

    myClass();
    int result;
    int calculateResult();

private:
    int number1;
    int number2;

protected:
    void setNumber1(int value);
    void setNumber2(int value);

};

#endif // MYCLASS_H
