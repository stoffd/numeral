#ifndef CONVERT_H
#define CONVERT_H

#include <gtest/gtest.h>
#include <memory>
#include  "ConvertAlg.h"

namespace velalg {


	class Convert {
	public:

		Convert(ConvertAlg& convAlg);

		void init();
		std::string getNumeral(const short unit) const;


	private:
		ConvertAlg* convAlg;

	};

}



#endif//CONVERT_HP
