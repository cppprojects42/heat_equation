#include "../include/tools.h"


namespace tools
{

    std::vector<double> return_grid(int series_size, double coefficient)
    {
        std::vector<double> location(series_size);

        std::iota(location.begin(), location.end(), 0);

        for (double &x : location) { x *= coefficient; }

        return location;
    }



    std::vector<double> initial_state(std::vector<double> x)
    {
        std::vector<double> xi;
        xi.reserve(x.size());

        for (double y : x) {
            xi.push_back(0.5 - std::abs(0.5 - y));
        }

        return xi;
    }



    bool parameters_of_app(std::vector<double> & constanta_k, std::vector<double> & constanta_g, int argc, char *argv[])
    {
        bool plot_3d_flag = false;

        if (argc == 5 | argc == 6){

            constanta_k.assign({ atof(argv[1]), atof(argv[2]) });
            constanta_g.assign({ atof(argv[3]), atof(argv[4]) });

            if (argc == 6){
                if (atof(argv[5]) == 1){
                    plot_3d_flag = true;
                }
            }
        }

        if (argc == 2){
            if (atof(argv[1]) == 1){
                plot_3d_flag = true;
            }
        }

        return plot_3d_flag;
    }



    void plot_2d(const std::vector<double> & data_x, const std::vector<std::vector<double>> & data_y, bool plot_3d_flag)
    {
        if (plot_3d_flag == false){

            for (int i = 0; i < number_of_nodes - 1; i++){

                matplot::plot(data_x, data_y[i])->line_width(3);
                matplot::ylim({-0.05, 0.55});
                matplot::grid(matplot::on);
                matplot::show();
            }            
        }
    }



    void plot_3d(const std::vector<std::vector<double>> & data, bool plot_3d_flag)
    {
        if (plot_3d_flag == true){

            auto [X, Y] = matplot::meshgrid(matplot::linspace(0, 1, number_of_nodes), matplot::linspace(0, 0.5, number_of_nodes));

            auto Z = matplot::transform(Y, X, [&data](double y, double x) {            
                return data[y*200][x*100];
            });

            matplot::meshc(X, Y, Z);
            matplot::colorbar();
            matplot::zlim({-0.1, 0.5});
            matplot::title("Heat equation with FEM");
            matplot::xlabel("Location");
            matplot::ylabel("Time");
            matplot::zlabel("Temperature of rod");

            //matplot::save("my_plot.png"); 
            matplot::show();
        }
    }


    
    double thermal_diffusivity (){
        return 0.75;
    }

    double source_function (double x){
        return 0.75*x;
    }
}