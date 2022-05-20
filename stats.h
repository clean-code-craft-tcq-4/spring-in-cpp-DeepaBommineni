#include <vector>
#include "algorithm"
#include "numeric"
namespace Statistics {
class Stats {
	public:
		double average, min, max;
};
    Stats ComputeStatistics(const std::vector<double>& numList);
} // namespace Statistics

class IAlerter
{};
class EmailAlert:public IAlerter
{
	public:
		EmailAlert():emailSent(false){}
		bool emailSent;
};
class LEDAlert:public IAlerter
{
	public:
		LEDAlert():ledGlows(false){}
		bool ledGlows;
};

class StatsAlerter {
	public:
	    StatsAlerter(const float maxThreshold, std::vector<IAlerter*>& alerters):m_maxThreshold(maxThreshold), m_alerters(alerters){}

		void checkAndAlert(std::vector<double> alerters) {
	        double value = *max_element(alerters.begin(),alerters.end());
			if (value > m_maxThreshold) {
				emailAlert.emailSent = true;
				ledAlert.ledGlows = true;
			}
	    }
    public:
		const float m_maxThreshold;
		std::vector<IAlerter*> m_alerters;
		EmailAlert emailAlert;
		LEDAlert ledAlert;
};
