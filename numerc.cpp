/*

#include <iostream>
#include <vector>
#include <cmath>
#define EPSILON 0.000001

using namespace std;

//  demo equation : x²-5.5x+5.16=0
// demo formate   : n(degree) a b c....(co-efficient)
//  demo input1   : 2 1 -5.5 5.16

//  demo equation : 8x³-108x²+478x-693=0
// demo formate   : n(degree) a b c....(co-efficient)
//  demo input1   : 3 8 -108 478 -693

//  demo equation : 16x⁴-320x³+2360x²-7600x+9009=0
// demo formate   : n(degree) a b c....(co-efficient)
//  demo input1   : 4 16 -320 2360 -7600 9009

//2 1 -3 2

int no_of_degree = 0;

struct ab_pair
{
    float a;
    float b;
};

vector<float> co_efficient_vector(no_of_degree);

float equation_value(float x)
{
    float value = 0;
    int power = no_of_degree;

    for (int i = 0; i < co_efficient_vector.size(); i++)
    {
        value += pow(x, power) * co_efficient_vector[i];
        power--;
    }
    return value;
}

float derivative_equation_value(float x)
{
    int co_power = no_of_degree;
    float value = 0;
    int power = no_of_degree - 1;

    for (int i = 0; i < co_efficient_vector.size() - 1; i++)
    {
        value += pow(x, power) * co_efficient_vector[i] * co_power;
        power--;
        co_power--;
    }
    return value;
}

float newton_raphson(float x)
{
    float h = equation_value(x) / derivative_equation_value(x);
    int iteration = 0;
    float y = 0;

    while (fabs(h) > EPSILON)
    {

        y = x;
        x = y - h;
        h = equation_value(x) / derivative_equation_value(x);
        iteration++;
        cout << fabs(x - y) << endl;
    }

    cout << "No of iteration :" << iteration << endl;
    return x;
}

int main()

{

    cin >> no_of_degree;

    co_efficient_vector.resize(no_of_degree + 1, 0);

    for (int i = 0; i < co_efficient_vector.size(); i++)
    {
        cin >> co_efficient_vector[i];
    }

    // for (int i = 0; i < co_efficient_vector.size(); i++)
    // {
    //     cout<< co_efficient_vector[i]<<" ";
    // }

    float range_a = 0;
    float range_b = 0;
    float c = sqrt((pow((co_efficient_vector[1] / co_efficient_vector[0]), 2) - 2 * (co_efficient_vector[2] / co_efficient_vector[0])));

    range_a = floor(-1 * c);
    range_b = ceil(1 * c);

    vector<ab_pair> pairab;

    pairab.reserve(no_of_degree);

    float temp_a = range_a;
    float temp_b = range_a + 1;
    vector<float> result(no_of_degree, 0);

    int index=0;

    while (temp_b < range_b + 1)
    {
        if(equation_value(temp_a)==0){
            result[index++]=equation_value(temp_a);
        }
        if(equation_value(temp_b)==0){
            result[index++]=equation_value(temp_b);
        }
        if (equation_value(temp_a) * equation_value(temp_b) < 0)
        {
            pairab.push_back({temp_a, temp_b});
        }
        temp_a = temp_b;
        temp_b = temp_b + 1;
    }


    // for (int i = 0; i < pairab.size(); i++)
    // {

    //         result[index++] = newton_raphson((pairab[i].a+pairab[i].b)/2);

    // }

    // cout<<"Roots : ";

    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout<<result[i]<<" ";
    // }
    // cout<<endl;

    for (int i = 0; i < no_of_degree; i++)
    {

        result[index++] = newton_raphson((pairab[i].a + pairab[i].b) / 2);
        cout<<"gape"<<endl;
    }

    cout << "Roots : ";

    for (int i = 0; i < no_of_degree; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

*/

/*

#include <iostream>
#include <vector>
#include <cmath>
#define EPSILON 0.000001

using namespace std;

//  demo equation : x²-5.5x+5.16=0
// demo formate   : n(degree) a b c....(co-efficient)
//  demo input1   : 2 1 -5.5 5.16


//  demo equation : 8x³-108x²+478x-693=0
// demo formate   : n(degree) a b c....(co-efficient)
//  demo input1   : 3 8 -108 478 -693

//  demo equation : 16x⁴-320x³+2360x²-7600x+9009=0
// demo formate   : n(degree) a b c....(co-efficient)
//  demo input1   : 4 16 -320 2360 -7600 9009

int no_of_degree = 0;

struct ab_pair
{
    float a;
    float b;
};

vector<float> co_efficient_vector(no_of_degree);

float equation_value(float x)
{
    float value = 0;
    int power = no_of_degree;

    for (int i = 0; i < co_efficient_vector.size(); i++)
    {
        value += pow(x, power) * co_efficient_vector[i];
        power--;
    }
    return value;
}

float derivative_equation_value(float x)
{
    int co_power = no_of_degree;
    float value = 0;
    int power = no_of_degree - 1;

    for (int i = 0; i < co_efficient_vector.size() - 1; i++)
    {
        value += pow(x, power) * co_efficient_vector[i] * co_power;
        power--;
        co_power--;
    }
    return value;
}

float scant_method(float x, float y)
{
    float f_x = equation_value(x);
    float f_y = equation_value(y);
    float z;
    int no_of_iteration = 0;

    // cout<<"check"<<fabs(y - x)<<endl;

    while (fabs(y - x) > EPSILON) // x y same hole to z update hbe na, r x y e change hocche ekhane
    {
        z = y - f_y * (y - x) / (f_y - f_x);
        cout << fabs(z - y) << endl;
        x = y;
        f_x = f_y;
        y = z;
        f_y = equation_value(z);
        no_of_iteration++;
    }
    cout << "No of iteration :" << no_of_iteration << endl;
    return z;
}

int main()

{

    cin >> no_of_degree;

    co_efficient_vector.resize(no_of_degree + 1, 0);

    for (int i = 0; i < co_efficient_vector.size(); i++)
    {
        cin >> co_efficient_vector[i];
    }

    // for (int i = 0; i < co_efficient_vector.size(); i++)
    // {
    //     cout<< co_efficient_vector[i]<<" ";
    // }

    float range_a = 0;
    float range_b = 0;
    float c = sqrt((pow((co_efficient_vector[1] / co_efficient_vector[0]), 2) - 2 * (co_efficient_vector[2] / co_efficient_vector[0])));

    range_a = floor(-1 * c);
    range_b = ceil(1 * c);

    vector<ab_pair> pairab;

    pairab.reserve(no_of_degree);

    float temp_a = range_a;
    float temp_b = range_a + 1;

    vector<float> result(no_of_degree, 0);
    int index = 0;

    while (temp_b < range_b + 1)
    {

        if (equation_value(temp_a) == 0)
        {
            result[index++] = equation_value(temp_a);
        }
        if (equation_value(temp_b) == 0)
        {
            result[index++] = equation_value(temp_b);
        }
        if (equation_value(temp_a) * equation_value(temp_b) < 0)
        {
            pairab.push_back({temp_a, temp_b});
        }
        temp_a = temp_b;
        temp_b = temp_b + 1;
    }


    // for (int i = 0; i < pairab.size(); i++)
    // {

    //     result[index++] = scant_method(pairab[i].a, pairab[i].b);
    // }

    // cout << "Roots : ";

    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < no_of_degree; i++)
    {
        // cout<<"check2"<<pairab[i].a<<" "<< pairab[i].b<<endl;

        result[index++] = scant_method(pairab[i].a, pairab[i].b);
        cout<<"gape"<<endl;
    }

    cout << "Roots : ";

    for (int i = 0; i < no_of_degree; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

*/