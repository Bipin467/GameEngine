#include "Public/Time.h"

Time::Time()
	:m_DeltaTime(0)
{
	m_TimerRefBase = std::chrono::system_clock::now();
	m_StartTime = std::chrono::system_clock::now();
}

Time& Time::GetInstance()
{
	static Time& t = *(new Time());
	return t;
}

float Time::DeltaTime()
{
	return GetInstance().m_DeltaTime;
}



float Time::TimeScale = 1.0f;

void Time::GameLoopEnd() {
	Time& t = Time::GetInstance();
	auto currentChronoTime = std::chrono::system_clock::now();
	std::chrono::duration<double> ellapsed_seconds = currentChronoTime-t.m_TimerRefBase;
	t.m_DeltaTime = (double)(ellapsed_seconds.count())*TimeScale;
	t.m_Time += t.m_DeltaTime;
	t.m_HighPrecisionTime += ellapsed_seconds.count()*TimeScale;
	t.m_TimerRefBase = currentChronoTime;
}

float Time::GameTime() {
	return GetInstance().m_Time;
}

double Time::HighPrecisionGameTime() {
	return GetInstance().m_HighPrecisionTime;
}

float Time::RealUnscaledGameTime()
{
	Time& t = Time::GetInstance();
	std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
	std::chrono::duration<float> ellapsed_seconds = currentTime - t.m_StartTime;
	return ellapsed_seconds.count();
}

double Time::RealUnscaledHighPrecisionGameTime()
{
	Time& t = Time::GetInstance();
	std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
	std::chrono::duration<double> ellapsed_seconds = currentTime - t.m_StartTime;
	return ellapsed_seconds.count();
}
