#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "processes.cpp"

/*Using a pseudo random number generation function (e.g., rand() in C or other
equivalent functions in other languages) that generates uniformly distributed random
numbers, generate a workload for a system that is composed of 1000 processes. You
can assume that processes arrive with an expected average arrival rate of 2 processes
per second that follows a Poisson Distribution and the service time (i.e., requested
duration on the CPU) for each process follows an Exponential Distribution with an
expected average service time of 1 second. Your outcome would be printing out a list
of tuples in the format of <process ID, arrival time, requested service time>.
You can assume that process IDs are assigned incrementally when processes arrive
and that they start at 1.*/

const size_t NUM_PROCESSES = 1000;
const double AVG_ARRIVAL_RATE = 2.0; // average processes per second
const double AVG_SERVICE_RATE = 1.0; // average seconds per process

using namespace std;

int main() {
    
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    double current_time = 0.0; // Track the current time for process arrivals

    // generate system workload
    vector<processes::Process> workload;
    vector<double> arrival_times;

    for (size_t i = 0; i < NUM_PROCESSES; ++i) {
        processes::Process proc(i + 1, AVG_ARRIVAL_RATE, AVG_SERVICE_RATE); // Create a new process with the specified average arrival and service times

        current_time += proc.getInterarrivalTime();
        workload.push_back(proc); // Add the process to the workload vector
        arrival_times.push_back(current_time);
    }
    // print the workload
    for (size_t i = 0; i < NUM_PROCESSES; ++i) {
        workload[i].printProcess(arrival_times[i]);
    }

    // Calculate actual averages
    double total_service_time = 0.0;
    for (const auto& proc : workload) {
        total_service_time += proc.getServiceTime();
    }
    double actual_avg_service_time = total_service_time / NUM_PROCESSES;
    double total_time = arrival_times.back();
    double actual_avg_arrival_rate = NUM_PROCESSES / total_time;

    // Print actual averages
    cout << "\nActual average arrival rate: " << actual_avg_arrival_rate << " processes per second" << endl;
    cout << "Actual average service time: " << actual_avg_service_time << " seconds" << endl;

    return 0;
}