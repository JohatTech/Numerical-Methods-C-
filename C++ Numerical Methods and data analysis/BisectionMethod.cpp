
#include <iostream>
#include <cmath>
                         /***THIS IS A BISECTION METHOD IMPLEMENTATION ***/


/***PROBLEM FUNCTION DECLARATION ***/

double function(const double& x) {
    double result =  8 - 4.5*(x - std::sin(x));
    return result;
}



void Bisection() {
    double limit_A;
    double limit_B;
    double MAX_ITERATION;
    double TOLERANCE;
    std::cout << "TYPE YOUR LIMIT VALUES\n";
    std::cin >> limit_A;
    std::cin >> limit_B;
    std::cout << "TYPE YOUR MAX_ITERATIONS\n";
    std::cin >> MAX_ITERATION;
    std::cout << "TYPE THE AMOUNT OF TOLERANCE \n";
    std::cin >> TOLERANCE;
    double FUNCTION_A = function(limit_A);
    double FUNCTION_B = function(limit_B);
    /*EVALUATE IF THE FUNCTION HAVE THE SAME SIGN AT POINT A AND B */
    if ((FUNCTION_A * FUNCTION_B) > 0) {
        std::cout << "ERROR : the function have the sam sign at the point a and b" << std::endl;
    }
    else {
        std::cout << "iteration  a      b        (xNS)Solution     f(xNS)     Tolerance" << std::endl;
        for (int i = 0; i <= MAX_ITERATION; i++) {
            /*CALCULATE THE MIDDLE VALUE ESTIMATE SOLUTION*/
            double xNS = (limit_A + limit_B) / 2;
            double CURRENT_TOLERANCE = (limit_B - limit_A) / 2;
            /*EVALUATE THE FUNCTION WITH THE MIDDLE VALUE ESTIMATE SOLUTION */
            double FxNS = function(xNS);
            printf("% 3i % 11.6f % 11.6f % 11.6f % 11.6f % 11.6f\n", i, limit_A, limit_B, xNS, FxNS, CURRENT_TOLERANCE);
            /*STOP THE PROGRAM IF THE SOLUTION F(X) = 0 WAS FOUND */
            if (FxNS == 0) {
                printf("An exact soluction x = %11.6f was found ", xNS);
            }

            /** STOP THE PROGRAM IF THE TOLERANCE OF THE ITERATION IS SMALLER THAN THE DESIRED TOLERANCE**/
            if (CURRENT_TOLERANCE < TOLERANCE) {
                break;
            }
            /*STOP THE PROGRAM IF THE SOLUTION WAS NOT FOUND AND WE REACH THE MAXIMUN ITERATION*/
            if (i == MAX_ITERATION) {
                std::cout << "solution was not obtained" << MAX_ITERATION << std::endl;
                break;
            }
            /**Determine whether the true solution is between a and xNS, or between xNS and b, and select a and b for the next iteration***/
            if ((function(limit_A) * FxNS) < 0) {
                limit_A = xNS;
            }
            else {
                limit_B = xNS;
            }
        }
    }
}
int main()
{
    
    return 0;
 
}

