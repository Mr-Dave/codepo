#!/bin/sh
 
  msgcat  --use-first po/da.po po_un/new_da.po -o po/da.po
  msgcat  --use-first po/de.po po_un/new_de.po -o po/de.po
  msgcat  --use-first po/es.po po_un/new_es.po -o po/es.po
  msgcat  --use-first po/fi.po po_un/new_fi.po -o po/fi.po
  msgcat  --use-first po/fr.po po_un/new_fr.po -o po/fr.po
  msgcat  --use-first po/it.po po_un/new_it.po -o po/it.po
  msgcat  --use-first po/ja.po po_un/new_ja.po -o po/ja.po
  msgcat  --use-first po/ko.po po_un/new_ko.po -o po/ko.po
  msgcat  --use-first po/li.po po_un/new_li.po -o po/li.po
  msgcat  --use-first po/nl.po po_un/new_nl.po -o po/nl.po
  msgcat  --use-first po/no.po po_un/new_no.po -o po/no.po
  msgcat  --use-first po/pt.po po_un/new_pt.po -o po/pt.po
  msgcat  --use-first po/sk.po po_un/new_sk.po -o po/sk.po
  msgcat  --use-first po/sv.po po_un/new_sv.po -o po/sv.po
  msgcat  --use-first po/zh.po po_un/new_zh.po -o po/zh.po

  rm po/*.po~

  echo  
  echo All done, now check the files with poedit.
  echo
 


