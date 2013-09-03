#ifndef STRUCT_HPP
#define STRUCT_HPP



namespace velalg {

	enum languages {russian, english};
	enum genders { masc, fem };
	enum power_grades { once=0, thous, mill, bill, trill, quad, quint };

	typedef std::vector< std::vector <std::string> > d2_string;
	typedef std::map <genders, d2_string>  units;

	struct power{
		genders grade_gender;
		d2_string names;
	};

}

#endif//STRUCT_HPP
