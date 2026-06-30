#include "../include/tools.h"
#include "../include/solution_steps.h"

namespace solution_steps
{

    void solution_process(const Eigen::Ref<const Eigen::Matrix<double, number_of_nodes, number_of_nodes>>& mat_M,
                          const Eigen::Ref<const Eigen::Matrix<double, number_of_nodes, number_of_nodes>>& mat_A,
                          const Eigen::Ref<const Eigen::Matrix<double, number_of_nodes, 1>>& vec_b,
                          std::vector<std::vector<double>> & list_vec_sol,
                          std::vector<double> x)
    {
        double k;

        std::vector<double> t = tools::return_grid(number_of_nodes, 0.005),
                            xi = tools::initial_state(x),
                            vec_sol(number_of_nodes);

        Eigen::Matrix<double, number_of_nodes, number_of_nodes> arg_1;

        Eigen::Matrix<double, number_of_nodes, 1> arg_2;

        Eigen::Matrix<double, number_of_nodes, 1> solution = Eigen::Map<Eigen::Matrix<double, number_of_nodes, 1>>(xi.data());


        list_vec_sol.push_back(xi);

        for (int i = 0; i < 100; i++){

            k = t[i+1] - t[i];
        
            arg_1 = mat_M + mat_A*k;

            arg_2 = mat_M * solution + vec_b*k;
    
            solution = arg_1.colPivHouseholderQr().solve(arg_2);            

            Eigen::Map<Eigen::Matrix<double, number_of_nodes, 1>>(vec_sol.data()) = solution;
            
            list_vec_sol.push_back(vec_sol);
        }      
    }
}