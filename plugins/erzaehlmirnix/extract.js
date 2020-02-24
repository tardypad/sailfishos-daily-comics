function(page) {
var regex = /<img[^>]*id="[^"]*"[^>]*src="(https:[^":]*)[":]/;
var match = regex.exec(page);
return match[1];
}
