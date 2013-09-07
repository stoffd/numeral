#include "./include/ConvertAlg.h"

namespace velalg {

	void RusAlg::phraseBaseInit() { 

		std::vector<std::string> v1;
		std::vector<std::string>::iterator it;

		D2String::iterator nlIt;


		v1.push_back(""); v1.push_back(""); v1.push_back("");
		powList.push_back(v1);
		v1.clear();

		v1.push_back("тысяча "); v1.push_back("тысячи "); v1.push_back("тысяч ");
		powList.push_back(v1);
		v1.clear();


		v1.push_back("миллион "); v1.push_back("миллиона "); v1.push_back("миллионов ");
		powList.push_back(v1);
		v1.clear();

		v1.push_back("миллиард "); v1.push_back("миллиарда "); v1.push_back("миллиардов ");
		powList.push_back(v1);
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
		
		unList[MASCUL] = d2vMasc;
		unList[FEM] = d2vFem;
		

	};

	RusAlg::RusAlg(){
		//cell.isFree = true;
		powerWasWrite = false;
		memCell = 0;
		unitCounter = 0;
		powerCounter = 0;
	};



	std::string RusAlg::getNumeral( const short value ) {


		std::string returnedString ("");
		

		genders gend = (powerCounter == 1) ? FEM : MASCUL;
		D2String::iterator vvIt = unList[gend].begin();

		switch (unitCounter) {

			case 0:
				memCell = value;
				break;

			case 1:
				if (value == 1) {

					returnedString = *( ( ( vvIt + 1 )->begin() ) + memCell - 1);
					returnedString += definePower( MORE_AS_FOUR, powerCounter );

				} else if ( (value == 0) && ( memCell != 0 ) ){

					returnedString = *( ( vvIt->begin() ) + memCell - 1 );
					returnedString += definePower( memCell, powerCounter );

				} else if ( ( value != 0 ) && ( memCell == 0 ) ) {

					returnedString = *( ( ( vvIt + 2 )->begin() ) + value - 1 );
					returnedString += definePower( MORE_AS_FOUR, powerCounter );

				} else if ( ( value != 0 ) && ( memCell != 0 ) ) {

					returnedString =  *( ( ( vvIt + 2 )->begin() ) + value - 1 );
					returnedString+=  *( ( vvIt->begin() ) + memCell - 1 );
					returnedString += definePower( memCell, powerCounter );

				}
					memCell = value;

				break;

			case 2:
				if ( (value == 0) )/*&& ( memCell != 0 ) )*/ {
					//returnedString = *( ( ( vvIt + 2 )->begin() ) + memCell - 1);
				} else if ( (value == 0) && ( memCell == 0 ) ) {
					returnedString = "";
				} else {
					returnedString = *( ( ( vvIt + 3 )->begin() ) + value - 1);
					if ( !powerWasWrite )
						returnedString += definePower( MORE_AS_FOUR, powerCounter );
				}

				break;
			
			default:
				break;
		
		}



		unitCounter++;

		if ( unitCounter == maxGradeLevel ) {

			powerWasWrite = false; 
			powerCounter++;
			unitCounter = 0;
			memCell = 0;
		}



		return returnedString; 
	}



	std::string RusAlg::definePower( const short value, const short power) {

		D2String::iterator vvItPow = powList.begin();
		short grammarCase=0;
		powerWasWrite = true; 

		switch (value) {

			case 0:
				throw;
				break;

			case 1:
				grammarCase = 0;
				break;

			case 2:
			case 3:
			case 4:
				grammarCase = 1;
				break;

			default:
				grammarCase = 2;
				break;
		
		} 

		return *( ( ( vvItPow + power ) -> begin() ) + grammarCase ); 
	
	}

}






