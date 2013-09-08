#ifndef MAIN_TEST_PACK_RUS
#define MAIN_TEST_PACK_RUS


TEST( MainTestPackRus, zero) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (0, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"ноль");
}


TEST( MainTestPackRus, one) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (1, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"один");
}


TEST( MainTestPackRus, lessThanZero) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (-1, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"минус один");
}




TEST( MainTestPackRus, AndTenHundreds) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (110, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"сто десять");
}


TEST( MainTestPackRus, roundHundred) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (200, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"двести");
}




TEST( MainTestPackRus, xTeen) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (13, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"тринадцать");
}



TEST( MainTestPackRus, thousands) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (4000, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"четыре тысячи");
}


TEST( MainTestPackRus, thousandWithTens) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (3010, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"три тысячи десять");
}


TEST( MainTestPackRus, thousandWithTens2) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (5014, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"пять тысяч четырнадцать");
}


TEST( MainTestPackRus, maxThousand) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (9999, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"девять тысяч девятьсот девяносто девять");
}


TEST( MainTestPackRus, tenthousandOne) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (10001, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"десять тысяч один");
}



TEST( MainTestPackRus, billion) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (1000000000, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"один миллиард");
}


TEST( MainTestPackRus, billonWithAndsVariant1) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (1506824910, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"один миллиард пятьсот шесть миллионов восемьсот двадцать четыре тысячи девятьсот десять");
}


TEST( MainTestPackRus, billonWithAndsVariant2) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (1540824910, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"один миллиард пятьсот сорок миллионов восемьсот двадцать четыре тысячи девятьсот десять");
}


TEST( MainTestPackRus, doesItnotDropDownWithWarningValues) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (222222222222222222, engAlg.get(),decAlg.get() );
	ASSERT_TRUE(true);
}


TEST( MainTestPackRus, grammarCase1) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (1001, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"одна тысяча один");
}


TEST( MainTestPackRus, grammarCase2) {
	std::auto_ptr<velalg::MatAlg> decAlg (new velalg::DecAlg() );
	std::auto_ptr<velalg::ConvertAlg> engAlg (new velalg::RusAlg() );
	std::string tempStr = velalg::Numeral() (2002004, engAlg.get(),decAlg.get() );
	EXPECT_STREQ( tempStr.c_str(),"два миллиона две тысячи четыре");
}





#endif//MAIN_TEST_PACK_RUS
