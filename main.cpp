#include <stdio.h>
#include "tests/test.hpp"
#include "Scenario.hpp"


#define TEST true


int main(void) {
    if (TEST){
        allTest();
    }

    //BaseScenario(400, 320).toImage("image4.bmp", true, 4);
    LineScenario(300, 220).toImage("image5.bmp", true, 6);

    return 0;

}





