#include "./include/Numeral.h"



namespace velalg {
	std::string Numeral::operator() ( long val,  ConvertAlg* convertAlg, MatAlg* matAlg ) try { 

		Algo algo( val, matAlg );
		Convert convert( convertAlg );
		std::string resultString="";
		short unit;

		std::vector<std::string> tempV;
		std::vector<std::string>::reverse_iterator tempIt;


		


		short count = 0;
		while ( !( algo.isEnd() ) ) {
			algo.incrPowerAndUnit ();
			unit = algo.getUnit();
			tempV.push_back( convert.getNumeral( unit ) );
			//resultString += convert.getNumeral( unit );
			count++;
			
		}

		//if ( count % 3  == 1 )
			//tempV.push_back( convert.getNumeral( 0 ) );
			//resultString += convert.getNumeral( 0 );


		//resultString = convert.finalize( algo.isLessZero() ) + resultString; 

		tempV.push_back( convert.finalize( algo.isLessZero() ) );

		for ( tempIt = tempV.rbegin(); tempIt != tempV.rend(); ++tempIt) {
			resultString += *(tempIt);
		
		}
		//for_each (tempV.begin(), tempV.end(), )

		resultString.erase( ( resultString.length() - 1 ),1 );


		return resultString;
	
	} catch (std::exception& ex) {
		std::cerr << "Failure! " << ex.what() <<std::endl; 
		exit (-1);
	};
}
