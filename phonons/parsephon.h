#pragma once

#include "pointers.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <functional>
#include <sstream>

namespace PHON_NS {
    class Input: protected Pointers {
    public:
        Input(class PHON *);
        ~Input();
        void parce_input(int, char **);
		template<typename T_to, typename T_from> T_to my_cast(T_from const &);

        std::string job_title;

    private:
		std::ifstream ifs_input;
		bool from_stdin;

        void read_input_phonons();
        void read_input_boltzmann();
        void read_input_gruneisen();

		int locate_tag(std::string);
		void parse_general_vars();
		void parse_cell_parameter();
		void parse_kpoints();
		void get_var_dict(std::string, std::map<std::string, std::string> &);
		void split_str_by_space(const std::string, std::vector<std::string>&);

		bool is_endof_entry(std::string);
		template<typename T> void assign_val(T&, std::string, std::map<std::string, std::string>);

		std::vector<std::string> my_split(const std::string &str, char delim)
		{
			std::istringstream iss(str);
			std::string str_tmp;
			std::vector<std::string> ret;

			while (std::getline(iss, str_tmp, delim)) {
				ret.push_back(str_tmp);
			}
			return ret;
		}
    };

	// trim from start
	static inline std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static inline std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static inline std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}




}

