#ifndef GPIOCLASS_H
#define GPIOCLASS_H

#include <string>



class GPIOClass
{
public:
    GPIOClass();
    GPIOClass(std::string x);

    int export_gpio();
    int unexport_gpio();
    int setdir_gpio(std::string dir);
    int setval_gpio(std::string val);
    int getval_gpio(std::string& val);
    std::string get_gpionum();

private:
std::string gpionum;

};

#endif // GPIOCLASS_H
