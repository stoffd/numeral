#ifndef MAT_ALG_HPP
#define MAT_ALG_HPP


#include <gtest/gtest.h>
#include  "struct.hpp"
#include <memory>
#include <cmath>

namespace velalg {

	struct algo {

		algo(const short ud, const short pd):unit_divisor(ud),power_divisor(pd){};

		const short unit_divisor;
		const short power_divisor;
	
	};

	struct dec_alg : public algo {
		dec_alg(): algo(10,1000) {};
	};


	struct oct_alg : public algo {
		oct_alg(): algo(8,512) {};
	};





	class mat_alg {
	public:

		mat_alg(const long value, algo& alg) {
			this->alg=&alg;
			power=-1;
			unit=0;
			unit_value=0;
			power_div_counter=1;
			unit_div_counter=1;

			if (value < 0) {
				minus=true;
			}

			this->value=abs(value);
		
		}

		void phase() {

			if ( (value == 0) && (unit_value == 0) ) {
				power=0;
				unit=0;
				return;
			}


			if (unit_value == 0) {
				unit_div_counter=1;
				power++;
				unit_value=value%(alg->power_divisor);
				value=value/(alg->power_divisor);
			}

			unit=unit_value%(long) (( pow ( (alg->unit_divisor), unit_div_counter ) ));
			unit_value/=( pow ( (alg->unit_divisor), unit_div_counter ) );

		
		}

		bool is_less_zero() const {
			return minus;
		}

		short get_power() const {
			return power;
		}; 

		short get_unit() const {
			return unit;
		}; 

	private:
		bool	minus;
		short	power;
		short	unit;
		short	unit_div_counter;
		short	power_div_counter;
		short	unit_value; //тут храниться часть числа обрубленная power divisoroм
		long	value;
		algo*	alg;

	};




}

//-------------TEST-----------
//-------------TEST-----------
//-------------TEST-----------



TEST( mat_algTest, zeroTest ) {

	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg() );
	velalg::mat_alg ma_dec (0, *al_dec.get() );
	ma_dec.phase();
	ma_dec.phase();
	ma_dec.phase();

	EXPECT_EQ( ma_dec.get_unit(), 0);
	EXPECT_EQ( ma_dec.get_power(), 0);


	std::auto_ptr<velalg::algo> al_oct (new velalg::oct_alg() );
	velalg::mat_alg ma_oct (0, *al_oct.get() );


	ma_oct.phase();
	ma_oct.phase();
	ma_oct.phase();


	EXPECT_EQ( ma_oct.get_unit(), 0);
	EXPECT_EQ( ma_oct.get_power(), 0);
}


TEST( mat_algTest, test1) {
	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg() );
	velalg::mat_alg ma_dec (1, *al_dec.get() );
	ma_dec.phase();

	EXPECT_EQ( ma_dec.get_unit(), 1);
	EXPECT_EQ( ma_dec.get_power(), 0);


	std::auto_ptr<velalg::algo> al_oct (new velalg::oct_alg() );
	velalg::mat_alg ma_oct (1, *al_oct.get() );


	ma_oct.phase();

	EXPECT_EQ( ma_oct.get_unit(), 1);
	EXPECT_EQ( ma_oct.get_power(), 0);

}



TEST( mat_algTest, test_is_less_zero) {
	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg() );
	velalg::mat_alg ma_dec (-1234, *al_dec.get() );

	ASSERT_TRUE (ma_dec.is_less_zero());

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 4);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 3);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 2);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 1);
	EXPECT_EQ( ma_dec.get_power(), 1);



//2322
	std::auto_ptr<velalg::algo> al_oct (new velalg::oct_alg() );
	velalg::mat_alg ma_oct (-1234, *al_oct.get() );

	ASSERT_TRUE (ma_oct.is_less_zero());

	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 2);
	EXPECT_EQ( ma_oct.get_power(), 0);

	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 2);
	EXPECT_EQ( ma_oct.get_power(), 0);

	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 3);
	EXPECT_EQ( ma_oct.get_power(), 0);

	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 2);
	EXPECT_EQ( ma_oct.get_power(), 1);

}


TEST( mat_algTest, test123000) {
	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg() );
	velalg::mat_alg ma_dec (123000, *al_dec.get() );


	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 0);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 3);
	EXPECT_EQ( ma_dec.get_power(), 1);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 2);
	EXPECT_EQ( ma_dec.get_power(), 1);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 1);
	EXPECT_EQ( ma_dec.get_power(), 1);

}

TEST( mat_algTest, test123102) {
	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg() );
	velalg::mat_alg ma_dec (123102, *al_dec.get() );


	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 2);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 0);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 1);
	EXPECT_EQ( ma_dec.get_power(), 0);

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 3);
	EXPECT_EQ( ma_dec.get_power(), 1);


	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 2);
	EXPECT_EQ( ma_dec.get_power(), 1);


	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 1);
	EXPECT_EQ( ma_dec.get_power(), 1);

}






TEST( mat_algTest, test4294967295) {

	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg() );
	velalg::mat_alg ma_dec (2147483647, *al_dec.get() );

	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 7);
	EXPECT_EQ( ma_dec.get_power(), 0);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 4);
	EXPECT_EQ( ma_dec.get_power(), 0);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 6);
	EXPECT_EQ( ma_dec.get_power(), 0);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 3);
	EXPECT_EQ( ma_dec.get_power(), 1);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 8);
	EXPECT_EQ( ma_dec.get_power(), 1);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 4);
	EXPECT_EQ( ma_dec.get_power(), 1);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 7);
	EXPECT_EQ( ma_dec.get_power(), 2);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 4);
	EXPECT_EQ( ma_dec.get_power(), 2);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 1);
	EXPECT_EQ( ma_dec.get_power(), 2);
	ma_dec.phase();
	EXPECT_EQ( ma_dec.get_unit(), 2);
	EXPECT_EQ( ma_dec.get_power(), 3);

//17777777777 - for oct

	std::auto_ptr<velalg::algo> al_oct (new velalg::oct_alg() );
	velalg::mat_alg ma_oct (2147483647, *al_oct.get() );


	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 0);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 0);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 0);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 1);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 1);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 1);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 2);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 2);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 2);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 7);
	EXPECT_EQ( ma_oct.get_power(), 3);
	ma_oct.phase();
	EXPECT_EQ( ma_oct.get_unit(), 1);
	EXPECT_EQ( ma_oct.get_power(), 3);


}


//TEST( mat_algTest, test4294967296) {
	//velalg::algo* al = new velalg::dec_alg<long>();
	//velalg::mat_alg<long> ma (0, *al);
	//ma.phase();
	//EXPECT_EQ( ma.get_unit(), 0);
	//EXPECT_EQ( ma.get_power(), 0);
//}



#endif//MAT_ALG_HPP
