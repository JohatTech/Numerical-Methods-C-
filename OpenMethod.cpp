#include <iostream>
#include <cmath>

/*FIXED POINT IMPLEMENTATION*/

double function1(const double & x){
 double result = std::exp(-x)-x;
 return result;
}


double fixPt(double x_zero, double error_estimate,const int& MAX_ITERATIONS, double(*func)(const double&)){
 double error_aprox;
 double x_root = x_zero;
 double x_old;
 int iterations  = 0;
 while (iterations<= MAX_ITERATIONS){
  x_old = x_root;
  x_root = func(x_old);
  iterations++;
  if(x_root =! 0){
   error_aprox = ((x_root - x_old)/x_root)*100;
  }
  if(error_aprox<error_estimate || iterations>=MAX_ITERATIONS){
   std::cout<<"limit of iteration reached or error aproximation less than estimated" << std::endl;
   break;
  }
 }
 return x_root;

}

int main()
{
   fixPt(0, 0.01, 15,&function1);
 
  return 0;
}