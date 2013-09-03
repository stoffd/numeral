#ifndef CONVERTER_HPP
#define CONVERTER_HPP


#include <string>
#include  "convert_alg.hpp"
#include  "mat_alg.hpp"
namespace velalg {


	template<typename T>
	class converter {
	public:
		converter(const d2_string& power, const units& unit) {};
		std::string convert(T value) {
		
		};

	private:
		d2_string 	power;
		units 		unit;
		convert_alg calg;
		mat_alg		malg;

	
	};

}


#endif//CONVERTER_HPP
