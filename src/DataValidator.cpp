#include <cmath>
#include <stdexcept>
#include "DataValidator.h"

namespace IneosTest {
	
	/**
	 * 	\brief 	Check if data value is within range of values
	 */
	bool DataValidator::check_range(const double dataValue, const double lowLimit, const double upLimit)
	{
		if ((std::abs(dataValue) < lowLimit) && (std::abs(dataValue) > upLimit))
			return false;
		return true;
	}
	
	/**
	 * 	\brief 	Check if data value is nan (not a number)
	 */
	bool DataValidator::is_nan(const double dataValue)
	{
		return std::isnan(dataValue);
	}
	
	/**
	 * 	\brief 	Check if data value is inf (infty)
	 */
	bool DataValidator::is_inf(const double dataValue)
	{
		return std::isinf(dataValue);
	}
		
	/**
	 * 	\brief 	Validate double data type value
	 *	\details Checks if dataValue is not under/overflowing and is not nan/inf
	 */
	bool DataValidator::validate_data_value(const double dataValue, const bool ignoreInvalidData)
	{
		bool isValid = false;
		
		if (check_range(dataValue))
			isValid = true;
		else if (!ignoreInvalidData)
			throw std::range_error("The input value exceeds double data type limits");
				
		if (!is_nan(dataValue))
			isValid = true;
		else if (!ignoreInvalidData)
			throw std::range_error("The input is NaN");
		
		if (!is_inf(dataValue))
			isValid = true;
		else if (!ignoreInvalidData)
			throw std::range_error("The input value is +-Inf");
		
		return isValid;
	}
	
	/**
	 * 	\brief 	Check if all data values in data array are within given range of values and not inf/nan
	 */
	bool DataValidator::validate_data_array(const std::vector<double> &data, const bool ignoreInvalidData, const double lowLimit, const double upLimit)
	{
		bool isDataValid = false;
		for(double dataValue : data)
			isDataValid = validate_data_value(dataValue, ignoreInvalidData);
		return isDataValid;
	}
}