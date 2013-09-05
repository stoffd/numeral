#ifndef CONVERTER_HPP
#define CONVERTER_HPP


#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include  "ConvertAlg.h"
#include  "MatAlg.h"

namespace velalg {


	class Converter {
	public:
		//Converter(const D2String& power, const units& unit) {};
		//std::string Convert(long value) {
		
		//};


	private:
		D2String 		power;
		//units 			unit;
		ConvertAlg*	calg;
		MatAlg*		malg;

	
	};

}


#endif//CONVERTER_HPP
