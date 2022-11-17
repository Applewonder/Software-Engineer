# include<iostream>
# include <iterator>
# include<vector>
# include <set>
# include<fstream>

//./../output/


class output {
    private:
        std::set<std::pair<std::string, std::string>> equiv;
        std::set<std::pair<std::string, std::string>> in_equiv;

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
                target_file << "file1" << "," << "file2" << std::endl;
                for (auto it = equiv.begin(); it != equiv.end(); it ++) {
                    std::string file_1 = it->first;
                    std::string file_2 = it->second;
                    target_file << file_1.substr(5) + ".cpp" << "," << file_2.substr(5) + ".cpp" << std::endl;
                }
            } else {
                target_file << "file1" << "," << "file2" << std::endl;
                for (auto it = in_equiv.begin(); it != in_equiv.end(); it ++) {
                    std::string file_1 = it->first;
                    std::string file_2 = it->second;
                    target_file << file_1.substr(5) + ".cpp" << "," << file_2.substr(5) + ".cpp" << std::endl;
                }
            }
        }

        void insert_equiv(std::string path_to_file_1, std::string path_to_file_2) {
            equiv.insert(std::make_pair(path_to_file_1, path_to_file_2));
        }

        void insert_in_equiv(std::string path_to_file_1, std::string path_to_file_2) {
            in_equiv.insert(std::make_pair(path_to_file_1, path_to_file_2));
        }

};