https://www.linuxjournal.com/article/5594



define(`MACRO1', `esyscmd(`ls') MACRO VALUE, ARG1=$1, $ARG2=$2')
define(`MACRO2', `VALUE')

and then
MACRO1(`MYarg1', `MYarg2')

