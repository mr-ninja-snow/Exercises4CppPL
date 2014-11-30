#include "timer.hpp"

namespace vTimer{

	Timer::Timer()
	{
		gettimeofday(&m_startTime, nullptr);
		m_endTime = m_startTime;
	}

	void Timer::startTimer()
	{
		gettimeofday(&m_startTime, nullptr);
	}

	void Timer::stopTimer()
	{
		gettimeofday(&m_endTime, nullptr);
	}

	float Timer::getResult()
	{
		// get difference, multiply by 1E-6 to convert to seconds
		return (m_endTime.tv_sec - m_startTime.tv_sec) + (m_endTime.tv_usec - m_startTime.tv_usec) * 1E-6; 
	}

}