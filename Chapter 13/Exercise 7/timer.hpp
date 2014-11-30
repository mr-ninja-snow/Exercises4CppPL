#include <sys/time.h>	//used for timing functions

#ifndef TIMER_HPP
#define TIMER_HPP

namespace vTimer{

	class Timer
	{
	public:
		Timer();

		void startTimer();
		void stopTimer();

		float getResult();

	private:
		struct timeval m_startTime;
		struct timeval m_endTime;
	};

}

#endif