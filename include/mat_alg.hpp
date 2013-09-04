#ifndef MAT_ALG_HPP
#define MAT_ALG_HPP


#include <gtest/gtest.h>
#include  "struct.hpp"
#include <memory>

namespace velalg {


	//class algo {
	//public:
		//algo(){};
		//virtual ~algo() {};

		//virtual short div() =0;
		//virtual short mod() =0;
	
	//};

	//template <typename T>
	//class dec_alg : public algo {
	//public:
		//dec_alg(){};
		//virtual ~dec_alg() {};

		//virtual short div() {return 0;};
		//virtual short mod() {return 0;};
	
	//};


	//template <typename T>
	//class oct_alg : public algo {

	//public:
		//oct_alg (const T value) {};
		//virtual ~oct_alg() {};
		//virtual short div() {return 0;};
		//virtual short mod() {return 0;};
	
	//};





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

//class mat_algTest : public ::testing::Test {
//protected:
	//virtual void SetUp() {
		//al_dec (new velalg::dec_alg<long>() );
		//al_oct (new velalg::dec_alg<long>() );	
	//}

//  // virtual void TearDown() {}
	//std::auto_ptr<velalg::algo> al_dec
	//std::auto_ptr<velalg::algo> al_dec
//};


TEST( mat_algTest, zeroTest ) {

	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg<long>() );
	velalg::mat_alg<long> ma_dec (0, *(al_dec.get()) );
	ma_dec.phase();
	ma_dec.phase();
	ma_dec.phase();

	EXPECT_EQ( ma_dec.get_unit(), 0);
	EXPECT_EQ( ma_dec.get_power(), 0);


	std::auto_ptr<velalg::algo> al_oct (new velalg::oct_alg<long>() );
	velalg::mat_alg<long> ma_oct (0, *(al_oct.get()) );


	ma_oct.phase();
	ma_oct.phase();
	ma_oct.phase();


	EXPECT_EQ( ma_oct.get_unit(), 0);
	EXPECT_EQ( ma_oct.get_power(), 0);
}


TEST( mat_algTest, test1) {
	std::auto_ptr<velalg::algo> al_dec (new velalg::dec_alg<long>() );
	std::auto_ptr<velalg::algo> al_oct (new velalg::dec_alg<long>() );
	velalg::mat_alg<long> ma_dec (1, *(al.get()) );
	velalg::mat_alg<long> ma_oct (1, *(al.get()) );
	ma_dec.phase();
	ma_dec.phase();
	ma_dec.phase();


	ma_oct.phase();
	ma_oct.phase();
	ma_oct.phase();

	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);

}


TEST( mat_algTest, test14) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test274) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test4342) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test43429) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test434290) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test4342909) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test77744455) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test777444333) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test4294967295) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}


TEST( mat_algTest, test4294967296) {
	velalg::algo* al = new velalg::dec_alg<long>();
	velalg::mat_alg<long> ma (0, *al);
	ma.phase();
	EXPECT_EQ( ma.get_unit(), 0);
	EXPECT_EQ( ma.get_power(), 0);
}



#endif//MAT_ALG_HPP
