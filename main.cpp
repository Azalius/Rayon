#include <stdio.h>
#include "tests/test.hpp"
#include "bases3d.hpp"
#include "plan.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "pixelmap.hpp"
#include "intersection.hpp"
#include "lumiere.h"
#include "rayon.hpp"
#include "objet3D.hpp"
#include "tests/Scenario.hpp"


#define TEST true


int main(void) {
    if (TEST){
        allTest();
    }

    BaseScenario(1920, 1080).toImage("image.bmp", true, 6);

    return 2;

}





