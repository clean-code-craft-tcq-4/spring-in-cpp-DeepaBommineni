#include "stats.h"
#include "algorithm"
#include "numeric"
namespace Statistics {
Stats ComputeStatistics(const std::vector<double>& numList) {
    //Implement statistics here
	Stats statObj;
	double maximum = 0.0;
	double minimum = 0.0;
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
