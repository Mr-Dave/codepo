

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>


void parse_base(std::string langcd ){
    std::string line_in, line_out;
    std::ifstream srcfile;
    std::ofstream basefile;
    char refnbr[15];
    int indx;

    srcfile.open("po_un/"+langcd+".po",std::ifstream::in);
    if (!srcfile.is_open()) {
        std::cout << "Unable to open po_un/"+langcd+".po\n";
        return;
    }

    basefile.open("po_un/base_"+langcd+".txt",std::ofstream::out);
    if (!basefile.is_open()) {
        std::cout << "Unable to open po_un/base_"+langcd+".txt\n";
        return;
    }

    indx = 0;
    while ( getline (srcfile, line_in) ) {
        snprintf(refnbr,15," %08d| ",indx);
        line_out = refnbr + line_in + '\n';
        basefile << line_out;
        indx++;
    }
    srcfile.close();
    basefile.close();

}

void parse_in(std::string langcd){
    std::string line_in, line_out, line_out2,line_temp;
    std::ifstream basefile;
    std::ofstream txtfile;
    std::ofstream tranfile;
    bool wrt_ln, current_tran;
    std::vector<std::string> vline;
    int indx,pos;

    basefile.open("po_un/base_"+langcd+".txt");
    if (!basefile.is_open()) {
        std::cout << "Unable to open po_un/base_"+langcd+".txt\n";
        return;
    }

    txtfile.open("po_un/tran_in_"+langcd+".txt");
    if (!txtfile.is_open()) {
        std::cout << "Unable to open po_un/tran_in_"+langcd+".txt\n";
        return;
    }

    /* we just create a empty file for later population by a translator*/
    tranfile.open("po_un/tran_out_"+langcd+".txt");
    if (!tranfile.is_open()) {
        std::cout << "Unable to open po_un/tran_out_"+langcd+".txt\n";
        return;
    }
    tranfile.close();


    wrt_ln = false;
    vline.clear();
    current_tran = false;
    while ( getline (basefile, line_in) ) {
        if (line_in.length() >= 11){
            if (line_in.substr(11,5) =="msgid") {
                if (( current_tran == false ) && (vline.size() > 0)){
                    for (indx =0; indx != (int)vline.size(); indx++) {
                        txtfile << vline[indx] + '\n';
                    }
                }
                wrt_ln = true;
                current_tran = false;
                vline.clear();
            }

            if (line_in.substr(11,6) =="msgstr") wrt_ln = false;

            if ( wrt_ln ){
                if (line_in.substr(11,5) =="msgid"){
                    line_in = line_in.substr(0,11) + line_in.substr(18,line_in.length()-19);
                } else {
                    line_in = line_in.substr(0,11) + line_in.substr(12,line_in.length()-13);
                }

                /* Replace the _ with spaces for better translations*/
                line_temp = "";
                pos = 0;
                while (pos < (int)line_in.length()){
                    if (line_in.substr(pos,1) == "_"){
                    line_temp = line_temp + " ";
                    } else {
                        line_temp = line_temp + line_in.substr(pos,1);
                    }
                    pos++;
                }

                vline.push_back(line_temp);

            } else {
                if (line_in.length() > 20){
                    if ((line_in.substr(18,1) == "\"") && (line_in.substr(19,1) != "\"")) current_tran = true;
                }
                if (line_in.substr(11,1) == "\"") current_tran = true;
            }

        }
    }

    if (( current_tran == false ) && (vline.size() > 0)){
        for (indx =0; indx != (int)vline.size(); indx++) {
            txtfile << vline[indx] + '\n';
        }
    }

    basefile.close();
    txtfile.close();

}

void parse_out(std::string langcd){
    std::string line_base, line_tran, line_adj, line_prev, line_temp;
    std::ifstream basefile;
    std::ifstream tranfile;
    std::ofstream newfile;
    int indx_base, indx_tran, indx_id;
    int pos_tran,pos_base, pos;
    std::string a_qte1, a_qte2, a_pct;

    basefile.open("po_un/base_"+langcd+".txt");
    if (!basefile.is_open()) {
        std::cout << "Unable to open po/base_"+langcd+".txt\n";
        return;
    }

    tranfile.open("po_un/tran_out_"+langcd+".txt");
    if (!basefile.is_open()) {
        std::cout << "Unable to open po/tran_out_"+langcd+".txt\n";
        return;
    }

    newfile.open("po_un/new_"+langcd+".po");
    if (!basefile.is_open()) {
        std::cout << "Unable to open po_un/new_"+langcd+".po\n";
        return;
    }


    a_qte1="“";
    a_qte2="”";
    a_pct="％";

    indx_tran = -1;
    indx_base = -1;
    while ( getline (tranfile, line_tran) ) {
        pos_tran = line_tran.find('|');
        if (pos_tran == (int)std::string::npos){
            /* Some translators remove our | */
            if (line_tran.length() > 7 ){
                pos_tran = line_tran.find(' ', 1);
                if (pos_tran == (int)std::string::npos){
                    pos_tran = (int)line_tran.length();
                    line_tran = line_tran+"|";
                } else {
                    line_tran = line_tran.substr(0,pos_tran)+"| "+line_tran.substr(pos_tran);
                    pos_tran++;
                }
            }
        }

        if (pos_tran != (int)std::string::npos){
            indx_tran = atoi(line_tran.substr(0 , pos_tran).c_str());
            line_temp = line_tran.substr(pos_tran+1);
            if (indx_tran >= indx_base){
                while (getline(basefile, line_base)){;
                    pos_base = line_base.find('|');
                    indx_base = atoi(line_base.substr(0,pos_base).c_str());
                    if ((indx_base > indx_tran) && (line_base.substr(pos_base+2,6) == "msgstr"))  break;
                    if (line_base.substr(pos_base+2,5) == "msgid") indx_id = indx_base;
                    newfile << line_base.substr(pos_base+2) + '\n';
                    line_prev = line_base.substr(pos_base+2);
                }
            }

            line_tran = line_tran.substr(pos_tran+1);
            while (line_tran.substr(0,1) == " "){
                line_tran = line_tran.substr(1);
                if (line_tran == "") break;
            }

            line_temp = "";
            pos = 0;
            while (pos < (int)line_tran.length()){
                /* ％ is an asian tranlation of % */
                if ((line_tran.substr(pos,2) == "% ")) {
                    if (pos > 0) {
                        if (line_tran.substr(pos-1,1) != " "){
                            line_temp = line_temp + " %";
                        } else {
                            line_temp = line_temp + "%";
                        }
                    } else {
                        line_temp = line_temp + "%";
                    }
                    pos += 2;
                } else if (line_tran.substr(pos,3) ==a_pct){    /* Asian variant */
                    line_temp = line_temp + " %";
                    pos +=3;
                } else if ((line_tran.substr(pos,3) == a_qte1) ||
                           (line_tran.substr(pos,3) == a_qte2)) {    /* Asian variant */
                    line_temp = line_temp + "\"";
                    pos +=3;
                } else if (line_tran.substr(pos,2) == "\\ "){
                    line_temp = line_temp + "\\";
                    pos += 2;
                } else {
                    line_temp = line_temp + line_tran.substr(pos,1);
                    pos++;
                }
            }
            if (indx_tran == indx_id){
                newfile << "msgstr \""+line_temp +"\"\n";
            } else {
                newfile << "\""+line_temp +"\"\n";
            }
        }
    }
    while (getline(basefile, line_base)){;
        pos_base = line_base.find('|');
        newfile << line_base.substr(pos_base+2) + '\n';
    }
    basefile.close();
    tranfile.close();
    newfile.close();

}


int main(int argc, char* argv[]) {

    std::string parg, langcd;
    struct dirent * dp;

    if (argc < 2){
         std::cout << "Usage: " << std::endl;
         std::cout << "01.  Create a subdirectory called po_un" << std::endl;
         std::cout << "02.  Copy in the *.po files into the po_un directory" << std::endl;
         std::cout << "03.  Run this program with a parameter of 'i'" << std::endl;
         std::cout << "04.  Find the tran_in_*.txt files created for each language in the directory." << std::endl;
         std::cout << "05.  If needed, change the text files to format accepted by online translation tool (e.g. docx)" << std::endl;
         std::cout << "     e.g. libreoffice --headless --convert-to docx tran_in_*.txt " << std::endl;
         std::cout << "06.  Use the online translation tool and specify the files and associated language." << std::endl;
         std::cout << "07.  Copy the translated results into a new file with the following format tran_out_es.txt" << std::endl;
         std::cout << "08.  Run this program with the parameter of 'o'" << std::endl;
         std::cout << "09.  Review merged results in the 'new_??.po' files. e.g. new_es.po" << std::endl;
         std::cout << "10.  If the results are good rename the 'new_??.po' files and move results back to the source code." << std::endl;
         return 0;
    }

    DIR* dirp = opendir("po_un");
    if (dirp == NULL) {
        std::cout << "No po_un directory.  Ending." << std::endl;
        return 0;
    }

    parg = argv[1];
    if ((parg != "i") && (parg != "o")) {
        std::cout << "Invalid parm.  Valid options are 'i' or 'o'. Ending." << std::endl;
        return 0;
    }

    while ((dp = readdir(dirp)) != NULL) {
        langcd = dp->d_name;
        if (langcd.length() == 5){
            if (langcd.substr(3,2) == "po"){
                langcd = langcd.substr(0,2);
                if ( parg == "i") {
                    parse_base(langcd);
                    parse_in(langcd);
                    std::cout << "Send the tran_in_"+langcd+".txt file through translator and create a tran_out_"+langcd+".txt file with the results" << std::endl;
                } else if ( parg == "o") {
                    parse_out(langcd);
                    std::cout << "tran_out_"+langcd+".txt merged into the file new_"+langcd+".po " << std::endl;
                }
            }
        }
    }

    closedir(dirp);

  return 0;
}
