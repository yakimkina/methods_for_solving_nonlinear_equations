cmake_minimum_required(VERSION 3.17)
project(methods_for_solving_nonlinear_equations)

set(CMAKE_CXX_STANDARD 14)

add_executable(methods_for_solving_nonlinear_equations
        main.cpp main.h
        tests.cpp
        solve_nonlinear_equation/solve_nonlinear_equation.h
        solve_nonlinear_equation/solve_nonlinear_equation.cpp
        solve_nonlinear_equation/table_creation.cpp
        solve_nonlinear_equation/localization.cpp
        solve_nonlinear_equation/bisection_method.cpp solve_nonlinear_equation/Newtons_method.cpp)