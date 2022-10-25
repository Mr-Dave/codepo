# codepo
Programatic updating of PO files from online translation tools

This program assists in the process of updating "po" file with translations from a web translation service such as google translate.

It is a simple build (no autotools), just type 'make'

Usage: 

01.  Create a subdirectory called po_un 
02.  Copy in the *.po files into the po_un directory 
03.  Run this program with a parameter of 'i' 
04.  Find the tran_in_*.txt files created for each language in the directory. 
05.  If needed, change the text files to format accepted by online translation tool (e.g. docx)
     e.g. libreoffice --headless --convert-to docx tran_in_*.txt 
06.  Use the online translation tool and specify the files and associated language. 
07.  Copy the translated results into a new file with the following format tran_out_es.txt 
08.  Run this program with the parameter of 'o' 
09.  Review merged results in the 'new_??.po' files. e.g. new_es.po 
10.  If the results are good rename the 'new_??.po' files and move results back to the source code.

Note that bigger lists of translations normally need to be translated via file but smaller (shorter) lists 
of translations may be quicker to just paste into the web interface.

The program creates many files in the 'po_un'.  Do not change/delete these during the processing steps.  
After the translations are finished, these can be deleted.