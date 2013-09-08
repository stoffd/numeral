#include "./include/Convert.h"



namespace velalg {



	Convert::Convert(ConvertAlg* convAlg) {
		this->convAlg = convAlg;
		init();
	}


	void Convert::init() {
		convAlg->phraseBaseInit();
	}


	std::string Convert::getNumeral(const short unit) const{
		return convAlg->getNumeral(unit);
	}

	std::string Convert::finalize( bool isLessZero ) {
		return convAlg->finalize( isLessZero );
	}


}






