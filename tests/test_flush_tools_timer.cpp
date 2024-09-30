#include "Timer.hpp"
#include <gtest/gtest.h>
#include <thread>
#include <chrono>

TEST(TimerTest, Run) {
  int duration = 10; // 10 seconds
  Timer timer(duration); // Initialize the timer with the specified duration

  // Define a work callback function
  std::function<void()> work_callback = []() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Work callback executed\n";
  };

  // Run the timer with the work callback
  timer.run(work_callback);

  // Check if the timer finished after the specified duration
  EXPECT_EQ(timer.get_elapsed(), duration + 1);
}

TEST(TimerTest, Reset) {
  Timer timer(10); // Initialize the timer with the specified duration

  // Run the timer once
  timer.run([]() {});

  // Reset the timer with a new duration
  int new_duration = 5; // 5 seconds
  timer.reset(new_duration);

  // Run the timer again
  timer.run([]() {});

  // Check if the timer finished after the new duration
  EXPECT_EQ(timer.get_elapsed(), new_duration);
}

TEST(TimerTest, IsFinished) {
  Timer timer(10); // Initialize the timer with the specified duration

  // Check if the timer is not finished initially
  EXPECT_FALSE(timer.is_finished());

  // Run the timer for 10 seconds
  std::this_thread::sleep_for(std::chrono::seconds(10));

  // Check if the timer is finished after 10 seconds
  EXPECT_TRUE(timer.is_finished());

  EXPECT_EQ(timer.get_elapsed(), 10);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

