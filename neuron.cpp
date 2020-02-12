#include "random.hpp"
#include "param.hpp"
#include <iostream>
#include <stdlib.h>

enum NeuronType
{
    input = 1,
    output = 2,
    normal = 3,
    modulation = 4,
};

struct Neuron
{
  private:
    double activation_val = 0.0;
    double modulation_val = 0.0;

  public:
    NeuronType neuron_type;
    double bias;
    double A,B,C,D;

    Neuron(NeuronType nt)
    {
        neuron_type = nt;
        bias = drnd(BIAS_LOWER_LIMIT, BIAS_UPPER_LIMIT);
        A = drnd(EVOPARAM_LOWER_LIMIT, EVOPARAM_UPPER_LIMIT);
        B = drnd(EVOPARAM_LOWER_LIMIT, EVOPARAM_UPPER_LIMIT);
        C = drnd(EVOPARAM_LOWER_LIMIT, EVOPARAM_UPPER_LIMIT);
        D = drnd(EVOPARAM_LOWER_LIMIT, EVOPARAM_UPPER_LIMIT);
    }

    void set_activation_val(double a)
    {
        if(neuron_type == (NeuronType) modulation)
        {
            std::cout << "ERROR neuron.cpp" << '\n';
            std::cout << "You cannot set activation_val of modulatory neuron" << std::endl;
            exit(1);
        }
        else activation_val = a;
    }

    double get_activation_val(void){ return this -> activation_val; }

    void set_modulation_val(double m)
    {
        if(neuron_type != (NeuronType) modulation)
        {
            std::cout << "ERROR neuron.cpp" << '\n';
            std::cout << "You cannot set modulation_val of non modulatory neuron" << std::endl;
            exit(1);
        }
        else modulation_val = m;
    }
    double get_modulation_val(void){ return this -> modulation_val; }
};

/*
int main(void)
{
    Neuron n(normal);
    std::cout << n.bias << '\n';
    std::cout << n.A << ' ' << n.B << ' ' <<  n.C << ' ' <<  n.D << '\n';
    std::cout << n.neuron_type << '\n';
    n.set_modulation_val(10.0);
    std::cout<<n.get_modulation_val();
    return 0;
}
*/
