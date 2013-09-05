#include "./include/MatAlg.h"





namespace velalg {

//-------------Algo---------------

	Algo::Algo(const short ud, const short pd):
		unitDivisor(ud),powerDivisor(pd){};



//проверка на кратность
	DecAlg::DecAlg(): 
		Algo(10,1000) {};

	OctAlg::OctAlg(): 
		Algo(8,512) {};


//-------------MatAlg---------------

	MatAlg::MatAlg(const long value, Algo& alg) {
			this->alg=&alg;
			power=0;
			unit=0;
			unitValue=0;
			powerDivCounter=1;
			unitDivCounter=0;

			if (value < 0) {
				minus=true;
			}

			this->value=abs(value);
			init();
		}

	void MatAlg::init() {
		unitValue=value%(alg->powerDivisor);
		value=value/(alg->powerDivisor);
	}



	void MatAlg::setPowerAndUnit() {

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

	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (0, *alDec.get() );
	maDec.setPowerAndUnit();
	maDec.setPowerAndUnit();
	maDec.setPowerAndUnit();

	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);


	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (0, *alOct.get() );


	maOct.setPowerAndUnit();
	maOct.setPowerAndUnit();
	maOct.setPowerAndUnit();


	EXPECT_EQ( maOct.getUnit(), 0);
	EXPECT_EQ( maOct.getPower(), 0);
}




TEST( MatAlgTest, test1) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (1, *alDec.get() );
	maDec.setPowerAndUnit();

	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 0);


	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (1, *alOct.get() );


	maOct.setPowerAndUnit();

	EXPECT_EQ( maOct.getUnit(), 1);
	EXPECT_EQ( maOct.getPower(), 0);

}



TEST( MatAlgTest, test_is_less_zero) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (-1234, *alDec.get() );

	ASSERT_TRUE (maDec.isLessZero());

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);



//2322
	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (-1234, *alOct.get() );

	ASSERT_TRUE (maOct.isLessZero());

	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 3);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 1);

}


TEST( MatAlgTest, test123000) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (123000, *alDec.get() );




	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 1);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);

}

TEST( MatAlgTest, test123102) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (123102, *alDec.get() );


	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);


	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 1);


	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);

}






TEST( MatAlgTest, test4294967295) {

	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (2147483647, *alDec.get() );

	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 7);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 6);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 8);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 7);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.setPowerAndUnit();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 3);

//17777777777 - for oct

	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (2147483647, *alOct.get() );


	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 3);
	maOct.setPowerAndUnit();
	EXPECT_EQ( maOct.getUnit(), 1);
	EXPECT_EQ( maOct.getPower(), 3);


}



