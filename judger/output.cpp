# include<iostream>
# include <iterator>
# include<vector>
# include <set>
# include<fstream>

class output {
    private:
        std::set<std::string> equiv;
        std::set<std::string> in_equiv;

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
                for (auto it = equiv.begin(); it != equiv.end(); it ++) {
                    for (auto it_sec = it; it_sec != equiv.end(); it_sec ++) {
                        if (it_sec == it) it_sec ++;
                        target_file << *it << ", " << *it_sec << std::endl;
                    }
                }
            } else {
                for (auto it = in_equiv.begin(); it != in_equiv.end(); it ++) {
                    for (auto it_sec = it; it_sec != in_equiv.end(); it_sec ++) {
                        if (it_sec == it) it_sec ++;
                        target_file << *it << ", " << *it_sec << std::endl;
                    }
                }
            }
        }

        void insert_equiv(std::string path_to_file) {
            equiv.insert(path_to_file);
        }

        void insert_in_equiv(std::string path_to_file) {
            in_equiv.insert(path_to_file);
        }

};