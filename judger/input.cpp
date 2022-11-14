#include <ios>
# include<iostream>
# include<filesystem>
# include<fstream>
# include<string>
# include<vector>
# include<random>
# include<ctime>
# include<cstdlib>

//./r_input/folder_name/test_case.txt


class input {
    private:
        




    public:
        int random_int(int a, int b) {
            int res = (rand () % (b-a+1)) + a;
            return res;
        }

        char random_char() {
            int res = (rand () % 52);
            if (res < 26) {
                char ascii_num = res + 65;
                return ascii_num;
            } else {
                char ascii_num = res + 71;
                return ascii_num;
            }
        }

        std::string random_string(int a, int b) {
            int res = (rand () % (b-a+1)) + a;
            std::string s_res = "";
            for (int i = 0; i < res; i++) {
                s_res.push_back(random_char());
            }
            return s_res;
        }


        void build_input_type() {
            int count_folder = 0;
            for (auto& f : std::filesystem::directory_iterator("./../input")) {
		        if (std::filesystem::is_directory(f)) {
                    count_folder ++;
                    std::string subpath = f.path();
                    int down_pos = subpath.rfind("/");
                    std::string folder_name = subpath.substr(down_pos + 1);
                    subpath += "/stdin_format.txt";
                    std::ifstream rfile;
                    rfile.open(subpath, std::ios::in);
                    std::string cur_token; 
                    while (!rfile.eof())
                    {
                        rfile >> cur_token;
                        if (cur_token.substr(0,3) == "int") {
                            std::string num_range = cur_token.substr(4);
                            num_range = num_range.substr(0, num_range.length()-1);
                            int pos = num_range.find(",");
                            std::string left_limit = num_range.substr(0,pos);
                            std::string right_limit = num_range.substr(pos+1);
                            int l_lim = std::stoi(left_limit);
                            int r_lim = std::stoi(right_limit);
                            for (int i = 1; i <= 3; i++) {
                                int res = random_int(l_lim, r_lim);
                                std::fstream rwrite;
                                rwrite.open("./r_input/"+ folder_name +"/" + std::to_string(i) + ".txt", std::ios::out | std::ios::app);
                                rwrite <<  std::to_string(res) << " ";
                            }
                        } else if (cur_token.substr(0,4) == "char") {
                            for (int i = 1; i <= 3; i++) {
                                char res = random_char();
                                std::fstream rwrite;
                                rwrite.open("./r_input/" + folder_name +"/" + std::to_string(i) + ".txt", std::ios::out | std::ios::app);
                                rwrite << res << " ";
                            }
                        } else if (cur_token.substr(0,6) == "string") {
                            std::string num_range = cur_token.substr(7);
                            num_range = num_range.substr(0, num_range.length()-1);
                            int pos = num_range.find(",");
                            std::string left_limit = num_range.substr(0,pos);
                            std::string right_limit = num_range.substr(pos+1);
                            int l_lim = std::stoi(left_limit);
                            int r_lim = std::stoi(right_limit);
                            for (int i = 1; i <= 3; i++) {
                                std::string res = random_string(l_lim, r_lim);
                                std::fstream rwrite;
                                rwrite.open("./r_input/" + folder_name +"/" + std::to_string(i) + ".txt", std::ios::out | std::ios::app);
                                rwrite << res << " ";
                            }
                        }
                        cur_token = "";
                    }
                    rfile.close();
                }
	        }
        }
};