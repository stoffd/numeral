
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


TEST( MainTestPackEng, billion) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (1000000000, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one billion");
}


TEST( MainTestPackEng, randomBill) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::EngAlg() );
	std::string tempStr = velalg::Numeral() (1506824910, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"one billion five hundred and six million eight hundred twenty-four thousand nine hundred and ten");
}




#endif//MAIN_TEST_PACK_ENG_HPP
