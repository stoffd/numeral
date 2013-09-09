#include <iostream>
#include <vector>
#include <map>
#include  "./include/Numeral.h"

#ifdef VELALG_TEST
	#include "./tests/AlgoTest.hpp"
	#include "./tests/MainTestPackEng.hpp"
	#include "./tests/ConvertTest.hpp"
	#include "./tests/MainTestPackRus.hpp"
#endif




int main(int argc, char **argv) {


	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


