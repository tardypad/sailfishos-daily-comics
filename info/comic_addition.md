
Addition of new comic
=====================

This document describes guidelines to follow for the addition of a new comic plugin.


Structure
---------

A subfolder with an unique identifier name needs to be created in the _plugins_ folder.  
That identifier must contain only alphanumerical and lowercase characters.

Example
```
plugins/
  commitstrip/
    cover.jpg
    example.jpg
    extract.js
    info.json
```


Information needed
------------------

- list of the authors (past/present, scenarist/cartoonist/...)
- homepage where to find more info about the comic
- comic main representative color (homepage color/strips color/character color/...)
- language used in the comic strips
- source where to find a link to the latest strip (RSS/API/URL/...)

This information needs to be in a JSON file named _info.json_

Example
```
{
  "name": "CommitStrip",                                // Display name
  "color": "2a3f6a",                                    // Color in hexadecimal format
  "language": "en",                                     // Language code
  "authors": [                                          //
    "Etienne Issartial",                                // List of authors
    "Thomas Gx"                                         //
  ],                                                    //
  "homepage": "http://www.commitstrip.com/",            // Homepage url
  "stripSource": "http://www.commitstrip.com/en/feed/"  // Source url for the current strip
}
```


Comic cover
-----------

The cover needs to be a file named _cover.jpg_

### Goal:
- The cover should be immediately recognizable while scanning the full list of comics

### Design:
- The cover is within a square
- Background is plain color from the comic own color
- Logo containing comic name should be displayed on top and centered
- The foregound contains the main character(s) centered

### Technical:
- format is JPEG
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

The cover needs to be a file named _example.jpg_

### Goal:
- The example strip should give users that don't know the comic an accurate idea of it.

### Choice:
- The example strip should be characteristic of the comic regarding format, drawing style and topic.

### Technical:
- format is JPEG
- remove the not necessary surrounding parts of the strip
- maximum width and height is 600 pixels
- minimize the size (remove metadata/use proper compression/...)

### Remarks:
- ensure the text is legible when displayed in the smallest size in the app


Extraction script
-----------------

The script needs to be a file named _extract.js_

That script is used to extract the current strip url from the source as defined in the information.  
The Javascript needs to consist of an unique function with a single parameter.  
That function will be called in the application with the content of the source.  
It needs to return a string containing an absolute or relative url to the current strip.

Example
```
function(page) {
    var regex = /<img[^>]*src="([^"]*\/wp-content\/uploads\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
```


Extras
------

- list the comic in the _info/comics_list.md_ file
- list, in the git commit message, the resource urls used for the cover and example
- keep higher resolution cover in the plugin folder with name _cover_big.jpg_
- regenerate the comics covers grid with the _resources/generate_covers_grid.sh_ script
- regenerate the comics list with the _resources/generate_list.sh_ script
- if needed, update, in the _Comic_ class and in the _resources/generate_list.sh_ script,
  the prefixes to ignore for the sorting of comics names
