#ifndef NUMERAL_HPP
#define NUMERAL_HPP


#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include  "Convert.h"
#include  "Algo.h"

namespace velalg {


	class Numeral {
	public:
		std::string operator() ( long val,  ConvertAlg* convertAlg, MatAlg* MatAlg ); 


	private:
		ConvertAlg*	convert;
		MatAlg*		algo;
	
	};

}


#endif//NUMERAL_HPP
