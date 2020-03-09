function(page) {
var regex = /<img[^>]*id="[^"]*"[^>]*src="([^"]*)"/;
var match = regex.exec(page);
return match[1];
}
