#ifndef CONVERT_ALG_HPP
#define CONVERT_ALG_HPP

#include <gtest/gtest.h>
#include <memory>
#include  "struct.hpp"

namespace velalg {



	class convert_alg {
	public:
		virtual void phrase_base_init(power_numeral_list& pl, unit_numeral_list& ul) =0;
		virtual std::string get_numeral(const short power, const short unit, const short grade) const =0;
	
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

			std::vector<std::string> v1;
			std::vector<std::string>::iterator it;

			power_numeral_list::iterator nl_it;

			v1.push_back("тысяча "); v1.push_back("тысячи "); v1.push_back("тысяч ");
			pl.push_back( ( struct power_numeral_struct) {FEM,v1} );
			v1.clear();


			v1.push_back("миллион "); v1.push_back("миллиона "); v1.push_back("миллионов ");
			pl.push_back( ( struct power_numeral_struct) {FEM,v1} );
			v1.clear();

			v1.push_back("миллиард "); v1.push_back("миллиарда "); v1.push_back("миллиардов ");
			pl.push_back( ( struct power_numeral_struct) {FEM,v1} );
			v1.clear();


//--------------------------
			d2_string 			d2v_masc, d2v_fem;
			d2_string::iterator d2it_masc, d2itv_fem;

			v1.push_back("один "); v1.push_back("два "); v1.push_back("три ");
			v1.push_back("четыре "); v1.push_back("пять "); v1.push_back("шесть ");
			v1.push_back("семь "); v1.push_back("восемь "); v1.push_back("девять "); 
			d2v_masc.push_back(v1);
			v1.clear();


			v1.push_back("одна "); v1.push_back("две "); v1.push_back("три ");
			v1.push_back("четыре "); v1.push_back("пять "); v1.push_back("шесть ");
			v1.push_back("семь "); v1.push_back("восемь "); v1.push_back("девять "); 
			d2v_fem.push_back(v1);
			v1.clear();


			v1.push_back("одиннадцать "); v1.push_back("двенадцать "); v1.push_back("тринадцать ");
			v1.push_back("четырнадцать "); v1.push_back("пятьнадцать "); v1.push_back("шестнадцать ");
			v1.push_back("семнадцать "); v1.push_back("восемнадцать "); v1.push_back("девятнадцать "); 
			d2v_masc.push_back(v1);
			d2v_fem.push_back(v1);
			v1.clear();


			v1.push_back("десять "); v1.push_back("двадцать "); v1.push_back("тридцать ");
			v1.push_back("сорок "); v1.push_back("пятьдесят "); v1.push_back("шестьдесят ");
			v1.push_back("семьдесят "); v1.push_back("восемьдесят "); v1.push_back("девяносто "); 
			d2v_masc.push_back(v1);
			d2v_fem.push_back(v1);
			v1.clear();


			v1.push_back("сто "); v1.push_back("двести "); v1.push_back("триста ");
			v1.push_back("четыреста "); v1.push_back("пятьсот "); v1.push_back("шестьсот ");
			v1.push_back("семьсот "); v1.push_back("восемьсот "); v1.push_back("девятьсот "); 
			d2v_masc.push_back(v1);
			d2v_fem.push_back(v1);
			v1.clear();
			
			ul[MASCUL] = d2v_masc;
			ul[FEM] = d2v_fem;
			

		};

		virtual std::string get_numeral(const short power, const short unit, const short grade) const {
			return (std::string)("ничего");
		};

		~rus_alg(){};


	private:


	
	};



//--------------------------
//--------------------------------
//---------------------------------
	class convert {
	public:

		convert(convert_alg& conv_alg) {
			this->conv_alg = &conv_alg;
			init();

		};

		void init() {
			conv_alg->phrase_base_init(pow_list, un_list);
		};


		std::string get_numeral(const short power, const short unit, const short grade) const{
			return conv_alg->get_numeral(power, unit, grade);
		};


	private:
		convert_alg* conv_alg;
		power_numeral_list 	pow_list;
		unit_numeral_list	un_list;

	};

}


TEST( convert_algTest, testone) {

	std::auto_ptr<velalg::convert_alg> al_ru (new velalg::rus_alg() );
	velalg::convert cnvrt (*al_ru.get() );
	
	std::cout<<cnvrt.get_numeral(0,0,0)<<std::endl;
	ASSERT_STREQ( (cnvrt.get_numeral(0,0,0)).c_str(), "ноль" );
	ASSERT_STREQ( (cnvrt.get_numeral(1,3,1)).c_str(), "тридцать " );

}




#endif//CONVERT_ALG_HPP
