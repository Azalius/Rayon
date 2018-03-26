#include <stdio.h>
#include "tests/test.hpp"
#include "Scenario.hpp"


#define TEST true


int main(void) {
    if (TEST){
        allTest();
    }

    BaseScenario(1920, 1080).toImage("image3.bmp", false, 4);

    return 0;

}





