#ifndef CONVERT_ALG_HPP
#define CONVERT_ALG_HPP

#include <gtest/gtest.h>
#include  "struct.hpp"

namespace velalg {



	class convert_alg {
	public:
		virtual void phrase_base_init(power_numeral_list& pl, unit_numeral_list& ul) =0;
		virtual std::string get_numeral() =0;
	
	};
//--------------------------
//--------------------------------
//---------------------------------



	class rus_alg : public convert_alg {

	public:

		rus_alg(){
		
		};


		virtual void phrase_base_init( 
				power_numeral_list& pl,
				unit_numeral_list& ul ) { 



		};

		virtual std::string get_numeral() {
		
		};


	private:


	
	};



//--------------------------
//--------------------------------
//---------------------------------
	class convert {
	public:

		convert() {
//phrase_base_init
		
		};


		std::string get_numeral() const {
		
		};

	private:
		convert_alg* conv_alg;
		power_numeral_list 	pow_list;
		unit_numeral_list	un_list;

	};

}

#endif//CONVERT_ALG_HPP
