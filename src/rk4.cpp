#include "rk4.hpp"

void rungekutta4(function<double(double, double)> odesys, double t0,  double tf,  double y0,  double h,  vector<double> &t_sol,  vector<double> &y_sol ){
// constants needed for the RK4 algorithm
double k1, k2, k3, k4;

//# points
int N = (int) ((tf - t0) / h + .5);

t_sol[0] = t0;
y_sol[0] = y0;

string filename = "rk4.txt";
ofstream outputFile(filename, ofstream::out);

if (!outputFile)
{
    cerr << "Error generating the file "<< filename <<endl;
    return ;
}
outputFile << scientific << setprecision(10);
outputFile << "t \t\t\t\ty"<< endl;
outputFile << t_sol[0] << "\t\t\t" << y_sol[0] << endl;

for (size_t j = 1; j < t_sol.size(); j++)
{
    //we evaluate the constants
	k1 = odesys(t_sol[j - 1], y_sol[j - 1]);
	k2 = odesys(t_sol[j - 1] + h / 2., y_sol[j - 1] + k1*h / 2.);
	k3 = odesys(t_sol[j - 1] + h / 2., y_sol[j - 1] + k2*h / 2.);
	k4 = odesys(t_sol[j - 1] + h, y_sol[j - 1] + k3*h);

	//we update the solution
	y_sol[j] = y_sol[j - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6 * h;
	t_sol[j] = t_sol[j - 1] + h;

    outputFile << t_sol[j] << "\t\t\t" << y_sol[j] << endl;
   
}
outputFile.close();

}

