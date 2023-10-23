#include <algorithm>
#include <functional>
#include "ProcessingSystem.h"
#include "DataValidator.h"
#include "Utility.h"

namespace IneosTest {
	
	/** Constructor 
		\brief Constructror that loads data in ChannelData object
	*/
	ProcessingSystem::ProcessingSystem(const ChannelData &data)
	:
	data_(data)
	{}
		
	/**
	 * 	\brief 	Function 1
	 */
	std::vector<double> ProcessingSystem::calculate_Y() const
	{
		double m = data_.get_m();
		double c =  data_.get_c();
		std::vector<double> Y = data_.get_data();
		for(double &YValue : Y)
			YValue = m*YValue + c;
		
		DataValidator::validate_data_array(Y);	
		return Y;
	}
	
	/**
	 * 	\brief 	Function 2
	 */
	double	ProcessingSystem::calculate_b() const
	{
		std::vector B = calculate_A() + calculate_Y();
		DataValidator::validate_data_array(B);
		double b = std::accumulate(std::begin(B), std::end(B), 0.0) / B.size();
		DataValidator::validate_data_value(b, false);
		return 	b;
	}
	
	/**
	 * 	\brief 	Function 3
	 */
	std::vector<double> ProcessingSystem::calculate_A() const
	{
		std::vector<double> A = data_.get_data();
		for(double &AValue : A)
			AValue = 1.0 / AValue;

		DataValidator::validate_data_array(A);	
		return A;
	}
	
	/**
	 * 	\brief 	Function 4
	 */
	std::vector<double> ProcessingSystem::calculate_C() const
	{
		std::vector<double> C = data_.get_data() ;
		double b = calculate_b();
		for(double CValue : C)
			CValue += b;
		DataValidator::validate_data_array(C);	
		return C;
	}
}