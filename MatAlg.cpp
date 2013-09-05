#include "./include/MatAlg.h"





namespace velalg {

//-------------Algo---------------

	Algo::Algo(const short ud, const short pd):
		unitDivisor(ud),powerDivisor(pd){};



	DecAlg::DecAlg(): 
		Algo(10,1000) {};

	OctAlg::OctAlg(): 
		Algo(8,512) {};


//-------------MatAlg---------------

	MatAlg::MatAlg(const long value, Algo& alg) {
			this->alg=&alg;
			power=-1;
			unit=0;
			unitValue=0;
			powerDivCounter=1;
			unitDivCounter=1;

			if (value < 0) {
				minus=true;
			}

			this->value=abs(value);
		}



	void MatAlg::phase() {

		if ( (value == 0) && (unitValue == 0) ) {
			power=0;
			unit=0;
			return;
		}


		if (unitValue == 0) {
			unitDivCounter=1;
			power++;
			unitValue=value%(alg->powerDivisor);
			value=value/(alg->powerDivisor);
		}

		unit=unitValue%(long) (( pow ( (alg->unitDivisor), unitDivCounter ) ));
		unitValue/=( pow ( (alg->unitDivisor), unitDivCounter ) );

	}


		


}





TEST( MatAlgTest, zeroTest ) {

	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (0, *alDec.get() );
	maDec.phase();
	maDec.phase();
	maDec.phase();

	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);


	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (0, *alOct.get() );


	maOct.phase();
	maOct.phase();
	maOct.phase();


	EXPECT_EQ( maOct.getUnit(), 0);
	EXPECT_EQ( maOct.getPower(), 0);
}




TEST( MatAlgTest, test1) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (1, *alDec.get() );
	maDec.phase();

	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 0);


	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (1, *alOct.get() );


	maOct.phase();

	EXPECT_EQ( maOct.getUnit(), 1);
	EXPECT_EQ( maOct.getPower(), 0);

}



TEST( MatAlgTest, test_is_less_zero) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (-1234, *alDec.get() );

	ASSERT_TRUE (maDec.isLessZero());

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);



//2322
	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (-1234, *alOct.get() );

	ASSERT_TRUE (maOct.isLessZero());

	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 3);
	EXPECT_EQ( maOct.getPower(), 0);

	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 2);
	EXPECT_EQ( maOct.getPower(), 1);

}


TEST( MatAlgTest, test123000) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (123000, *alDec.get() );


	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 1);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);

}

TEST( MatAlgTest, test123102) {
	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (123102, *alDec.get() );


	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 0);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 0);

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);


	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 1);


	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 1);

}






TEST( MatAlgTest, test4294967295) {

	std::auto_ptr<velalg::Algo> alDec (new velalg::DecAlg() );
	velalg::MatAlg maDec (2147483647, *alDec.get() );

	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 7);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 6);
	EXPECT_EQ( maDec.getPower(), 0);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 3);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 8);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 1);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 7);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 4);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 1);
	EXPECT_EQ( maDec.getPower(), 2);
	maDec.phase();
	EXPECT_EQ( maDec.getUnit(), 2);
	EXPECT_EQ( maDec.getPower(), 3);

//17777777777 - for oct

	std::auto_ptr<velalg::Algo> alOct (new velalg::OctAlg() );
	velalg::MatAlg maOct (2147483647, *alOct.get() );


	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 0);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 1);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 2);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 7);
	EXPECT_EQ( maOct.getPower(), 3);
	maOct.phase();
	EXPECT_EQ( maOct.getUnit(), 1);
	EXPECT_EQ( maOct.getPower(), 3);


}



