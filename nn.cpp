#include "random.hpp"
#include "param.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "neuron.cpp"
#include "connection.cpp"

struct NeuralNetwork
{
    std::vector<Neuron> neurons;
    std::vector<Connection> connections;

    NeuralNetwork(
        int global_max_connection_id,
        int input_num = INPUT_NUM,
        int output_num = OUTPUT_NUM,
        int normal_num = NORMAL_NUM_LOWER_LIMIT,
        int modulation_num = MODULATION_NUM_LOWER_LIMIT)
        {
            // Initialize neurons
            for (int num=0 ; num < input_num ; num++)
            {
                Neuron n(input);
                neurons.push_back(n);
            }
            for (int num=0 ; num < output_num ; num++)
            {
                Neuron n(output);
                neurons.push_back(n);
            }
            for (int num=0 ; num < normal_num ; num++)
            {
                Neuron n(normal);
                neurons.push_back(n);
            }
            for (int num=0 ; num < modulation_num ; num++)
            {
                Neuron n(modulation);
                neurons.push_back(n);
            }
        }


        // Initialize connections
};

int main(void)
{
    NeuralNetwork nn(1);
    std::cout << nn.neurons.size() << std::endl;
    for (int num=0; num < nn.neurons.size() ; num++)
    {
        std::cout << nn.neurons[num].bias << "\n";
    }
    return 0;
}
