#ifndef CONVERT_ALG_H
#define CONVERT_ALG_H

#include <gtest/gtest.h>
#include <memory>
#include  "struct.h"

namespace velalg {



	class ConvertAlg {
	public:
		virtual void phraseBaseInit() =0;
		virtual std::string getNumeral( const short unit) =0;


	protected:


		PowerNumeralList 	powList;
		UnitNumeralList		unList;

		short unitCounter;
		short powerCounter;
		short memCell;

		//struct MemCell {
			//short val;
			//bool isFree;
		//} cell;

	};
//--------------------------
//--------------------------------
//---------------------------------



	class RusAlg : public ConvertAlg {

	public:

		RusAlg();
		virtual void phraseBaseInit();

		virtual std::string getNumeral( short unit);

		virtual	~RusAlg(){};


	private:
		static const short maxGradeLevel = 3;
	
	};



//--------------------------
//--------------------------------
//---------------------------------
	class Convert {
	public:

		Convert(ConvertAlg& convAlg);

		void init();
		std::string getNumeral(const short unit) const;


	private:
		ConvertAlg* convAlg;

	};

}



#endif//CONVERT_ALG_HP
