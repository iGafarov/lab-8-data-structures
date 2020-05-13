 #pragma once
#include <vector>
#include <iostream>
#include <cstdio>
#include <chrono>
#include "OrderedVector.h"
#include "AVLTree.h"
#include "UnorderedSet.h"
template<class T>
void Clock(T& collection, int step) {
	int accuracy = 10;
	int number_of_sizes = 10;
	std::vector<int> sizes;
	for (int i = 1; i <= number_of_sizes; ++i) {
		sizes.push_back(step * i);
	}
	double full_time = 0.0;
	double average_time = 0.0;
	std::vector<double> insert_time;
	std::vector<double> contains_time;
	std::vector<double> remove_time;
	for (int k = 0; k < number_of_sizes; ++k)
	{
		for (size_t j = 0; j < accuracy; ++j)
		{
			auto start = std::chrono::steady_clock::now();
			for (int i = 0; i < sizes[k]; ++i)
			{
				collection.Insert(rand() % sizes[k]);
			}
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> duration = end - start;
			insert_time.push_back(duration.count());

			start = std::chrono::steady_clock::now();
			for (int i = 0; i < sizes[k]; ++i)
			{
				collection.Contains(rand() % sizes[k]);
			}
			end = std::chrono::steady_clock::now();
			duration = end - start;
			contains_time.push_back(duration.count());


			start = std::chrono::steady_clock::now();
			for (int i = 0; i < sizes[k]; ++i)
			{
				collection.Remove(rand() % sizes[k]);
			}
			end = std::chrono::steady_clock::now();
			duration = end - start;
			remove_time.push_back(duration.count());
		}

		std::cout << "Size: " << sizes[k] << std::endl;

		for (auto i : insert_time) full_time += i;
		average_time = full_time / accuracy;
		std::cout << "    Insert time: " << average_time * 1000000 << " us" << std::endl;

		full_time = 0.0;
		average_time = 0.0;

		for (auto i : contains_time) full_time += i;
		average_time = full_time / accuracy;
		std::cout << "    Contains time: " << average_time * 1000000 << " us" << std::endl;

		full_time = 0.0;
		average_time = 0.0;

		for (auto i : remove_time) full_time += i;
		average_time = full_time / accuracy;
		std::cout << "    Remove time: " << average_time * 1000000 << " us" << std::endl;

		full_time = 0.0;
		average_time = 0.0;
		insert_time.clear();
		contains_time.clear();
		remove_time.clear();		
	}
}
