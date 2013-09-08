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


//-------------Algo---------------

	Algo::Algo(const long value, MatAlg* alg) {
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








