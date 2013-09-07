#include "./include/ConvertAlg.h"


namespace velalg {


	void EngAlg::phraseBaseInit() { 

		std::vector<std::string> v1;
		std::vector<std::string>::iterator it;

		D2String::iterator nlIt;


		v1.push_back("");
		powList.push_back(v1);
		v1.clear();

		v1.push_back("thousand ");
		powList.push_back(v1);
		v1.clear();


		v1.push_back("million ");
		powList.push_back(v1);
		v1.clear();

		v1.push_back("billion ");
		powList.push_back(v1);
		v1.clear();


//--------------------------

		D2String 			d2vMasc;
		D2String::iterator d2itMasc;

		v1.push_back("one "); v1.push_back("two "); v1.push_back("three ");
		v1.push_back("four "); v1.push_back("five "); v1.push_back("six ");
		v1.push_back("seven "); v1.push_back("eight "); v1.push_back("nine "); 
		d2vMasc.push_back(v1);
		v1.clear();


		v1.push_back("eleven "); v1.push_back("twelve "); v1.push_back("thirteen ");
		v1.push_back("fourteen "); v1.push_back("fifteen "); v1.push_back("sixteen ");
		v1.push_back("seventeen "); v1.push_back("eighteen "); v1.push_back("nineteen "); 
		d2vMasc.push_back(v1);
		v1.clear();


		v1.push_back("ten-"); v1.push_back("twenty-"); v1.push_back("thirty-");
		v1.push_back("fourty-"); v1.push_back("fifty-"); v1.push_back("sixty-");
		v1.push_back("seventy-"); v1.push_back("eighty-"); v1.push_back("ninety-"); 
		d2vMasc.push_back(v1);
		v1.clear();


		v1.push_back("one hundred "); v1.push_back("two hundred "); v1.push_back("three hundred ");
		v1.push_back("four hundred "); v1.push_back("five hundred "); v1.push_back("six hundred ");
		v1.push_back("seven hundred "); v1.push_back("eight hundred "); v1.push_back("nine hundred "); 
		d2vMasc.push_back(v1);
		v1.clear();
		
		unList[MASCUL] = d2vMasc;

	};



	EngAlg::EngAlg(){
		//cell.isFree = true;
		powerWasWrite = false;
		memCell = 0;
		unitCounter = 0;
		powerCounter = 0;
	};



	std::string EngAlg::getNumeral( const short value ) {


		std::string returnedString ("");
		

		D2String::iterator vvIt = unList[MASCUL].begin();

		switch (unitCounter) {

			case 0:
				memCell = value;
				break;

			case 1:
				if (value == 1) {

					returnedString = *( ( ( vvIt + 1 )->begin() ) + memCell - 1);
					//returnedString += definePower(powerCounter); 
					memCell = 0;

				} else if ( (value == 0) && ( memCell != 0 ) ){

					returnedString = *( ( vvIt->begin() ) + memCell - 1 );
					//returnedString += definePower(powerCounter); 
					memCell = 0;

				} else if ( ( value != 0 ) && ( memCell == 0 ) ) {

					returnedString += *( ( ( vvIt + 2 )->begin() ) + value - 1 );
					returnedString.replace( returnedString.find("-"), 1," ");
					//returnedString += definePower(powerCounter); 

				} else if ( ( value != 0 ) && ( memCell != 0 ) ) {

					returnedString =  *( ( ( vvIt + 2 )->begin() ) + value - 1 );
					returnedString+=  *( ( vvIt->begin() ) + memCell - 1 );
					//returnedString += definePower(powerCounter); 

					memCell = 0;
				}

				break;

			case 2:
				if ( (value == 0) && ( memCell != 0 ) ) {
					returnedString = *( ( ( vvIt + 2 )->begin() ) + memCell - 1);
				} else if ( (value == 0) && ( memCell == 0 ) ) {
					returnedString = "";
				} else {
					returnedString = *( ( ( vvIt + 3 )->begin() ) + value - 1);
					//if ( !powerWasWrite )
						returnedString = "and ";
						//returnedString += definePower(powerCounter); 
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
		}



		return returnedString; 
	}


	std::string EngAlg::definePower( const short power ) {

		D2String::iterator vvItPow = powList.begin();
		powerWasWrite = true; 

		return *( ( ( vvItPow + power ) -> begin() ) ); 
	
	}



}
