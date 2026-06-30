#include "../include/fem_functions.h"

namespace fem_functions
{
    
    Eigen::Matrix<double, number_of_nodes, number_of_nodes> mass_matrix_assembler(const std::vector<double> & x)
    {
        Eigen::Matrix<double, number_of_nodes, number_of_nodes> mass_matrix;

        double delta;

        for(int i = 0; i < number_of_nodes - 1; i++)
        {
            delta = x[i+1]-x[i];

            mass_matrix(i, i) += delta/3;

            mass_matrix(i, i+1) += delta/6;
            mass_matrix(i+1, i) += delta/6;

            mass_matrix(i+1, i+1) += delta/3;
        }

        return mass_matrix;
    }



    Eigen::Matrix<double, number_of_nodes, 1> source_assembler(const std::vector<double> & x,
                                                               const std::vector<double> & constanta_k,
                                                               const std::vector<double> & constanta_g,
                                                               double (*source_function) (double))
    {
        Eigen::Matrix<double, number_of_nodes, 1> load_vector;

        double delta;

        for(int i = 0; i < number_of_nodes - 1; i++)
        {
            delta = x[i+1] - x[i];

            load_vector(i) += source_function(x[i])*delta/2;

            load_vector(i+1) += source_function(x[i+1])*delta/2;
        }

        load_vector(0) += constanta_k[0]*constanta_g[0];
        load_vector[number_of_nodes-1] += constanta_k[1]*constanta_g[1];

        return load_vector;
    }



    Eigen::Matrix<double, number_of_nodes, number_of_nodes> stiffness_matrix_assembler(const std::vector<double> & x,
                                                                                       const std::vector<double> & constanta_k,
                                                                                       double (*thermal_diffusivity) ())
    {

        Eigen::Matrix<double, number_of_nodes, number_of_nodes> stiffness_matrix;

        double delta, constanta_ther_diff;

        for(int i = 0; i < number_of_nodes - 1; i++)
        {
            delta = x[i+1]-x[i];

            constanta_ther_diff = thermal_diffusivity();

            stiffness_matrix(i, i) += constanta_ther_diff/delta;

            stiffness_matrix(i, i+1) -= constanta_ther_diff/delta;
            stiffness_matrix(i+1, i) -= constanta_ther_diff/delta;

            stiffness_matrix(i+1, i+1) += constanta_ther_diff/delta;
        }

        stiffness_matrix(0, 0) += constanta_k[0];
        stiffness_matrix(number_of_nodes-1, number_of_nodes-1) += constanta_k[1];

        return stiffness_matrix;
    }
}