#ifndef CONVERT_ALG_HPP
#define CONVERT_ALG_HPP

#include  "struct.hpp"

namespace velalg {


	class convert_alg {
		virtual short get_convert_power() const = 0; 
		virtual short get_convert_unit() const = 0; 
	};

	class rus_alg : public convert_alg {
	public:
		rus_alg(){
		
		};


		virtual short get_convert_power() const {

			return 0;
		}; 

		virtual short get_convert_unit() const {
			return 0;
		}; 
		virtual ~rus_alg() {};
	private:
	
	};


	class eng_alg : public convert_alg {

	public:
		eng_alg () {
		
		};

		virtual short get_convert_power() const {

			return 0;
		}; 

		virtual short get_convert_unit() const {
			return 0;
		}; 

		virtual ~eng_alg() {};

	private:
	
	};


}

#endif//CONVERT_ALG_HPP
