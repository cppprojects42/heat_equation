#pragma once

#include "./include_files.h"


namespace tools
{
    std::vector<double> return_grid(int series_size, double coefficient);


    std::vector<double> initial_state(std::vector<double> x);


    bool parameters_of_app(std::vector<double> & constanta_k, std::vector<double> & constanta_g, int argc, char *argv[]);


    void plot_2d(const std::vector<double> & data_x, const std::vector<std::vector<double>> & data_y, bool plot_3d_flag);


    void plot_3d(const std::vector<std::vector<double>> & data, bool plot_3d_flag);

    
    double thermal_diffusivity();
    double source_function(double x);
}