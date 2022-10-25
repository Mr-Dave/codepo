# codepo
Programatic updating of PO files from online translation tools

This program assists in the process of updating "po" file with translations from a web translation service such as google translate.

It is a simple build (no autotools), just type 'make'

Usage: 

01.  Run the setup_po_files script in the motion directory.
     a.  Creates an updated motion.pot file
     b.  Updates the po files with the new items.
     c.  Removes the unused translations.
     d.  Creates a po_un directory and puts in the untranslated phrases.
     e.  Revises the existing po files so they only have the translated phrases.
02.  Run this program with a parameter of 'i' 
03.  Find the tran_in_*.txt files created for each language in the directory. 
04.  If needed, change the text files to format accepted by online translation tool (e.g. docx)
     e.g. libreoffice --headless --convert-to docx tran_in_*.txt 
05.  Use the online translation tool and specify the files and associated language. 
06.  Copy the translated results into the empty files named tran_out_??.txt where ?? is the language code. 
07.  Run this program with the parameter of 'o' 
08.  Review merged results in the 'new_??.po' files.  
09.  If the results are good, run the script merge_new_po.sh to merge the old and new translations.


Note that bigger lists of translations will normally need to be translated via a file but smaller (shorter) 
lists of translations may be processed quicker by just pasting the text into the web interface.  If the phrases
are pasted as text into the translation tool, be sure to include the prefix numbers on each line.  These are
critical to the merge process later.  

The program creates many files in the 'po_un' directory.  Do not change/delete these during the processing steps.  
After the translations are finished, the whole directory can be deleted.


General process the program uses:

The program starts by reading through all the 'po' files in the directory.  For each po file found, the program
creates a base file with a numeric row id.  It also creates an additional file that includes every phrase that does
not have a translation.  The additional file is provided to the online translation (manually by the user) and
the results are put into a third file.  This third file is then merged back in with the base file based upon the 
row ids to create the new po file.

Since some online translators revise characters that "should not" be translated, the program looks for some of these
special characters and changes them back to what we want.  For example the % symbol is changed by some online
translators to an asian version and possibly also prefixed/suffixed by a space.  The program identifies these 
and changes them back to a plain % . 

(To run this for projects other than motion, edit the script files to specify different source code directories,pot files and language files)