#include "./include/ConvertAlg.h"



namespace velalg {



	void RusAlg::phraseBaseInit( 
			PowerNumeralList& pl,
			UnitNumeralList& ul ) { 

		std::vector<std::string> v1;
		std::vector<std::string>::iterator it;

		PowerNumeralList::iterator nlIt;

		v1.push_back("тысяча "); v1.push_back("тысячи "); v1.push_back("тысяч ");
		pl.push_back( ( struct PowerNumeralStruct) {FEM,v1} );
		v1.clear();


		v1.push_back("миллион "); v1.push_back("миллиона "); v1.push_back("миллионов ");
		pl.push_back( ( struct PowerNumeralStruct) {FEM,v1} );
		v1.clear();

		v1.push_back("миллиард "); v1.push_back("миллиарда "); v1.push_back("миллиардов ");
		pl.push_back( ( struct PowerNumeralStruct) {FEM,v1} );
		v1.clear();


//--------------------------
		D2String 			d2vMasc, d2vFem;
		D2String::iterator d2itMasc, d2itFem;

		v1.push_back("один "); v1.push_back("два "); v1.push_back("три ");
		v1.push_back("четыре "); v1.push_back("пять "); v1.push_back("шесть ");
		v1.push_back("семь "); v1.push_back("восемь "); v1.push_back("девять "); 
		d2vMasc.push_back(v1);
		v1.clear();


		v1.push_back("одна "); v1.push_back("две "); v1.push_back("три ");
		v1.push_back("четыре "); v1.push_back("пять "); v1.push_back("шесть ");
		v1.push_back("семь "); v1.push_back("восемь "); v1.push_back("девять "); 
		d2vFem.push_back(v1);
		v1.clear();


		v1.push_back("одиннадцать "); v1.push_back("двенадцать "); v1.push_back("тринадцать ");
		v1.push_back("четырнадцать "); v1.push_back("пятьнадцать "); v1.push_back("шестнадцать ");
		v1.push_back("семнадцать "); v1.push_back("восемнадцать "); v1.push_back("девятнадцать "); 
		d2vMasc.push_back(v1);
		d2vFem.push_back(v1);
		v1.clear();


		v1.push_back("десять "); v1.push_back("двадцать "); v1.push_back("тридцать ");
		v1.push_back("сорок "); v1.push_back("пятьдесят "); v1.push_back("шестьдесят ");
		v1.push_back("семьдесят "); v1.push_back("восемьдесят "); v1.push_back("девяносто "); 
		d2vMasc.push_back(v1);
		d2vFem.push_back(v1);
		v1.clear();


		v1.push_back("сто "); v1.push_back("двести "); v1.push_back("триста ");
		v1.push_back("четыреста "); v1.push_back("пятьсот "); v1.push_back("шестьсот ");
		v1.push_back("семьсот "); v1.push_back("восемьсот "); v1.push_back("девятьсот "); 
		d2vMasc.push_back(v1);
		d2vFem.push_back(v1);
		v1.clear();
		
		ul[MASCUL] = d2vMasc;
		ul[FEM] = d2vFem;
		

	};


	std::string RusAlg::getNumeral(const short power, const short unit, const short grade) const {
			return (std::string)("ничего");
		};


//---------------------------------
//---------------------------------
//---------------------------------


	Convert::Convert(ConvertAlg& convAlg) {
		this->convAlg = &convAlg;
		init();
	}


	void Convert::init() {
		convAlg->phraseBaseInit(powList, unList);
	}


	std::string Convert::getNumeral(const short power, const short unit, const short grade) const{
		return convAlg->getNumeral(power, unit, grade);
	}


}










TEST( ConvertAlgTest, testone) {

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	
	std::cout<<cnvrt.getNumeral(0,0,0)<<std::endl;
	ASSERT_STREQ( (cnvrt.getNumeral(0,0,0)).c_str(), "ноль" );
	ASSERT_STREQ( (cnvrt.getNumeral(1,3,1)).c_str(), "тридцать " );

}

