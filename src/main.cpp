#include "../include/fem_functions.h"
#include "../include/tools.h"
#include "../include/solution_steps.h"


int main(int argc, char *argv[])
{
    std::vector<double> constanta_k{1.e+6, 1.e+6}, constanta_g{0.0, 0.0};

    bool plot_3d_flag = tools::parameters_of_app(constanta_k, constanta_g, argc, argv);
    
    std::vector<double> data_x = tools::return_grid(number_of_nodes, 0.01);
    
    auto mat_M = fem_functions::mass_matrix_assembler(data_x);
    
    auto mat_A = fem_functions::stiffness_matrix_assembler(data_x, constanta_k, tools::thermal_diffusivity);

    auto vec_b = fem_functions::source_assembler(data_x, constanta_k, constanta_g, tools::source_function);
    
    std::vector<std::vector<double>> list_vec_sol;
    list_vec_sol.reserve(number_of_nodes);

    solution_steps::solution_process(mat_M, mat_A, vec_b, list_vec_sol, data_x);

    tools::plot_2d(data_x, list_vec_sol, plot_3d_flag);

    tools::plot_3d(list_vec_sol, plot_3d_flag);    
}
