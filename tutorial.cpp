// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "TutorialConfig.h"


#include <rtapi.h>
#include <hal.h>
#include <hal_priv.h>

using namespace std;

int main (int argc, char *argv[])
{
    int comp_id;
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout,"The square root of %g is %g\n",
        inputValue, outputValue);

    comp_id = hal_init("prefix");

    if(comp_id < 0)
    exit(-1);

    hal_ready(comp_id);
    cout << "Component registered and ready" << "comp_ID " << comp_id;

  return 0;
}