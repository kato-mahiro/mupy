#include "random.hpp"
#include "param.hpp"
#include <iostream>
#include <stdlib.h>

struct Connection
{
  public:
    int connection_id;
    int input_id;
    int output_id;
    bool is_valid = true;
    double initial_weight;
    double weight;

    Connection(int connection_id, int input_id, int output_id)
    {
        this -> connection_id = connection_id;
        this -> input_id = input_id;
        this -> output_id = output_id;
        initial_weight = drnd(WEIGHT_LOWER_LIMIT, WEIGHT_UPPER_LIMIT);
        weight = initial_weight;
    }
};

/*
int main(void)
{
    Connection c(10,20,30);
    std::cout << c.connection_id << ',' << c.input_id << ',' << c.output_id << ','
    << c.is_valid << ',' << c.initial_weight <<',' << c.weight <<'\n' << std::endl;
    c.weight = 0.0;
    std::cout << c.connection_id << ',' << c.input_id << ',' << c.output_id << ','
    << c.is_valid << ',' << c.initial_weight <<',' << c.weight <<'\n' << std::endl;
}
*/
