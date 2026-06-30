#pragma once

#include "./include_files.h"


namespace fem_functions
{

    Eigen::Matrix<double, number_of_nodes, number_of_nodes> mass_matrix_assembler(const std::vector<double> & x);



    Eigen::Matrix<double, number_of_nodes, 1> source_assembler(const std::vector<double> & x,
                                                               const std::vector<double> & constanta_k,
                                                               const std::vector<double> & constanta_g,
                                                               double (*source_function) (double));



    Eigen::Matrix<double, number_of_nodes, number_of_nodes> stiffness_matrix_assembler(const std::vector<double> & x,
                                                                                       const std::vector<double> & constanta_k,
                                                                                       double (*thermal_diffusivity) ());
}