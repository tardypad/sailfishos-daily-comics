function(page) {
var regex = /data-render-location="newsstand".*src="[^"]*"/;
var match = regex.exec(page);
var regex = /src="([^"]*)"/;
var match = regex.exec(match[0]);
var match = match[1].replace( /&amp;/g, "&" );
return match;
}
