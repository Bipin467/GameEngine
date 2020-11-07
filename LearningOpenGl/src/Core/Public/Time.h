#pragma once
#include <chrono>

class Time {
private:
	Time();
private:
	std::chrono::system_clock::time_point m_TimerRefBase, m_StartTime;
	float m_Time, m_DeltaTime;
	double m_HighPrecisionTime;
public:
	static float TimeScale;
public:
	static Time& GetInstance();
	static void GameLoopEnd();
	static float DeltaTime();
	static float GameTime();
	static double HighPrecisionGameTime();
	static float RealUnscaledGameTime();
	static double RealUnscaledHighPrecisionGameTime();
};