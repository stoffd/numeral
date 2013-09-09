#ifndef ALGO_TEST_PACK_HPP
#define ALGO_TEST_PACK_HPP


TEST( MatAlgTest, testWrongGreat) {

	try {
	std::auto_ptr<velalg::MatAlg> wrng (new velalg::WrongGreaterAlg() );
	velalg::Algo maWrng (0, wrng.get() );

	} catch (std::invalid_argument& ia) {
		ASSERT_TRUE(true);
		return;
	}
	ASSERT_TRUE(false);

}



TEST( MatAlgTest, testWrongZeroAlg) {

	try {
	std::auto_ptr<velalg::MatAlg> wrng (new velalg::WrongZeroAlg() );
	velalg::Algo maWrng (0, wrng.get() );

	} catch (std::invalid_argument& ia) {
		ASSERT_TRUE(true);
		return;
	}
	ASSERT_TRUE(false);

}


TEST( MatAlgTest, testRightDivisibleByUnitDec) {

	try {
	std::auto_ptr<velalg::MatAlg> alDec (new velalg::DecAlg() );
	velalg::Algo maDec (0, alDec.get() );

	} catch (std::invalid_argument& ia) {
		ASSERT_TRUE(false);
		return;
	}
	ASSERT_TRUE(true);

}


TEST( MatAlgTest, testRightDivisibleByUnitOct) {

	try {
	std::auto_ptr<velalg::MatAlg> alOct (new velalg::OctAlg() );
	velalg::Algo maOct (0, alOct.get() );

	} catch (std::invalid_argument& ia) {
		ASSERT_TRUE(false);
		return;
	}
	ASSERT_TRUE(true);

}



TEST( MatAlgTest, testErrorDivisibleByUnit) {

	try {
		std::auto_ptr<velalg::MatAlg> alWrong (new velalg::WrongAlg() );
	velalg::Algo maWrong (100, alWrong.get() );
	} catch (std::invalid_argument& ia) {
		ASSERT_TRUE(true);
		return;
	}
	ASSERT_TRUE(false);

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




TEST( MatAlgTest, testBase) {
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
}



TEST( MatAlgTest, test_is_less_zero_oct_2322) {

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


TEST( MatAlgTest, testRightTripsZero) {
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

TEST( MatAlgTest, testZeroInTheMiddle) {
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






TEST( MatAlgTest, testMaxRange) {

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
}

TEST( MatAlgTest, testMaxRangeOct_17777777777 ) {

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




#endif//ALGO_TEST_PACK_HPP
