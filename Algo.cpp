#include "./include/Algo.h"





namespace velalg {

//-------------MatAlg---------------

	MatAlg::MatAlg(const short ud, const short pd):
		unitDivisor(ud),powerDivisor(pd){};



//проверка на кратность
	DecAlg::DecAlg(): 
		MatAlg(10,1000) {};

	OctAlg::OctAlg(): 
		MatAlg(8,512) {};

#ifdef VELALG_TEST
	WrongAlg::WrongAlg(): 
		MatAlg(8,592) {};

	WrongZeroAlg::WrongZeroAlg(): 
		MatAlg(0,0) {};


	WrongGreaterAlg::WrongGreaterAlg(): 
		MatAlg(512,8) {};

#endif


//-------------Algo---------------

	Algo::Algo(const long value, MatAlg* alg)  throw (std::invalid_argument) {
			
			short rate = alg->unitDivisor;

			if ( !(alg->unitDivisor) )
					throw std::invalid_argument( "unit divisor is zero" );

			if ( !(alg->powerDivisor) )
					throw std::invalid_argument( "power divisor is zero" );


			while ( rate != alg->powerDivisor ) {
				if  ( rate > alg->powerDivisor )
					throw std::invalid_argument( "a power must be divisible by unit" );

				rate*=alg->unitDivisor;
			}

			this->alg = alg;
			power = 0;
			unit = 0;
			unitValue = 0;
			powerDivCounter = 1;
			unitDivCounter = 0;

			if (value < 0) {
				minus = true;
			} else 
				minus = false;

			this->value=abs(value);
			init();
		}

	void Algo::init() {
		unitValue=value%(alg->powerDivisor);
		value=value/(alg->powerDivisor);
	}



	void Algo::incrPowerAndUnit() {

		if ( (value == 0) && (unitValue == 0) ) {
			power=0;
			unit=0;
			return;
		}


		if ( pow(alg->unitDivisor, unitDivCounter) == (alg->powerDivisor)  ) {

			unitDivCounter=0;
			power++;
			unitValue=value%(alg->powerDivisor);
			value=value/(alg->powerDivisor);
		} 

		unit=unitValue%(alg->unitDivisor);
		unitValue/=(alg->unitDivisor);
		unitDivCounter++;

	}


}








