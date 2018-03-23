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
#include "Scenario.hpp"


#define TEST true


int main(void) {
    if (TEST){
        allTest();
    }

    BaseScenario(400, 300).toImage("image.bmp", true, 3);

    return 2;

}





