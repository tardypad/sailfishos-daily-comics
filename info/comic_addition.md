
Addition of new comic
=====================

This document describes guidelines to follow for the addition of a new comic.


Information needed
------------------

- list of the authors (past/present, scenarist/cartoonist/...)
- homepage where to find more info about the comic
- comic main representative color (homepage color/strips color/character color/...)
- country of the authors
- language used in the comic
- where to find the latest strip (URL/RSS/API/...)


Comic cover
-----------

### Goal:
- The cover should be immediately recognizable while scanning the full list of comics

### Design:
- The cover is within a square
- Background is plain color from the comic own color
- Logo containing comic name should be displayed on top and centered
- The foregound contains the main character(s) centered

### Technical:
- format is JPEG with ".jpg" extension
- size is 300x300 pixels
- minimize the size (remove metadata/use proper compression/...)

### Remarks:
- ensure the text is legible when displayed in the smallest size in the app
- good contrast between logo/character and background color
- main character(s) is preferably shown in a characteristic attitude
- no shadows or effects on the main character(s)
- preferably no object is present with the characters (unless common for the comic or helping define the comic)
- the logo can be adapted to contain only the necessary parts (no tagline, background, author name, copyright/trademarks signs,...)
- the logo color can be changed if monochrome and is the same as the comic main color
- no full black or full white main color
- the main character(s) can expand in the bottom of the cover (but not on the side)
- if no main character, take a representative item or character
- if too many characters, limit to the most well known ones
- if the main color is the color of the main character, the main color can be darkened/lightened slightly to improve the contrast with the character
- the characters are preferably shown in full color (if they appear even only sometimes as such in the strips)

Comic example strip
-------------------

### Goal:
- The example strip should give users that don't know the comic an accurate idea of it.

### Choice:
- The example strip should be characteristic of the comic regarding format, drawing style and topic.

### Technical:
- format is JPEG with ".jpg" extension
- remove the not necessary surrounding parts of the strip
- maximum width and height is 600 pixels
- minimize the size (remove metadata/use proper compression/...)

### Remarks:
- ensure the text is legible when displayed in the smallest size in the app


Extras
------

- list the comic in the info/comics_list.md file
- list resources urls used for the cover/example in the git commit
- keep higher resolution cover in images/resources/comics covers
- regenerate the comics covers grid: montage $(ls images/comics/covers/*.jpg | shuf) -tile 10 -geometry 80x80 info/comics_covers.jpg
- update the prefixes to ignore for the sorting of comics name
