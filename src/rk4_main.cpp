#include "rk4.hpp"

double odesys(double t, double y);
int main()
{
    double y0 = 1.;

    double t0 = 0.;
    double tf = 5.;

    double h = .00001;

    //number of points
	int N = (int)((tf - t0) / h + 0.5);

    vector<double> t_sol(N), y_sol(N);

    cout << "Currently integrating " << N << " points..." << endl;

    rungekutta4(odesys, t0, tf, y0, h, t_sol, y_sol);

    cout << "Integration done!" <<endl;

    t_sol.clear();
    y_sol.clear();

    return 0;
}


double odesys(double t, double y){
    return t * sin(y*t);    
}