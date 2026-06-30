# The project theme: the heat equation

The purpose of the project: an analysis of the heat equation.

Next problem is solved:

```math
\begin{equation*}
    \text{find u(x, t): }
\end{equation*}
```
```math
\begin{equation}
    \frac{\partial u}{\partial t} - 0.75 \frac{\partial^2 u}{\partial x^2} = 0.75x, x \in [0, 1], t \in [0, 0.5],
\end{equation}
```
```math
\begin{equation}
    u(x, 0) = 0.5 - |0.5-x|
\end{equation}
```

With the Robin boundary conditions:

```math
\begin{equation}
    \frac{\partial u}{\partial x}(0, t) = k_0(u(0, t) - g_0),
\end{equation}
```
```math
\begin{equation}
    -\frac{\partial u}{\partial x}(1, t) = k_1(u(1, t) - g_1).
\end{equation}
```


## The structure of the repository:

```
heat_eq/
|---src/
    |--- fem_functions.cpp
    |--- main.cpp
    |--- solution_steps.cpp
    |--- tools.cpp
|---include/
    |--- fem_functions.h
    |--- include_files.h
    |--- solution_steps.h 
    |--- tools.h
|---images/
    |--- my_plot_Neumann_cond.png
    |--- my_plot_Dirichlet_cond.png
|---CMakeLists.txt
```






## The description of the files:

`main.cpp` - the main part of the project  
`fem_functions.cpp` - functions necessary for the finite element method  
`solution_steps.cpp` - the heat equation solution process  
`tools.cpp` - additional functions necessary for the project

`Images` folder  - plots of solutions for different sets of coefficients

## The necessary steps for the installation of this project:

```
cd heat_equation

cmake -B build

cmake --build build
```

## How the executable can be used:

1)
```
./build/heat_equation_solver
```
( the default values for the coefficients: k_0 = k_1 = 1000000, g_0 = g_1 = 0 (the Dirichlet boundary conditions) )

2)
```
./build/heat_equation_solver 1
```
( the default values for the coefficients: k_0 = k_1 = 1000000, g_0 = g_1 = 0 (the Dirichlet boundary conditions) )

The last flag ( 1 ) - the instruction for a 3d plotting

3)

Reasonable coefficients can be provided: k_0, k_1, g_0, g_1

all coefficients must be provided at once
```
./build/heat_equation_solver 0 0 0 0 1
```
k_0 = k_1 = g_0 = g_1 = 0 - (the Neumann boundary conditions)

The last flag ( 1 ) - the instruction for a 3d plotting