#include "./include/ConvertAlg.h"



namespace velalg {



	void RusAlg::phraseBaseInit() { 

		std::vector<std::string> v1;
		std::vector<std::string>::iterator it;

		PowerNumeralList::iterator nlIt;

		v1.push_back("тысяча "); v1.push_back("тысячи "); v1.push_back("тысяч ");
		powList.push_back( ( struct PowerNumeralStruct) {FEM,v1} );
		v1.clear();


		v1.push_back("миллион "); v1.push_back("миллиона "); v1.push_back("миллионов ");
		powList.push_back( ( struct PowerNumeralStruct) {FEM,v1} );
		v1.clear();

		v1.push_back("миллиард "); v1.push_back("миллиарда "); v1.push_back("миллиардов ");
		powList.push_back( ( struct PowerNumeralStruct) {FEM,v1} );
		v1.clear();


//--------------------------
		D2String 			d2vMasc, d2vFem;
		D2String::iterator d2itMasc, d2itFem;

		v1.push_back("1один "); v1.push_back("2два "); v1.push_back("3три ");
		v1.push_back("4четыре "); v1.push_back("5пять "); v1.push_back("6шесть ");
		v1.push_back("7семь "); v1.push_back("8восемь "); v1.push_back("9девять "); 
		d2vMasc.push_back(v1);
		v1.clear();


		v1.push_back("1aодна "); v1.push_back("2aдве "); v1.push_back("3aтри ");
		v1.push_back("4aчетыре "); v1.push_back("5aпять "); v1.push_back("6aшесть ");
		v1.push_back("7aсемь "); v1.push_back("8aвосемь "); v1.push_back("9aдевять "); 
		d2vFem.push_back(v1);
		v1.clear();


		v1.push_back("11одиннадцать "); v1.push_back("12двенадцать "); v1.push_back("13тринадцать ");
		v1.push_back("14четырнадцать "); v1.push_back("15пятьнадцать "); v1.push_back("16шестнадцать ");
		v1.push_back("17семнадцать "); v1.push_back("18восемнадцать "); v1.push_back("19девятнадцать "); 
		d2vMasc.push_back(v1);
		d2vFem.push_back(v1);
		v1.clear();


		v1.push_back("10десять "); v1.push_back("20двадцать "); v1.push_back("30тридцать ");
		v1.push_back("40сорок "); v1.push_back("50пятьдесят "); v1.push_back("60шестьдесят ");
		v1.push_back("70семьдесят "); v1.push_back("80восемьдесят "); v1.push_back("90девяносто "); 
		d2vMasc.push_back(v1);
		d2vFem.push_back(v1);
		v1.clear();


		v1.push_back("100сто "); v1.push_back("200двести "); v1.push_back("300триста ");
		v1.push_back("400четыреста "); v1.push_back("500пятьсот "); v1.push_back("600шестьсот ");
		v1.push_back("700семьсот "); v1.push_back("800восемьсот "); v1.push_back("900девятьсот "); 
		d2vMasc.push_back(v1);
		d2vFem.push_back(v1);
		v1.clear();
		
		unList[MASCUL] = d2vMasc;
		unList[FEM] = d2vFem;
		

	};

	RusAlg::RusAlg(){
		//cell.isFree = true;
		memCell = 0;
		unitCounter = 0;
		powerCounter = 0;
	};

	std::string RusAlg::getNumeral( const short value ) {


		std::string returnedString ("");

		genders gend = (powerCounter == 1) ? MASCUL : FEM;

		switch (unitCounter) {

		case 0:
			memCell = value;
			break;

		case 1:
			if (value == 1)
				returnedString= *( (( (unList[gend].begin())+1 )->begin())+memCell-1);
			else if ( (value == 0) && ( memCell != 0 ) )
				returnedString= *( (( (unList[gend].begin()) )->begin())+memCell-1);
			else if ( value!=0 )
				returnedString= *( (( (unList[gend].begin())+2 )->begin())+value-1);
			break;

		case 2:
			break;
		
		default:
			break;
		
		}




		//if (unitCounter == 0) {
		//} else {
			//if ( (unitCounter == 1) && (value == 1) ) {

			//} else if ( value == 0 ) {
				//return *( (( (unList[gend].begin()) )->begin())+memCell-1);
			//} else {
				//if ( memCell != 0 ) {
					//return *( (( (unList[gend].begin())+unitCounter )->begin())+value+1);
				
				//}
			
			//}
		
		//}


		unitCounter++;

		if ( unitCounter == maxGradeLevel ) {
			powerCounter++;
			unitCounter = 0;
		}



		return returnedString; 
	}


//---------------------------------
//---------------------------------
//---------------------------------


	Convert::Convert(ConvertAlg& convAlg) {
		this->convAlg = &convAlg;
		init();
	}


	void Convert::init() {
		convAlg->phraseBaseInit();
	}


	std::string Convert::getNumeral(const short unit) const{
		return convAlg->getNumeral(unit);
	}


}










TEST( ConvertAlgTest, xteen) {

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	
	EXPECT_STREQ( (cnvrt.getNumeral(7)).c_str(), "" );
	EXPECT_STREQ( (cnvrt.getNumeral(1)).c_str(), "семнадцать " );

}


TEST( ConvertAlgTest, zeroInTheMiddle103) {

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	
	EXPECT_STREQ( (cnvrt.getNumeral(3)).c_str(), "" );
	EXPECT_STREQ( (cnvrt.getNumeral(0)).c_str(), "три " );
	EXPECT_STREQ( (cnvrt.getNumeral(1)).c_str(), "сто " );

}


TEST( ConvertAlgTest, fullTriplet) {

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	
	EXPECT_STREQ( (cnvrt.getNumeral(3)).c_str(), "три" );
	EXPECT_STREQ( (cnvrt.getNumeral(5)).c_str(), "пятьдесят " );
	EXPECT_STREQ( (cnvrt.getNumeral(4)).c_str(), "четыреста " );

}

