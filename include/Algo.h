#ifndef MAT_ALG_H
#define MAT_ALG_H


#include <gtest/gtest.h>
#include  "struct.h"
#include <memory>
#include <cmath>

namespace velalg {

	struct MatAlg {

		MatAlg(const short ud, const short pd);

		const short unitDivisor;
		const short powerDivisor;
	
	};

	struct DecAlg : public MatAlg {
		DecAlg();
	};

	struct OctAlg : public MatAlg {
		OctAlg();
	};


#ifdef VELALG_TEST
	struct WrongAlg : public MatAlg {
		WrongAlg();
	};


	struct WrongZeroAlg : public MatAlg {
		WrongZeroAlg();
	};


	struct WrongGreaterAlg : public MatAlg {
		WrongGreaterAlg();
	};
#endif

//-----------------------------------------

	class Algo {
	public:

		Algo(const long value, MatAlg* alg) throw (std::invalid_argument); 
		void init();

		void incrPowerAndUnit(); 

		inline bool isEnd() {
			if ( (value == 0) && (unitValue == 0) ) {
				if ( unitDivCounter % rateCount == 0 ) 
				return true;
			}
			return false;
		};

		inline bool isLessZero() const {
			return minus;
		};

		inline short getPower() const {
			return power;
		}; 

		inline short getUnit() const {
			return unit;
		}; 

	private:
		short	rateCount;
		bool	minus;
		short	power;
		short	unit;
		short	unitDivCounter;
		short	powerDivCounter;
		short	unitValue; //тут храниться часть числа обрубленная power divisoroм
		long	value;
		MatAlg*	alg;

	};




}







#endif//MAT_ALG_H
