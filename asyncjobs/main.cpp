#include "JobSystem/JobSystem.h"
#include <future>
#include <chrono>
#include <iostream>
#include <cmath>

JobSystem jobsystem;

void samplefunction(Job job)
{
    int core = 100 * std::sin(std::sqrt(rand()));
    srand(core);
    std::cout << std::asinh(core * std::sqrt(core + 1)) << std::endl;

    return;
}

void print(Job job)
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
	}
	std::cout << "Job done\n";
	return;
}


int main()
{
    Job job = jobsystem.createJob(samplefunction);
    std::array<std::future<void>, 1000> futureslist;
    std::chrono::high_resolution_clock::time_point t;

    //Async Test
    auto asynctest = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 1000; ++i)
    {
        futureslist.at(i) = std::async(samplefunction, job);
    }
    
    for(auto& f : futureslist)
    {
        f.get();
    }

    t = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> asynctestend = std::chrono::duration_cast<std::chrono::duration<double>>(t - asynctest);
    
    // JobSystem Test
    auto jobtest = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        jobsystem.schedule(job);
    }
    jobsystem.wait(0);

    t = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> jobtestend = std::chrono::duration_cast<std::chrono::duration<double>>(t - jobtest);

    std::cout << "BENCHMARK RESULTS: \n";
    std::cout << "\tstd::async results: " << asynctestend.count() << "ns\n";
    std::cout << "\tJob System results: " << jobtestend.count() << "ns\n";
    
    // Apparently, std::async DOES lose

    return 0;
}