# Fourth-Order Runge-Kutta ODE Solver

## Description
This project implements the fourth-order Runge-Kutta algorithm to solve ordinary differential equations (ODEs). The fourth-order Runge-Kutta method is a widely used numerical technique for approximating the solutions of initial value problems in ODEs.

## Algorithm
The fourth-order Runge-Kutta algorithm is a higher-order numerical method for solving ODEs. It approximates the solution by updating the dependent variable at discrete time steps using the following iterative steps:

1. Compute the increment values `k1`, `k2`, `k3`, and `k4` as follows:
   - `k1 = h * f(t, y)` (where `h` is the time step, `t` is the current time, and `y` is the current value of the dependent variable)
   - `k2 = h * f(t + h/2, y + k1/2)`
   - `k3 = h * f(t + h/2, y + k2/2)`
   - `k4 = h * f(t + h, y + k3)`

2. Update the value of the dependent variable:
   - `y_new = y + (k1 + 2*k2 + 2*k3 + k4)/6`

3. Increment the time:
   - `t = t + h`

4. Repeat the above steps until the desired time interval is covered.

## Usage
To use this implementation, follow these steps:

1. Import or include the Runge-Kutta solver code in your project.

2. Define your ODE function `f(t, y)` that describes the rate of change of the dependent variable `y` with respect to time `t`.

3. Set the initial conditions, such as the initial time `t0`, the initial value of `y0`, and the time step `h`.

4. Implement a loop to iterate over time steps and use the fourth-order Runge-Kutta method to solve your ODE.

5. Access the solution at each time step for further analysis.
---
### Further changes (yet to be implemented)
1. *Generalise the algorithm to vectorial ODEs*
2. *Implementing a way to chose the best `h`*