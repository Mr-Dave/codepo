#!/bin/sh
  xgettext --keyword=_ -o po/motion.pot src/*.c
  msgmerge -UN --add-location=file --no-fuzzy-matching po/da.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/de.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/es.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/fi.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/fr.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/it.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/ja.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/ko.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/li.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/nl.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/no.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/pt.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/sk.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/sv.po po/motion.pot
  msgmerge -UN --add-location=file --no-fuzzy-matching po/zh.po po/motion.pot
  
  msgattrib --no-obsolete po/da.po -o po/da.po 
  msgattrib --no-obsolete po/de.po -o po/de.po
  msgattrib --no-obsolete po/es.po -o po/es.po
  msgattrib --no-obsolete po/fi.po -o po/fi.po
  msgattrib --no-obsolete po/fr.po -o po/fr.po
  msgattrib --no-obsolete po/it.po -o po/it.po
  msgattrib --no-obsolete po/ja.po -o po/ja.po
  msgattrib --no-obsolete po/ko.po -o po/ko.po
  msgattrib --no-obsolete po/li.po -o po/li.po
  msgattrib --no-obsolete po/nl.po -o po/nl.po
  msgattrib --no-obsolete po/no.po -o po/no.po
  msgattrib --no-obsolete po/pt.po -o po/pt.po
  msgattrib --no-obsolete po/sk.po -o po/sk.po
  msgattrib --no-obsolete po/sv.po -o po/sv.po
  msgattrib --no-obsolete po/zh.po -o po/zh.po
 
  mkdir po_un
  msgattrib --untranslated po/da.po  -o po_un/da.po 
  msgattrib --untranslated po/de.po  -o po_un/de.po
  msgattrib --untranslated po/es.po  -o po_un/es.po
  msgattrib --untranslated po/fi.po  -o po_un/fi.po
  msgattrib --untranslated po/fr.po  -o po_un/fr.po
  msgattrib --untranslated po/it.po  -o po_un/it.po
  msgattrib --untranslated po/ja.po  -o po_un/ja.po
  msgattrib --untranslated po/ko.po  -o po_un/ko.po
  msgattrib --untranslated po/li.po  -o po_un/li.po
  msgattrib --untranslated po/nl.po  -o po_un/nl.po
  msgattrib --untranslated po/no.po  -o po_un/no.po
  msgattrib --untranslated po/pt.po  -o po_un/pt.po
  msgattrib --untranslated po/sk.po  -o po_un/sk.po
  msgattrib --untranslated po/sv.po  -o po_un/sv.po
  msgattrib --untranslated po/zh.po  -o po_un/zh.po
  
  msgattrib --translated po/da.po -o po/da.po 
  msgattrib --translated po/de.po -o po/de.po
  msgattrib --translated po/es.po -o po/es.po
  msgattrib --translated po/fi.po -o po/fi.po
  msgattrib --translated po/fr.po -o po/fr.po
  msgattrib --translated po/it.po -o po/it.po
  msgattrib --translated po/ja.po -o po/ja.po
  msgattrib --translated po/ko.po -o po/ko.po
  msgattrib --translated po/li.po -o po/li.po
  msgattrib --translated po/nl.po -o po/nl.po
  msgattrib --translated po/no.po -o po/no.po
  msgattrib --translated po/pt.po -o po/pt.po
  msgattrib --translated po/sk.po -o po/sk.po
  msgattrib --translated po/sv.po -o po/sv.po
  msgattrib --translated po/zh.po -o po/zh.po

  rm po/*.po~

  echo  
  echo Now tranlate the "po_un" directory files and merge back into the regular po files.
  echo
 


