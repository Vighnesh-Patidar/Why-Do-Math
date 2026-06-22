#include <stdio.h>
#include <iostream>
#include <cmath>
#include <random>
#include <utility>
#include <vector>

// this is good enough for a basic running code, I am pretty sure I see some issues already but we are going to unravel them as we move on
// Using a pair to define a line Pair<int , int> (slope and intercept)
 

long long counter(std::vector<std::pair<float, float>> lines)// we need all of them here to count effectively
{
	// I'll add logic later on
	return 0;
}


int main()
{
	std::vector<long long> counts;
	//generate the points for a fixed n;
	for(int n = 0; n < 1000000; n++)
	{
		//static allocate the memory
		std::vector<std::pair<float,float>> lines;
		// we need to get a hardware based seed
		std::random_device rd;

		std::mt19937 gen(rd());

		std::uniform_real_distribution<float> full_rand(-1, 1); // the intercept cannot be more than radius
		
		for(int i = 0; i < n-1 ; i++)
		{
			float intercept = full_rand(gen);
			float slope = full_rand(gen)*180.0f; // the slope, right now in degrees, no pi in cpp 17 sadly
			lines[i] = {intercept , slope};
		}
		// Send lines packing to the counter and store the number of pieces
		counts[n] = counter(lines);
	}
	long long probability = 0;
	for(int n=0; n < 1000000; n++)
	{
		probability+= n*counts[n];
	}
	return 0;
}

