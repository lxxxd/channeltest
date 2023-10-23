#ifndef CHANNEL_DATA_H
#define CHANNEL_DATA_H
#include <string>
#include <vector>
#include <limits>

namespace IneosTest {
	/**
	 * 	\brief Channel Data class
	 *	\details Class that loads channel data either from a file or array of vaalues.
	 *	\todo 	Allow class to ignore invalid data?
	 */
	class ChannelData
	{
		private:
			std::vector<double> data_;
			double mParameter_;
			double cParameter_;
					
		public:
			/**
			 * 	\brief 	Get channel data
			 *	\return vector of data points
			 */
			std::vector<double> get_data() const;
		   
		   /**
			 * 	\brief 	Get m parameter
			 *	\return m parameter
			 */
			double get_m() const;
			
			/**
			 * 	\brief 	Get c parameter
			 *	\return c parameter
			 */
			double get_c() const;
			
			/**
			 * 	\brief 	Get dataValues in certain range
			 *	\details The function filters data in specified range of values
			 */
			std::vector<double> get_data_in_range(const double lowLimit, const double upLimit) const;
				
		
			/** Constructor 
				\brief Constructror that parses files for data
			*/
			ChannelData(const std::string &dataFilename, const std::string &parameterFilename);
			
			/** Constructor 
			\brief Constructror that processes data array
			*/
			ChannelData(const std::vector<double> &dataArray, const double m, const double c);
	};
}
#endif // CHANNEL_DATA_H