# include<iostream>
# include<vector>
# include<filesystem>
# include<fstream>
# include<string>

//output_path:./r_output/folder_num/file.txt

class judge_diff {
    private:
        std::vector<std::string> equiv;
        std::vector<std::string> in_equiv;
    public:
        bool judger(std::string file_1, std::string file_2, int folder_num) {
            std::ifstream file_fir;
            std::ifstream file_sec;
            file_fir.open("./r_output/" + std::to_string(folder_num) + "/" + file_1 + ".txt", std::ios::in);
            file_sec.open("./r_output/" + std::to_string(folder_num) + "/" + file_2 + ".txt", std::ios::in);
            for (int i = 0; i < 3; i ++) {
                
            }
        }
};