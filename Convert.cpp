#include "./include/Convert.h"



namespace velalg {



	Convert::Convert(ConvertAlg* convAlg) {
		this->convAlg = convAlg;
		init();
	}


	void Convert::init() {
		convAlg->phraseBaseInit();
	}


	std::string Convert::getNumeral(const short unit) const throw (std::out_of_range) {

		if ( (unit < 0) || (unit > 9) )
			throw std::out_of_range( "out of range. Diapason will be 0..9" );


		return convAlg->getNumeral(unit);
	}

	std::string Convert::finalize( bool isLessZero ) {
		return convAlg->finalize( isLessZero );
	}


}






