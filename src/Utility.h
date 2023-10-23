#ifndef UTILITY_H
#define UTILITY_H

#include <algorithm>
#include <functional>
#include <stdexcept>

namespace IneosTest {
	

	/** \brief Overload + operator for element wise addition of std::vector<T> vectors
	*
	*	\todo std::vector<T> is not the best choice for handling arrays of numerical data,
	*	consider using available libraries as Armadillo, Boost. 
	*	std::vallarray<double> could serve a purpose, but its support/developement has been discontinued,
	*	owing to powerfull array alternatives.
	*
	**/
	template <typename T>
	std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b)
	{
		if (a.size() != b.size())
			throw std::length_error("These two vectors cannot be added element wise, their sizes are different");
		std::vector<T> result;
		result.reserve(a.size());
		std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(result), std::plus<T>());
		return result;
	}
	
	/** \brief Overload - operator for element wise subtraction of std::vector<T> vectors
	*
	*	\todo Consider using available libraries as Armadillo, Boost for better array types
	*
	**/
	template <typename T>
	std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b)
	{
		if (a.size() != b.size())
			throw std::length_error("These two vectors cannot be added element wise, their sizes are different");
		std::vector<T> result;
		result.reserve(a.size());
		std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(result), std::minus<T>());
		return result;
	}
	
	/** \brief Overload * operator for for element wise multiplication of std::vector<T> vectors
	*
	*	\todo Consider using available libraries as Armadillo, Boost for better array types
	*
	**/
	template <typename T>
	std::vector<T> operator*(const std::vector<T>& a, const std::vector<T>& b)
	{
		if (a.size() != b.size())
			throw std::length_error("These two vectors cannot be added element wise, their sizes are different");
		std::vector<T> result;
		result.reserve(a.size());
		std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(result), std::multiplies<T>());
		return result;
	}

	/** \brief Overload / operator for element wise division of std::vector<T> vectors
	*
	*	\todo Consider using available libraries as Armadillo, Boost for better array types
	*
	**/
	template <typename T>
	std::vector<T> operator/(const std::vector<T>& a, const std::vector<T>& b)
	{
		if (a.size() != b.size())
			throw std::length_error("These two vectors cannot be added element wise, their sizes are different");
		std::vector<T> result;
		result.reserve(a.size());
		std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(result), std::divides<T>());
		return result;
	}
}
#endif // UTILITY_H