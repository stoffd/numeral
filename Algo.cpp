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





TEST( MatAlgTest, zeroTest ) {

	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (0, alDec.get() );
	maDec.incrPowerAndUnit();
	maDec.incrPowerAndUnit();
	maDec.incrPowerAndUnit();

	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);


	std::auto_ptr<velalg::MatAlg> alOct (new velalg::OctAlg() );
	velalg::Algo maOct (0, alOct.get() );


	maOct.incrPowerAndUnit();
	maOct.incrPowerAndUnit();
	maOct.incrPowerAndUnit();


	EXPECT_EQ( maOct.getUnit(), 0);
	EXPECT_EQ( maOct.getPower(), 0);
}




TEST( MatAlgTest, test1) {
	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (1, alDec.get() );
	maDec.incrPowerAndUnit();

	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 0);


	std::auto_ptr<velalg::MatAlg> alOct (new velalg::OctAlg() );
	velalg::Algo maOct (1, alOct.get() );


	maOct.incrPowerAndUnit();

	EXPECT_EQ( maOct.getUnit(), 1);
	EXPECT_EQ( maOct.getPower(), 0);

}



TEST( MatAlgTest, test_is_less_zero) {
	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (-1234, alDec.get() );

	ASSERT_TRUE (maDec.isLessZero());

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);



//2322
	std::auto_ptr<velalg::MatAlg> alOct (new velalg::OctAlg() );
	velalg::Algo maOct (-1234, alOct.get() );

	ASSERT_TRUE (maOct.isLessZero());

	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 3);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 1);

}


TEST( MatAlgTest, test123000) {
	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (123000, alDec.get() );




	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 1);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);

}

TEST( MatAlgTest, test123102) {
	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (123102, alDec.get() );


	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);


	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 1);


	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);

}






TEST( MatAlgTest, test4294967295) {

	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (2147483647, alDec.get() );

	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 7);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 6);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 8);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 7);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.incrPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 3);

//17777777777 - for oct

	std::auto_ptr<velalg::MatAlg> alOct (new velalg::OctAlg() );
	velalg::Algo maOct (2147483647, alOct.get() );


	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 3);
	maOct.incrPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 1);
	EXPECT_EQ( maOct.getPower(), 3);


}



