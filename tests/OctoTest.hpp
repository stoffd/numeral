
#ifndef MAIN_TEST_PACK_ENG_HPP
#define MAIN_TEST_PACK_ENG_HPP


TEST( MainTestPackEng, AndTenHundreds) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (110, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one hundred and ten");
}


TEST( MainTestPackEng, roundHundred) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (200, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"two hundred");
}


TEST( MainTestPackEng, zero) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (0, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"zero");
}


TEST( MainTestPackEng, one) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (1, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one");
}


TEST( MainTestPackEng, lessThanZero) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (-1, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"minus one");
}


TEST( MainTestPackEng, xTeen) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (13, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"thirteen");
}



TEST( MainTestPackEng, thousands) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (4000, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"four thousand");
}


TEST( MainTestPackEng, thousandWithTens) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (3010, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"three thousand and ten");
}


TEST( MainTestPackEng, thousandWithTens2) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (5014, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"five thousand fourteen");
}


TEST( MainTestPackEng, maxThousand) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (9999, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"nine thousand nine hundred ninety-nine");
}


TEST( MainTestPackEng, tenthousandOne) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (10001, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"ten thousand and one");
}


TEST( MainTestPackEng, billion) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (1000000000, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one billion");
}


TEST( MainTestPackEng, billonWithAndsVariant1) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (1506824910, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one billion five hundred and six million eight hundred twenty-four thousand nine hundred and ten");
}


TEST( MainTestPackEng, billonWithAndsVariant2) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (1540824910, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one billion five hundred fourty million eight hundred twenty-four thousand nine hundred and ten");
}


TEST( MainTestPackEng, doesItnotDropDownWithWarningValues) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (222222222222222222, engAlg.get(),decAlg.get() );
	ASSERT_TRUE(true);
}





#endif//MAIN_TEST_PACK_ENG_HPP
