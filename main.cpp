#include <iostream>
#include <vector>
#include <map>
#include  "./include/Numeral.h"

#include "./tests/MainTestPackEng.hpp"
#include "./tests/AlgoTest.hpp"
#include "./tests/ConvertTest.hpp"
#include "./tests/MainTestPackRus.hpp"




int main(int argc, char **argv) {


	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


