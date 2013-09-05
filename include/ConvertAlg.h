#ifndef CONVERT_ALG_H
#define CONVERT_ALG_H

#include <gtest/gtest.h>
#include <memory>
#include  "struct.h"

namespace velalg {



	class ConvertAlg {
	public:
		virtual void phraseBaseInit(PowerNumeralList& pl, UnitNumeralList& ul) =0;
		virtual std::string getNumeral(const short power, const short unit, const short grade) const =0;
	};
//--------------------------
//--------------------------------
//---------------------------------



	class RusAlg : public ConvertAlg {

	public:

		RusAlg(){};
		virtual void phraseBaseInit( 
				PowerNumeralList& pl,
				UnitNumeralList& ul );

		virtual std::string getNumeral(const short power, const short unit, const short grade) const;
		~RusAlg(){};

	private:

	
	};



//--------------------------
//--------------------------------
//---------------------------------
	class Convert {
	public:

		Convert(ConvertAlg& convAlg);

		void init();
		std::string getNumeral(const short power, const short unit, const short grade) const;


	private:
		ConvertAlg* convAlg;
		PowerNumeralList 	powList;
		UnitNumeralList	unList;

	};

}



#endif//CONVERT_ALG_HP
