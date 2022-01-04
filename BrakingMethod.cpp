#include <iostream>
#include <cmath>
                         /***THIS IS A BISECTION METHOD IMPLEMENTATION***/


/***PROBLEM FUNCTION DECLARATION #1 ***/

double function1(const double& x) {
    double result =  8 - 4.5*(x - std::sin(x));
    return result;
}
/***PROBLEM FUNCTION DECLARATION # 2***/
double function2( const double& x ){
 //in c++ exponent operator does not exit, need to use cmath pow(base, power) function
 double result1 = (std::pow(x, 10)) - 1;
 return result1;
}


/**REGULA FALSI MODIFIED IMPLEMENTATION*/
double regulaFalsi_Mod(double xl, double xu, const int& iteration, double error, double(*func)(const  double& )){
  double x_lower = xl;
    double x_upper = xu;
    double x_root;
    double xr_old ;
    double ERROR_estimate = error ;
    double ERROR_Aprox;
    float il ;
    float iu;
    /*EVALUATING THE FUNCION IN THE UPPER AND LOWER LIMIT*/
    double FUNCTION_XLOWER = func(x_lower);
    double FUNCTION_XUPPER = func(x_upper);
    /*EVALUATE IF THE FUNCTION HAVE THE SAME SIGN AT POINT A AND B */
    if ((FUNCTION_XLOWER * FUNCTION_XUPPER) > 0) {
        std::cout << "ERROR : the function have the sam sign at the point a and b" << std::endl;
        exit;
    }
    std::cout << "iteration  a          b          Root    f(Root)     Error aprox." << std::endl;
    x_root = x_lower;
    for(int i =0 ; i <=iteration ; i ++) {
            /*CALCULATE THE MIDDLE VALUE ESTIMATE SOLUTION*/
            xr_old = x_root;
            x_root = x_upper-FUNCTION_XUPPER*(x_lower-x_upper)/(FUNCTION_XLOWER-FUNCTION_XUPPER);
            /*EVALUATING THE MIDDLE VALUE WITH THE FUNCTION */
            double FxNS = func(x_root);

            if(x_root != 0){ 
                /*CALCULATE THE ERROR WHILE THE ROOT STILL NOT FOUNDED*/
                ERROR_Aprox = std::abs((x_root-xr_old)/x_root)*100;
                
                printf("% 3i % 11.6f % 11.6f % 11.6f % 11.6f % 11.6f\n", i, x_lower, x_upper, x_root, FxNS, ERROR_Aprox);
            }
         
            if (FxNS == 0.000000){
                std::cout << "Root founded: "<< x_root;
                break;
            }
            /*CHANGING THE VALUE OF THE LIMIT TO APROXIMATE THE ROOT */
            double test = FUNCTION_XLOWER *FxNS;
            if (test <0 ){
                x_upper  = x_root;
                FUNCTION_XUPPER = func(x_upper);
                iu = 0;
                il = il +1;
                if(il>= 2){FUNCTION_XLOWER = FUNCTION_XLOWER/2;}
            }else if(test >0) {
                x_lower = x_root;
                FUNCTION_XLOWER = func(x_lower);
                 il=0;
                 iu = iu +1;
                if(iu>= 2){FUNCTION_XUPPER = FUNCTION_XUPPER/2;}
            }else{
                ERROR_Aprox = 0; 
            }
            if (ERROR_estimate > ERROR_Aprox){
                break;
            }    
    }
    return x_root;
}



double Bisection(double xl, double xu,const int& iteration, double error, double(*func)(const  double& )){
    double x_lower = xl;
    double x_upper = xu;
    double x_root;
    double xr_old ;
    double ERROR_estimate = error ;
    double ERROR_Aprox;
    double FUNCTION_XLOWER = func(x_lower);
    double FUNCTION_XUPPER = func(x_upper);
    /*EVALUATE IF THE FUNCTION HAVE THE SAME SIGN AT POINT A AND B */
    if ((FUNCTION_XLOWER * FUNCTION_XUPPER) > 0) {
        std::cout << "ERROR : the function have the sam sign at the point a and b" << std::endl;
        exit;
    }
    std::cout << "iteration  a          b          Root    f(Root)     Error aprox." << std::endl;
    x_root = x_lower;
    for(int i =0 ; i <=iteration ; i ++) {
            /*CALCULATE THE MIDDLE VALUE ESTIMATE SOLUTION*/
            xr_old = x_root;
            x_root = (x_lower + x_upper)/2;
            double FxNS = func(x_root);
            /*EVALUATING THE MIDDLE VALUE WITH THE FUNCTION */
            if(x_root != 0){ 
                  /*CALCULATE THE ERROR WHILE THE ROOT STILL NOT FOUNDED*/
                ERROR_Aprox = std::abs((x_root-xr_old)/x_root)*100;
                
                printf("% 3i % 11.6f % 11.6f % 11.6f % 11.6f % 11.6f\n", i, x_lower, x_upper, x_root, FxNS, ERROR_Aprox);
            }
         
            if (FxNS == 0.000000){
                std::cout << "Root founded: "<< x_root;
                break;
            }
            /*CHANGING THE VALUE OF THE LIMIT TO APROXIMATE THE ROOT */
            double test = FUNCTION_XLOWER *FxNS;
            if (test <0 ){
                x_upper  = x_root;
                FUNCTION_XUPPER = FxNS;
            }else if(test >0) {
                x_lower = x_root;
                FUNCTION_XLOWER = FxNS;
            }else{
                ERROR_Aprox = 0; 
            }
            if (ERROR_estimate > ERROR_Aprox){
                break;
            }    
    }
    return x_root;
}





int main()
{
    std::cout<<"Bisection method"<<std::endl;
    Bisection(0, 1.3 , 50, 0.0001,&function2);
    std::cout<<"Regula Falsi method"<<std::endl;
    regulaFalsi_Mod(0, 1.3 , 50, 0.0001, &function2);
    return 0;
}