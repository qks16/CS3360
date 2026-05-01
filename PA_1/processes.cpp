#include <iostream>
#include <cmath>

namespace processes {
    class Process {
    private:
        size_t id;
        double arrival_time;
        double service_time;
        double interarrival_time;
    public:
        Process(size_t identity, double avg_arrival_time, double avg_service_time, double current_time) {
            id = identity;
            interarrival_time = -log((rand() + 1.0) / (RAND_MAX + 1.0)) / avg_arrival_time; // Exponential interarrival time
            service_time = -log((rand() + 1.0) / (RAND_MAX + 1.0)) / avg_service_time; // Exponential service time
            arrival_time = 0.0; // Will be set in main based on interarrival time and current time
        }

        void setID(size_t new_id) {
            id = new_id;
        }

        void setArrivalTime(double new_arrival_time) {
            arrival_time = new_arrival_time;
        }
        
        double getArrivalTime() const {
            return arrival_time;
        }

        double getinterarrivalTime() const {
            return interarrival_time;
        }

        void printProcess() const {
            std::cout << "<" << id << ", " << arrival_time << ", " << service_time << ">" << std::endl;
        }
    };
}

