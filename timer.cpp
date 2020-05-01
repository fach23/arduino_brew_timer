#include "timer.h"

namespace BrewTimer {

Timer::Timer() : start_time_(0), current_time_(0), active_(false) {}

void Timer::start() 
{
	start_time_ = millis();
	current_time_ = start_time_;
	active_ = true;
}

void Timer::stop() 
{
	start_time_ = 0;
	current_time_ = 0;
	active_ = false;
}

void Timer::update() 
{
	current_time_ = millis();
}

bool Timer::active() const
{
	return active_;
}

unsigned long Timer::elapsedTime() const
{
	return current_time_ - start_time_;
}

} // namespace BrewTimer 
