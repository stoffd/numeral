#ifndef MAT_ALG_H
#define MAT_ALG_H


#include <gtest/gtest.h>
#include  "struct.h"
#include <memory>
#include <cmath>

namespace velalg {

	struct Algo {

		Algo(const short ud, const short pd);

		const short unitDivisor;
		const short powerDivisor;
	
	};

	struct DecAlg : public Algo {
		DecAlg();
	};

	struct OctAlg : public Algo {
		OctAlg();
	};

//-----------------------------------------

	class MatAlg {
	public:

		MatAlg(const long value, Algo& alg); 

		void phase(); 

		inline bool isLessZero() const {
			return minus;
		}

		inline short getPower() const {
			return power;
		}; 

		inline short getUnit() const {
			return unit;
		}; 

	private:
		bool	minus;
		short	power;
		short	unit;
		short	unitDivCounter;
		short	powerDivCounter;
		short	unitValue; //тут храниться часть числа обрубленная power divisoroм
		long	value;
		Algo*	alg;

	};




}







#endif//MAT_ALG_H
