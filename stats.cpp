#include "stats.h"
#include "algorithm"
#include "numeric"
namespace Statistics {
Stats Statistics::ComputeStatistics(const std::vector<double>& numList) {
    //Implement statistics here
	Stats statObj;
	double maximum = NAN;
	double minimum = NAN;
    double sum = 0.0;

	if(numList.size() != 0){
	maximum = *max_element(numList.begin(), numList.end());
	minimum = *min_element(numList.begin(), numList.end());
	}
	statObj.max = maximum;
	statObj.min = minimum;
	if (numList.size() != 0) {
    for (const double &i: numList) {
        sum += (double)i;
    }
	}
    statObj.average = sum / numList.size();
	return statObj;
}
} //namespace Statistics
