#ifndef PROCESSING_SYSTEM_H
#define PROCESSING_SYSTEM_H

#include "ChannelData.h"

namespace IneosTest {
	/**
	 * 	\brief Processing system class
	 *	\details Class that processess channel data 
	 *	\todo Consider simplifying the code, functions  1 and 3 are redundant unless their outputs are of specific interest
	 *	\todo Add functionality to ignore faulty data - over/underflows and nans and infs.
	 */
	class ProcessingSystem
	{
		private:
			ChannelData data_;		// Channel data
		
		public:
			/**
			 * 	\brief 	Function 1
			 */
			std::vector<double> calculate_Y() const;
			
			/**
			 * 	\brief 	Function 2
			 */
			double	calculate_b() const;
			
			/**
			 * 	\brief 	Function 3
			 */
			std::vector<double> calculate_A() const;
			
			/**
			 * 	\brief 	Function 4
			 */
			std::vector<double> calculate_C() const;

			/** Constructor 
				\brief Constructror that loads data in ChannelData object
			*/
			ProcessingSystem(const ChannelData &data);
	};
}
#endif // PROCESSING_SYSTEM_H