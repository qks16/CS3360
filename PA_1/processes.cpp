#include <iostream>
#include <cmath>
#include <cstdlib>

namespace processes {
    class Process {
    private:
        size_t id;
        double service_time;
        double interarrival_time;
    public:
        Process(size_t identity, double avg_arrival_time, double avg_service_time) {
            id = identity;
            interarrival_time = -log((rand() + 1.0) / (RAND_MAX + 1.0)) / avg_arrival_time; // Exponential interarrival time
            service_time = -log((rand() + 1.0) / (RAND_MAX + 1.0)) / avg_service_time; // Exponential service time
        }

        double getInterarrivalTime() const {
            return interarrival_time;
        }

        void printProcess(double arrival_time) const {
            std::cout << "<" << id << ", " << arrival_time << ", " << service_time << ">" << std::endl;
        }
    };
}

