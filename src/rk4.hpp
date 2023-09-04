#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include<functional>
#include <fstream>

using namespace std;

void rungekutta4(function<double(double, double)> odesys, 
                 double t0, 
                 double tf, 
                 double y0, 
                 double h, 
                 vector<double>& t_sol, 
                 vector<double>& y_sol
                 );