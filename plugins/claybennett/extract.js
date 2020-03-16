function(page) {
var regex = /url\('([^']*)'/;
var match = regex.exec(page);
return match[1];
}
