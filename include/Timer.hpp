#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <chrono>
#include <functional>
#include <thread>

class Timer {
public:
    Timer() : duration(0), start_time(std::chrono::steady_clock::now()) {}

    Timer(int duration) : duration(duration), start_time(std::chrono::steady_clock::now()) {}

    void reset(int new_duration) {
        if (new_duration < 0) {
            throw std::invalid_argument("Timer duration cannot be negative");
        }
        duration = new_duration;
        start_time = std::chrono::steady_clock::now();
    }

    bool is_finished() const {
        return get_elapsed() >= duration;
    }

    double get_elapsed() const {
        auto now = std::chrono::steady_clock::now();
        auto time_difference = now - start_time;
        return std::chrono::duration_cast<std::chrono::seconds>(time_difference).count();
    }

    void run(std::function<void()> work_callback) {
        if (!work_callback) {
            throw std::invalid_argument("work_callback cannot be null");
        }

        start_time = std::chrono::steady_clock::now(); // Update start_time to current time
        while (!is_finished()) {
            std::cout << "Timer: " << get_elapsed() << " Seconds passed\n";

            try {
                work_callback();
            } catch (const std::exception &e) {
                std::cerr << "Exception in work_callback: " << e.what() << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "Timer finished after " << duration << " Seconds.\n";
    }

private:
    int duration;
    std::chrono::time_point<std::chrono::steady_clock> start_time;
};

#endif // TIMER_HPP

