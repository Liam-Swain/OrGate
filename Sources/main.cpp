#include <iostream>
#include <random>
#include <math.h>
double weight1[] = { (double)rand() / RAND_MAX };
double weight2[] = { (double)rand() / RAND_MAX };
double weight3[] = { (double)rand() / RAND_MAX, (double)rand() / RAND_MAX };
double bias1 = (double)rand() / RAND_MAX;
double bias2 = (double)rand() / RAND_MAX;
double bias3 = (double)rand() / RAND_MAX;
double lr = 0.03;

double activationLayer(double input)
{
	double output;

	output = (1 / (1 + pow(2.71828, -input)));

	return output;
}

double getTotalError(double output, double expected)
{
	return (-1 * (expected - output));
}

double getDerivative(double input)
{
	double fx;

	fx = (1 / (1 + pow(2.71828, -input)));

	return (fx * (1 - fx));
}


void outputLayer(double input1, double input2, double expected)
{
	double active1 = input1 * weight3[0] + input2 * weight3[1] + bias3;
	double output = activationLayer(active1);
	double error;
	double derOutput1;
	error = getTotalError(output, expected);
	derOutput1 = getDerivative(active1);


	weight3[0] = weight3[0] - lr * (error * derOutput1 * input1);
	weight3[1] = weight3[1] - lr * (error * derOutput1 * input2);
	bias3 = bias3 - lr * (error * derOutput1 * bias3);

	if (output > 0.6)
		output = 1;
	else if (output <= 0.5)
		output = 0;
}


int main()
{
	int x;
	int y;
	for (int i = 0; i < 10; i++)
	{
		outputLayer(1, 1, 1);
		outputLayer(1, 0, 1);
		outputLayer(0, 1, 1);
		outputLayer(0, 0, 0);
	}

	std::cout << "ENTER IN YOUR NUMBERS" << std::endl;
	std::cin >> x;
	std::cin >> y;

	double output = x * weight3[0] + y * weight3[1] + bias3;
	output = activationLayer(output);


	if (output > 0.6)
		output = 1;
	else if (output <= 0.6)
		output = 0;

	std::cout << output << std::endl;

	return 0;
}
