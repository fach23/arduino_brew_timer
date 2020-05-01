#ifndef BREWTIMER_TIMER_H
#define BREWTIMER_TIMER_H

#include "Arduino.h"

namespace BrewTimer{

class Timer {
public:
	// Constructs timer instance.
	Timer();

	// Starts the timer.
	void start();

	// Updates the current time.
	void update();

	// Stops and resets the timer.
	void stop();

	// Returns the elapsed time in milliseconds.
	unsigned long elapsedTime() const;

	// Returns timer status.
	bool active() const;

private:
	unsigned int start_time_;
	unsigned int current_time_;
	bool active_;
};

} // namespace BrewTimer
#endif // BREWTIMER_TIMER_H
