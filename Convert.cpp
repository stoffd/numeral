#include "./include/Convert.h"



namespace velalg {



	Convert::Convert(ConvertAlg& convAlg) {
		this->convAlg = &convAlg;
		init();
	}


	void Convert::init() {
		convAlg->phraseBaseInit();
	}


	std::string Convert::getNumeral(const short unit) const{
		return convAlg->getNumeral(unit);
	}


}


//---------------------------------
//------------ENG_TEST-----------------
//---------------------------------


TEST( ConvertAlgTest, millionEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(2); 
	EXPECT_STREQ( tempStr.c_str() ,"twenty " );

	tempStr = cnvrt.getNumeral(1); 
	EXPECT_STREQ(tempStr.c_str(),"one hundred and ");


	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(2); 
	EXPECT_STREQ(tempStr.c_str(),"twenty thousand ");

	tempStr = cnvrt.getNumeral(3); 
	EXPECT_STREQ(tempStr.c_str(),"three hundred ");

	tempStr = cnvrt.getNumeral(1); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"one million ");

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");


}





TEST( ConvertAlgTest, hundredAndOnceEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(2); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ( tempStr.c_str() ,"two " );

	tempStr = cnvrt.getNumeral(3); 
	EXPECT_STREQ(tempStr.c_str(),"three hundred and ");

}




TEST( ConvertAlgTest, hundredAndDecEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(8); 
	EXPECT_STREQ( tempStr.c_str() ,"eighty " );

	tempStr = cnvrt.getNumeral(4); 
	EXPECT_STREQ(tempStr.c_str(),"four hundred and ");

}






TEST( ConvertAlgTest, singleEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(2); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ( tempStr.c_str() ,"two " );

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

}



TEST( ConvertAlgTest, xteenEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(3); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(1); 
	EXPECT_STREQ( tempStr.c_str() ,"thirteen " );

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

}


TEST( ConvertAlgTest, decWithOnceEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(7); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(6); 
	EXPECT_STREQ( tempStr.c_str() ,"sixty-seven " );

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

}


TEST( ConvertAlgTest, decWithEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(8); 
	EXPECT_STREQ( tempStr.c_str() ,"eighty " );

	tempStr = cnvrt.getNumeral(0); 
	EXPECT_STREQ(tempStr.c_str(),"");

}





TEST( ConvertAlgTest, hundredEng) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alEng (new velalg::EngAlg() );
	velalg::Convert cnvrt (*alEng.get() );
	

	tempStr = cnvrt.getNumeral(7); 
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(8); 
	EXPECT_STREQ( tempStr.c_str() ,"eighty-seven " );

	tempStr = cnvrt.getNumeral(9); 
	EXPECT_STREQ(tempStr.c_str(),"nine hundred ");

}




//---------------------------------
//------------RUS_TEST-----------------
//---------------------------------

TEST( ConvertAlgTest, million ) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(2); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"двадцать один ");

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"сто " );


	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(7); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"семьдесят одна тысяча ");


	tempStr = cnvrt.getNumeral(8); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"восемьсот ");

	tempStr = cnvrt.getNumeral(4); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(4); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"сорок четыре миллиона ");

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");


	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");


	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"один миллиард ");

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");


}







TEST( ConvertAlgTest, hundred ) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(2); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"двадцать один ");

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"сто " );


	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"одна тысяча ");

}


TEST( ConvertAlgTest, minTriplet ) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"одиннадцать " );

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"сто ");

}




TEST( ConvertAlgTest, maxTriplet ) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(9); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(9); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"девяносто девять " );

	tempStr = cnvrt.getNumeral(9); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"девятьсот ");

}




TEST( ConvertAlgTest, single) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(2); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"два " );

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

}


TEST( ConvertAlgTest, hundredNdDecs ) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(9); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"девяносто " );

	tempStr = cnvrt.getNumeral(5); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"пятьсот ");


}




TEST( ConvertAlgTest, xteen) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	
	tempStr = cnvrt.getNumeral(7); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"семнадцать " );

}


TEST( ConvertAlgTest, zeroInTheMiddle103) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );

	tempStr = cnvrt.getNumeral(3); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"три " );

	tempStr = cnvrt.getNumeral(1); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"сто ");


}


TEST( ConvertAlgTest, fullTriplet) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(4); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(9); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"девяносто четыре " );

	tempStr = cnvrt.getNumeral(8); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"восемьсот ");

}


TEST( ConvertAlgTest, twoZeroes300) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"" );

	tempStr = cnvrt.getNumeral(3); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"триста ");

}





TEST( ConvertAlgTest, decs) {

	std::string tempStr;

	std::auto_ptr<velalg::ConvertAlg> alRu (new velalg::RusAlg() );
	velalg::Convert cnvrt (*alRu.get() );
	

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

	tempStr = cnvrt.getNumeral(7); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ( tempStr.c_str() ,"семьдесят " );

	tempStr = cnvrt.getNumeral(0); 
	//std::cout<<tempStr<<std::endl;
	EXPECT_STREQ(tempStr.c_str(),"");

}




