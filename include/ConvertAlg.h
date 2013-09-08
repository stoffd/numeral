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
		virtual std::string finalize( bool isLessZero ) =0;


	protected:


		//PowerNumeralList 	powList;
		D2String			powList;
		UnitNumeralList		unList;

		short unitCounter;
		short powerCounter;

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
		virtual std::string finalize( bool isLessZero );

		virtual	~RusAlg(){};


	private:
		bool powerWasWrite;
		short memCell1;
		short memCell2;
		std::string definePower( const short value, const short power ); 
		static const short maxGradeLevel = 3;
		static const short MORE_AS_FOUR = 5;
	
	};





//--------------------------
//--------------------------------
//---------------------------------



	class EngAlg : public ConvertAlg {

	public:

		EngAlg();
		virtual void phraseBaseInit();
		virtual std::string getNumeral( short unit);
		virtual std::string finalize( bool isLessZero );

		virtual	~EngAlg(){};


	private:

		bool powerWasWrite;
		bool potentialAnd;
		short memCell1;
		short memCell2;
		std::string definePower( const short power ); 
		static const short maxGradeLevel = 3;
	
	};



}




#endif//CONVERT_ALG_HP
