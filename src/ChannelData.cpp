#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "ChannelData.h"
#include "DataValidator.h"

namespace IneosTest {
	/** Constructor 
		\brief Constructror that parses files for data
		\todo The code below is repetitive, create generic csv data reading functions 
	*/
	ChannelData::ChannelData(const std::string &dataFilename, const std::string &parameterFilename)
	{
		std::ifstream channelInput(dataFilename);
		if (!channelInput.is_open()) 
			throw std::runtime_error("Couldn't read file: " + dataFilename);
		std::string csvLine;
		std::getline(channelInput, csvLine);
		std::stringstream ss(csvLine);
		while (ss.good()) 
		{
			std::string substr;
			std::getline(ss, substr, ',');
			if (substr != "X")
				data_.push_back(std::stod(substr) );
		}
		channelInput.close();

		std::ifstream parameteresInput(parameterFilename);
		if (!parameteresInput.is_open()) 
			throw std::runtime_error("Couldn't read file: " + parameterFilename);
		
		std::string line;
		int linenum = 0;
		while(std::getline(parameteresInput,line))	
		{			
			std::stringstream ss(line);
			while (ss.good()) 
			{
				std::string substr;
				std::getline(ss, substr, ',');
				if ((substr != "m") && (linenum == 0))
					mParameter_ = std::stod(substr);
				if ((substr != "c") && (linenum == 1))
					cParameter_ = std::stod(substr);
			}
			linenum++;
		}
		parameteresInput.close();

		bool validateM = DataValidator::validate_data_value(mParameter_, false);
		bool validateC = DataValidator::validate_data_value(cParameter_, false);
		bool validateData = DataValidator::validate_data_array(data_);
		if (!validateData)
			throw std::range_error("Some of your data points are invalid - over/under flow or inf/nan");
	}
	
	/** Constructor 
	\brief Constructror that processes data array
	*/
	ChannelData::ChannelData(const std::vector<double> &dataArray, const double m, const double c)	
	:
	data_(dataArray),
	mParameter_(m),
	cParameter_(c)
	{
		bool validateM = DataValidator::validate_data_value(mParameter_, false);
		bool validateC = DataValidator::validate_data_value(cParameter_, false);
		bool validateData = DataValidator::validate_data_array(data_);
		if (!validateData)
			throw std::range_error("Some of your data points are invalid - over/under flow or inf/nan");
	}
	
	/**
	 * 	\brief 	Get channel data
	 *	\return vector of data points
	 */
	std::vector<double> ChannelData::get_data() const
	{
		return data_;
	}
   
	/**
	 * 	\brief 	Get m parameter
	 *	\return m parameter
	 */
	double ChannelData::get_m() const
	{
		return mParameter_;
	}
	
	/**
	 * 	\brief 	Get c parameter
	 *	\return c parameter
	 */
	double ChannelData::get_c() const
	{
		return cParameter_;
	}
	
	/**
	 * 	\brief 	Get valid dataValues
	 *	\details The function ignores invalid data points and it can be used to filter data in specified range of values
	 */
	std::vector<double> ChannelData::get_data_in_range(const double lowLimit = std::numeric_limits<double>::min(), const double upLimit = std::numeric_limits<double>::max()) const
	{
		std::vector<double> filteredData;
		for(double dataValue : data_)
		{
			if (DataValidator::check_range(dataValue))
				filteredData.push_back(dataValue);
		}
		return filteredData;
	}
}