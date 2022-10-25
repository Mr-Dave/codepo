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


General process the program uses:

The program starts by reading through all the 'po' files in the directory.  For each po file it creates
a base file with a numeric row id.  It also creates an additional file that includes every phrases that does
not have a translation.  The additional file is provided to the online translation (manually by the user) and
the results are put into a third file.  This third file is then merged back in with the base file to create the
new po file that has both the original translations as well as the new ones.

All the translations that are in the original file are not revised.  Only the new/empty translations are written
to the file for the online translation tool.  This method prevents any previous translations from being broken
by the updates.  

Since some online translators revise characters that "should not" be translated, the codepo looks for some of these
special characters and changes them back to what we want.  For example the % symbol is changed by some online
translators to an asian version and possibly also prefixed/suffixed by a space.  The codepo program identifies these 
and changes them back to a plain % . 