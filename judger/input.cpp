# include<iostream>
#include <iterator>
# include<vector>
# include<fstream>

class output {
    private:
        std::vector<std::string> equiv;
        std::vector<std::string> in_equiv;

    public:

        void output_file() {
            std::string equiv_path;
            std::string in_equiv_path;
            equiv_path = "./../output/equal.csv";
            in_equiv_path = "./../output/inequal.csv";
            write_in_file(equiv_path, true);
            write_in_file(in_equiv_path, false);
        }

        void write_in_file(std::string path_to_file, bool is_equal) {
            std::ofstream target_file;
            target_file.open(path_to_file, std::ios::out|std::ios::app);
            if (is_equal) {
                for (int i = 0; i < equiv.size(); i ++) {
                    for (int j = i + 1; j < equiv.size(); j ++) {
                        target_file << equiv.at(i) << ", " << equiv.at(j) << std::endl;
                    }
                }
            } else {
                for (int i = 0; i < equiv.size(); i ++) {
                    for (int j = i + 1; j < in_equiv.size(); j ++) {
                        target_file << in_equiv.at(i) << ", " << in_equiv.at(j) << std::endl;
                    }
                }
            }
        }
};