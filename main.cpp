/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*#include <string>*/
/*#include <iostream>*/



/*#define DG_POWER 6              // Энто допустимая степень числа 1000 для long:*/
//								При необходимости его легко увеличить,
/*struct s_POWER {                // дополнив массив 'a_power' и заменив*/
  /*int sex;                      // тип long на более серьезный*/
  /*std::string one;*/
  /*std::string four;*/
  /*std::string many;*/
/*} a_power[]= {*/
  /*{0,NULL          ,NULL           ,NULL            },  // 1*/
  /*{1,"тысяча "     ,"тысячи "      ,"тысяч "        },  // 2*/
  /*{0,"миллион "    ,"миллиона "    ,"миллионов "    },  // 3*/
  /*{0,"миллиард "   ,"миллиарда "   ,"миллиардов "   },  // 4*/
  /*{0,"триллион "   ,"триллиона "   ,"триллионов "   },  // 5*/
  /*{0,"квадриллион ","квадриллиона ","квадриллионов "},  // 6*/
  /*{0,"квинтиллион ","квинтиллиона ","квинтиллионов "}   // 7*/
/*};*/

/*struct s_UNIT {*/
  /*std::string one[2];*/
  /*std::string two;*/
  /*std::string dec;*/
  /*std::string hun;*/
/*} digit[10]= {*/
  /*{{""       ,""       },"десять "      ,""            ,""          },*/
  /*{{"один "  ,"одна "  },"одиннадцать " ,"десять "     ,"сто "      },*/
  /*{{"два "   ,"две "   },"двенадцать "  ,"двадцать "   ,"двести "   },*/
  /*{{"три "   ,"три "   },"тринадцать "  ,"тридцать "   ,"триста "   },*/
  /*{{"четыре ","четыре "},"четырнадцать ","сорок "      ,"четыреста "},*/
  /*{{"пять "  ,"пять "  },"пятнадцать "  ,"пятьдесят "  ,"пятьсот "  },*/
  /*{{"шесть " ,"шесть " },"шестнадцать " ,"шестьдесят " ,"шестьсот " },*/
  /*{{"семь "  ,"семь "  },"семнадцать "  ,"семьдесят "  ,"семьсот "  },*/
  /*{{"восемь ","восемь "},"восемнадцать ","восемьдесят ","восемьсот "},*/
  /*{{"девять ","девять "},"девятнадцать ","девяносто "  ,"девятьсот "}*/
/*};*/

/*std::string dig2str (long p_summa, int p_sex, const char *p_one, const char *p_four, const char *p_many)*/
/*{*/
  /*int    i,mny;*/
  /*std::string str,result="";*/
  /*long divisor=0; //делитель*/

  /*a_power[0].sex = p_sex;*/
  /*a_power[0].one(p_one);*/
  /*a_power[0].four(p_four);*/
  /*a_power[0].many(p_many);*/

  /*if(p_summa == (long)0) return std::string("ноль ")+p_many;*/
  /*if(p_summa <  (long)0) {result="минус "; p_summa = -p_summa;}*/

  /*for(i=0,divisor=(long)1; i<DG_POWER; i++)*/
    /*divisor *= (long)1000;*/
  /*for(i=DG_POWER-1; i>=0; i--){*/
    /*divisor /= 1000;*/
	/*std::cout<<"divisor: "<<(long)(divisor)<<std::endl;*/
    /*mny = (int)(p_summa / divisor);*/
	/*std::cout<<"mny: "<<mny<<std::endl;*/
    /*p_summa %= divisor;*/
    /*str="";*/
    /*if(mny==0){*/
      /*if(i>0) continue;*/
      /*str += a_power[i].one;*/
    /*}else{*/
      /*if(mny>=100){str += digit[mny/100].hun; mny%=100;}*/
      /*if(mny>=20 ){str += digit[mny/10 ].dec; mny%=10; }*/
      /*if(mny>=10 ) str += digit[mny-10 ].two; else*/
      /*if(mny>=1  ) str += digit[mny].one[a_power[i].sex];*/
      /*switch(mny){*/
        /*case 1: str += a_power[i].one; break;*/
        /*case 2: case 3:*/
        /*case 4: str += a_power[i].four; break;*/
       /*default: str += a_power[i].many; break;*/
      /*};*/
    /*}*/
    /*result += str;*/
  /*}*/
  /*return result;*/
/*}*/

/*int main(int argc, const char *argv[]) {*/

  /*exit (0);*/
	/*std::string st1;*/
	/*st1=dig2str(10,0,"asd","asdf","sdf");*/


	/*std::cout<<st1<<std::endl;*/


	/*return 0;*/
/*}*/


//#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>


namespace vel_data {

	enum languages {russian, english};
	enum genders { masc, fem };
	enum power_grades { once=0, thous, mill, bill, trill, quad, quint };

	typedef std::vector< std::vector <std::string> > d2_string;
	typedef std::map <genders, d2_string>  units;

	struct power{
		genders grade_gender;
		d2_string names;
	};


	class simple_alg {
	public:
		simple_alg(){};
		simple_alg(const languages lang, power& pwr, units& unt ) {
		
		};

		short get_one() const { return 1; }
		power& get_powers() const {};
		units& get_units() const {};

	private:
		power pwr;
		units unt;
	
	};


	template <typename T>
	class alg_unpack {

	public:
		alg_unpack(T& init_alg) {
		
			std::cout<<init_alg.get_one()<<std::endl;
		};

		std::string get_unit(){return "ноль";};
		std::string get_power(){return "ноль";};
		void set_num(power_grades pwr_names, short unit){};

	private:
		T init_alg;
		power pwr;
		units unt;

	};

}


//template <typename T_type, typename T_unpalg, typename T_matalg>
//class num_to_str {
//public:
	//num_to_str() {
	//};
//private:
	//alg_unpack<T_unpalg> lang_suite;
	//grad<T_matalg> mat_suite;
	//T_type number;
//};


int main(int argc, char **argv) {
	
	using namespace vel_data;
	power pwr;
	units unt;
	simple_alg sa(russian, pwr, unt);

	alg_unpack<simple_alg> au(sa);
	//au.set_num();
	//au.get_unit();
	//au.get_power();


	/*::testing::InitGoogleTest(&argc, argv);*/
	/*return RUN_ALL_TESTS();*/
}


