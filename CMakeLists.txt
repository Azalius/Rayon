cmake_minimum_required(VERSION 3.7)
project(image)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        bases3d.cpp
        bases3d.hpp
        bitmap.cpp
        bitmap.hpp
        camera.cpp
        camera.hpp
        const.hpp
        couleurRVB.cpp
        couleurRVB.hpp
        intersection.cpp
        intersection.hpp
        liste.hpp
        lumiere.cpp
        lumiere.h
        objet3D.hpp
        pixelmap.cpp
        pixelmap.hpp
        plan.cpp
        plan.hpp
        rayon.cpp
        rayon.hpp
        sphere.cpp
        sphere.hpp
        tests/test.cpp
        tests/test.hpp
        tests/testVec.cpp
        tests/testVec.hpp
        main.cpp
        Scenario.cpp Scenario.hpp Cube.cpp Cube.hpp)

add_executable(image ${SOURCE_FILES})