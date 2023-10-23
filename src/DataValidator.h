#ifndef DATA_VALIDATOR_H
#define DATA_VALIDATOR_H
#include <vector>
#include <limits>

namespace IneosTest {
	/**
	 * 	\brief 		Data validator class
	 *	\details 	Class is equipped with methods that validate data,
	 *				these methods mimic mathematical analysis principle in
	 *				terms of checking for data domain and range. Class also
	 *				has methods that check for nans and infs.
	 *	\todo		This is currently a class of static-only methods and does not need
					to be class (it could be a library of global utility functions),
					however the aim of this implementation is the possiblity to extend
					this class further and allow it to test more complex objects.
	 *	\todo 		Consider templating some methods in order to support different data types etc.
	 */
	class DataValidator
	{
		public:

			/**
			 * 	\brief 	Check if data value is within range of values
			 */
			static bool check_range(const double dataValue, const double lowLimit = std::numeric_limits<double>::min(), const double upLimit = std::numeric_limits<double>::max());
			
			/**
			 * 	\brief 	Check if data value is nan (not a number)
			 */
			
			static bool is_nan(const double dataValue);
			/**
			 * 	\brief 	Check if data value is inf (infty)
			 */
			static bool is_inf(const double dataValue);
			
			/**
			 * 	\brief 	Validate double data type value
			 *	\details Checks if dataValue is not under/overflowing and is not nan/inf
			 */
			static bool validate_data_value(const double dataValue, const bool ignoreInvalidData);
			
			/**
			 * 	\brief 	Check if all data values in data array are within given range of values and not inf/nan
			 */
			static bool validate_data_array(const std::vector<double> &data, const bool ignoreInvalidData = false, const double lowLimit = std::numeric_limits<double>::min(), const double upLimit = std::numeric_limits<double>::max());
	};
}
#endif // DATA_VALIDATOR_H