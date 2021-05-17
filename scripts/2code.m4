#!/bin/bash


define(`START_HTML',
`<html>
<head>
  <meta http-equiv="Content-Type" content="text/html;
   charset=iso-8859-1">
  <meta name="Author" content="D. Robert Adams">
  <title>$1</title>
</head>
<body text="#000000"
  ifdef(`BACKGROUND_IMAGE',
        `background="BACKGROUND_IMAGE"')
  bgcolor="#e5e5e5" link="#3333ff"
vlink="#000099"
  alink="#ffffff">
')

define(`PAGE_HEADER',
`<table border="0" background="steel.jpg"
width="100%">
  <tr>
    <td align="left">$1</td>
    <td align="right">$2</td>
  </tr>
</table>
<div align=right>
  Last Modified: esyscmd(`date')
</div>
')

define(`HTML_BANNER',
`<table border="0"
background="steel.jpg"
width="100%">
  <tr>
    <td>
      <img src="$1">
      <h2>$2</h2>
    </td>
  </tr>
</table>
')

define(`END_HTML', `</body></html>')

define(`BACKGROUND_IMAGE', `bg.jpg')
START_HTML(`Sample Page')
PAGE_HEADER(`computer.jpeg', `Sample HTML
Page')
HTML_BANNER(`img1.jpg', `News')
HTML_BANNER(`img2.jpg', `Downloads')
END_HTML
