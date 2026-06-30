#pragma once

#include "./include_files.h"

namespace solution_steps
{
    void solution_process(const Eigen::Ref<const Eigen::Matrix<double, number_of_nodes, number_of_nodes>>& mat_M,
                          const Eigen::Ref<const Eigen::Matrix<double, number_of_nodes, number_of_nodes>>& mat_A,
                          const Eigen::Ref<const Eigen::Matrix<double, number_of_nodes, 1>>& vec_b,
                          std::vector<std::vector<double>> & list_vec_sol,
                          std::vector<double> x);
}