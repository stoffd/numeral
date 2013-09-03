#ifndef MAT_ALG_HPP
#define MAT_ALG_HPP


#include <gtest/gtest.h>
#include  "struct.hpp"

namespace velalg {


	class algo {
	public:
		algo(){};
		virtual ~algo() {};

		virtual short div() =0;
		virtual short mod() =0;
	
	};

	template <typename T>
	class dec_alg : public algo {
	public:
		dec_alg(){};
		virtual ~dec_alg() {};

		virtual short div() {return 0;};
		virtual short mod() {return 0;};
	
	};


	template <typename T>
	class oct_alg : public algo {

	public:
		oct_alg (const T value) {};
		virtual ~oct_alg() {};
		virtual short div() {return 0;};
		virtual short mod() {return 0;};
	
	};


	template <typename T>
	class mat_alg {
	public:

		mat_alg(const T value, const algo& alg) {
		
		}

		void phase() {
		
		}

		short get_power() const {
			return 0;
		}; 

		short get_unit() const {
			return 0;
		}; 

	};




}

//-------------TEST-----------
//-------------TEST-----------
//-------------TEST-----------

TEST( mat_algTest, zeroTest ) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


#endif//MAT_ALG_HPP
